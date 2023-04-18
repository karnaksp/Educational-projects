
# Сети Кохонена Чтение и обработка данных.Загрузим библиотеки для обработки данных и загрузим датасет.

library(kohonen)
library(readr)
library(dplyr)
library(tidyverse)
library(RColorBrewer)
library(magrittr)
library(NbClust)

winequality_white <- read_delim("C:/Users/user/Downloads/verte/winequality-white.csv", 
    delim = ";", escape_double = FALSE, col_types = cols(quality = col_character()), 
    trim_ws = TRUE)
head(winequality_white)


# Посмотрим на коэффициент вариации переменных для того, чтобы использовать только те переменные, у которых хорошая вариабильность.


apply(winequality_white[,1:11], 2, function(x) sd(x)/mean(x))

# Получилось, что мы можем удалить переменную dencity.


qual_col_pals = brewer.pal.info[brewer.pal.info$category == 'qual',]
col_vector = unlist(mapply(brewer.pal, qual_col_pals$maxcolors, rownames(qual_col_pals)))


# Далее установим количество итераций и размер сетки


n <- 60
map_dimension_x = 20
map_dimension_y = 23
n_iterations = 5000
recalculate_map = T
recalculate_no_clusters = T

# ```

# Разделим данные на факторные и непрерывные, поскольку в датасете есть переменная качества. И продемонстрируем новые данные.

# ```{r}
numerics = summarise_all(winequality_white, is.numeric ) %>%
  as.logical()
factors = names(winequality_white)%>%
  .[!numerics]
numerics = names(winequality_white)%>%
  .[numerics]

data_list = list()
distances = vector()

for (fac in factors){
  data_list[[fac]] = kohonen::classvec2classmat(winequality_white[[fac]] )
  distances = c(distances, 'tanimoto')
}

data_list[['numerics']] = scale(winequality_white[,numerics])
distances = c( distances, 'euclidean')

str(data_list)
# ```

# От полученных переменных будет зависеть мера расстояния, которую мы будем использовать. Эвклидово - для непрерывных переменных и Танимото - для категорий.

# Теперь создадим модель

# ```{r}
set.seed(100)

som_grid = kohonen::somgrid(xdim = map_dimension_x
                            , ydim=map_dimension_y
                            , topo="hexagonal")

if(recalculate_map == F & file.exists('som.Rdata') == T){
  load('som.Rdata')
} else{
  m = kohonen::supersom( data_list
                   , grid=som_grid
                   , rlen= n_iterations
                   , alpha = 0.05
                   , whatmap = c(factors, 'numerics')
                   , dist.fcts = distances
                    )
  save(m, file = 'som.Rdata')
}

plot(m, type="changes", main="Прогресс обучения")
#Прогресс обучения выходит на плато на 5000 итераций
# ```

# Мы записали данные модели в файл.

# Посмотрим на веса векторов:

# ```{r}
plot(m, type="counts", main="Веса векторов")
# ```

# и на распределение относительно переменных

# ```{r}
plot(m, type="codes")
# ```

# ------------------------------------------------------------------------

# Соединим все слои в 1 датафрейм, сгенерируем матрицу расстояний для codes и для каждого участка на карте.

# ```{r}
codes = tibble( layers = names(m$codes)
                ,codes = m$codes ) %>%
  mutate( codes = purrr::map(codes, as_tibble) ) %>%
  spread( key = layers, value = codes) %>%
  apply(1, bind_cols) %>%
  .[[1]] %>%
  as_tibble()
dist_m = dist(codes) %>%
  as.matrix()
dist_on_map = kohonen::unit.distances(som_grid)
dist_adj = dist_m ^ dist_on_map
# ```

# Посмотрим на некоторые методы определения оптимального количества кластеров:**

# ```{r}
#ellbow method
factoextra::fviz_nbclust(dist_adj
                         , factoextra::hcut
                         , method = "wss"
                         , hc_method = 'ward.D2'
                         , k.max = 7) 

#silhouette method
factoextra::fviz_nbclust(dist_adj
                         , factoextra::hcut
                         , method = "silhouette"
                         , hc_method = "ward.D2"
                         , k.max =  7)


# Однако не все индексы работают со всеми матрицами расстояний, поэтому мы пройдемся по всем доступным индексам и посмотрим, сколько они определят кластеров.

indexes = c( "kl", "ch", "hartigan", "ccc", "scott", "marriot", "trcovw", "tracew", "friedman", "rubin", "cindex", "db", "duda", "pseudot2", "beale", "ratkowsky", "ball", "ptbiserial", "frey", "mcclain", "gamma", "gplus", "tau", "dunn", "sdindex",  "sdbw")

if(recalculate_no_clusters == F & file.exists('nbclust.Rdata') == T ){
  load('nbclust.Rdata')
}else{
  results_nb = list()
  safe_nb = purrr::safely(NbClust::NbClust)
  times = list()
  for(i in 1:length(indexes) ){
    t = lubridate::now()
    nb = safe_nb(as.dist(dist_adj)
                        , distance = "euclidean"
                        , min.nc = 2              
                        , max.nc = 15             
                        , method = "ward.D2"
                        , index = indexes[i]
                        )
    results_nb[[i]] = nb
    times[[i]]      = lubridate::now()-t
  }
  
  df_clust = tibble( indexes = indexes
                     , times = times
                     , nb = results_nb) %>%
    mutate( results = purrr::map(nb,'result') 
            , error = purrr::map(nb, 'error')
            , is_ok = purrr::map_lgl(error, is_null))
  df_clust_success = df_clust %>%
    filter( is_ok ) %>%
    mutate( names      = purrr::map(results, names)
            ,all_index = purrr::map(results, 'All.index')
            ,best_nc   = purrr::map(results, 'Best.nc')
            ,best_nc   = purrr::map(best_nc, function(x) x[[1]])
            ,is_ok     = !purrr::map_lgl(best_nc, is_null)
            ) %>%
    filter(is_ok) %>%
    mutate( best_nc    = purrr::flatten_dbl(best_nc))
  save(df_clust_success, file = 'nbclust.Rdata')
}
# ```

# А теперь посмотрим, сколько методов, сколько раз предпочли то или иное количество кластеров.

# ```{r}
df_clust_success %>%
  filter(!is_null(best_nc) )%>%
ggplot( aes(x = as.factor(best_nc))) +
  geom_bar()+
  labs(title = 'Количество методов за лучшее разбиение'
       ,x     = 'Лучшее количество кластеров')


# Выходит, что оптимальное количество кластеров - это 3. Построим карту, учитывая это количество.

dist_adj =  dist_m ^ dist_on_map
clust_adj = hclust(as.dist(dist_adj), 'ward.D2')
som_cluster_adj = cutree(clust_adj, 3)
plot(m, type="codes", main = "Clusters", bgcol = col_vector[som_cluster_adj], pchs = NA)
add.cluster.boundaries(m, som_cluster_adj)

# А теперь посмотрим на отношение полученных кластеров с качеством вина (quality).
link = tibble( map_loc = names(som_cluster_adj) %>% as.integer()
               ,cluster = som_cluster_adj)

pred = tibble( map_loc = m$unit.classif) %>%
    left_join(link)
data_pred = winequality_white %>%
    bind_cols(pred)
ggplot(data_pred, aes(x = as.factor(cluster)
                      , fill = as.factor(quality))
) +
    geom_bar() +
    labs(x = 'Кластер', y = 'Количество образцов', fill = "Качество вина")

## Вывод:** 

# В 1 кластер попали все вина 6 уровня качества, во 2 кластер немногочисленные 9,3, 8 и многочисленные 7 и 5. В то время как 3 кластер в основном составляют вина 4, 5 и 6 качества.**
