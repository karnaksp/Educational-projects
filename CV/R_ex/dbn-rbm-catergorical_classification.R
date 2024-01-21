
library(readr)
library(keras)
library(ggplot2)
library(gridExtra)
library(purrr)
library(boot)
library(RBM)

fmnist <- read_csv("fashion-mnist_train.csv",
                       col_types = cols(.default = "i"))

fmnist_plot=fmnist
fmnist_plot$label = as.factor(fmnist_plot$label)
fmnist_plot$cat = fmnist_plot$label
categories = c("T-shirt", "Trouser", "Pullover", "Dress", "Coat",
               "Sandal", "Shirt", "Sneaker", "Bag", "Boot")
fmnist_plot = fmnist_plot[ ,c(1,786,2:785)]
xy_axis = data.frame(x = expand.grid(1:28,28:1)[,1],
                     y = expand.grid(1:28,28:1)[,2])
plot_theme = list(raster = geom_raster(hjust = 0, vjust = 0), 
                  gradient_fill = scale_fill_gradient(low = "white", high = "black", 
                                                      guide = FALSE), 
                  theme = theme(axis.title = element_blank(), 
                                panel.background = element_blank(),
                                panel.border = element_blank(),
                                panel.grid.major = element_blank(),
                                panel.grid.minor = element_blank(), 
                                plot.background = element_blank(),
                                aspect.ratio = 1))
set.seed(128)
sample_plots = sample(1:nrow(fmnist),20) %>% map(~ {
  plot_data = cbind(xy_axis, fill = as.data.frame(t(fmnist_plot[.x, -c(1,2)]))[,1]) 
  ggplot(plot_data, aes(x, y, fill = fill)) + plot_theme
})
suppressWarnings(do.call("grid.arrange", c(sample_plots, ncol = 4, nrow = 5)))

test.data <- read_csv("fashion-mnist_test.csv",
                      col_types = cols(.default = "i"))

train_m <- data.matrix(fmnist)
test_m <- data.matrix(test.data)
train_x <- train_m[,-1]
test_x <- test_m[,-1]
train_y <- train_m[,1]
test_y <- test_m[,1]
train_x_array <- array_reshape(train_x, dim(train_x))
test_x_array <- array_reshape(test_x, dim(test_x))
train_x.sc <- train_x_array/255
test_x.sc <- test_x_array/255

modDBN <- DBN(x = train_x.sc, y = train_y, nodes = c(500, 400, 300), 
              n.iter.pre = 1000, n.iter = 10000,
              learning.rate = 0.1, verbose = FALSE)
PredictDBN(test = test_x.sc, labels = test_y, model = modDBN, layers = 4)

