
library(keras)
library(ggplot2)
batch_size <- 32
epochs <- 30
#data_augmentation <- FALSE # потому что объем выборки большой
cifar10 <- dataset_cifar10()
  
x_train <- cifar10$train$x/255
x_test <- cifar10$test$x/255
y_train <- to_categorical(cifar10$train$y, num_classes = 10)
y_test <- to_categorical(cifar10$test$y, num_classes = 10)


library(EBImage)
# посмотрим примеры картинок
pictures = c(15, 87, 97, 100, 104, 208, 351, 800, 1909, 2004) #случайные вектор номеров картинок

fig_img  = list()
for (i in 1:10 ) {
  fig_mat  = cifar10$train$x[pictures[i], , , ]
  fig_img[[i]]  = normalize(Image(transpose(fig_mat), dim=c(32,32,3), colormode='Color'))
}
fig_img_comb = combine(fig_img[1:10])
fig_img_obj = tile(fig_img_comb,5)
plot(fig_img_obj, all=T)

suppressWarnings({model = keras_model_sequential()})
model %>%
  layer_conv_2d( filters = 128, kernel_size = c(3,3), padding = "same", input_shape = c(32, 32, 3), activation = "relu" ) %>%
  layer_conv_2d(filters  = 64, kernel_size = c(3,3), activation = "relu") %>%
  layer_max_pooling_2d(pool_size = c(2,2)) %>%
  layer_dropout(0.2) %>%
  layer_conv_2d(filters = 64, kernel_size = c(3,3), padding = "same", activation = "relu") %>%
  layer_conv_2d(filters = 32, kernel_size = c(3,3), activation = "relu") %>%
  layer_max_pooling_2d(pool_size = c(2,2)) %>%
  layer_dropout(0.2) %>%
  layer_flatten() %>%
  layer_dense(256, activation = "relu") %>%
  layer_dropout(0.3) %>%
  layer_dense(10, activation = "softmax") %>%
  compile(
          loss = "categorical_crossentropy",
          optimizer = optimizer_nadam(learning_rate = 0.001),
          metrics = "categorical_accuracy" )

summary(model)

start.time = Sys.time()

history_model<- model %>% fit(
     x_train, y_train,
     batch_size = batch_size,
     epochs = epochs,
     validation_data = list(x_test, y_test),
     shuffle = TRUE )

end.time = Sys.time()

plot(history_model) + 
  scale_x_continuous(limits = c(0, length(history_model$metrics$val_loss)))

model %>%
    keras::evaluate(x_test, y_test)
model %>% save_model_hdf5("zad8.h5")
