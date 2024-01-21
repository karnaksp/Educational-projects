
install.packages('nnet')
install.packages('GGally')
install.packages('ggplot2')
install.packages('dplyr')

library('nnet')
data <- read_table("C:/Users/user/Downloads/verte/column_3C.dat", 
                   col_names = FALSE, col_types = cols(X1 = col_number(), 
                                                       X2 = col_number(), X3 = col_number(), 
                                                       X4 = col_number(), X5 = col_number(), 
                                                       X6 = col_number()))
summary(data)

library(GGally)

ggpairs(data, columns = 1:6, aes(color = X7, alpha = 0.4),
        upper = list(continuous = wrap("cor", size = 2.5)),
        title ="Взаимное распределение данных по категориям")   

library(dplyr)
data<- na.omit(data)
data %>% count(X7)

targets<- class.ind(c(rep('DH', 60), rep('NO', 100), rep('SL', 150)))
X7<-data$X7
data$X7<- NULL
# нормализация данных улучшит прогноз
data <- data %>% mutate(across(1:6, ~ scale(.x)))

set.seed(55)
samp<- c(sample(1:60,round((0.9*60), digits = 0)), 
         sample(61:160, round((0.8*100), digits = 0)),
         sample(161:310, round((0.7*150), digits = 0)))
#
train<- data[ samp , ]
test<- data[ -samp , ]
y_train<- targets[ samp , ]
y_test<- targets[ -samp , ]

set.seed(67)
net.vertebral<- nnet(train, y_train, size = 5, maxit = 10000)
net.pred<- predict(net.vertebral, test)
table(max.col(y_test), max.col(net.pred))

# В итоге можно сказать, что модель работает не очень хорошо, по скольку определяет некоторые наблюдения ошибочно. Это связано, вероятно, с малым количеством наблюдений в группе DH - грыжа диска. -->
