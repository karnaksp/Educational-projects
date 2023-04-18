
library(keras) # чтобы не отображать результат написать после r.. eval=FALSE
library(dplyr)
library(glue)
library(tidyverse)
train_dir <- file.path("data/dogs-vs-cats/train")
test_dir <- file.path("data/dogs-vs-cats/test")
# create train, validation, and test file paths for cat images
train_cats_dir <- file.path(train_dir, "cats")
test_cats_dir <- file.path(test_dir, "cats")

# create train, validation, and test file paths for dog images
train_dogs_dir <- file.path(train_dir, "dogs")
test_dogs_dir <- file.path(test_dir, "dogs")

fnames_tcat<- list.files(train_cats_dir, full.names = TRUE) #список файлов в директории
img_path<- fnames_tcat[[15]] # выберем 1 картинку под индексом 15, например
img<- image_load(img_path, target_size = c(300,300))
# преобразуем в тензор
img_array<- array_reshape(image_to_array(img), c(1, 300, 300, 3))

datagen <- image_data_generator(rescale = 1/255, rotation_range = 190,fill_mode = "nearest" )
# rescale используется для перемасштабирования даннхы пикселей из 0-255 в 0-1, что является по сути своей нормализацией
aug_iter<- flow_images_from_data(img_array, generator = datagen, 
                                 batch_size = 1)
# batch_size используется здесь для разбиения изображения на равное количество изображений, в данном случае м этого не делаем
axs<- par(mfrow = c(3,1), pty = 's')
for (i in 1:3) {
  batch<- generator_next(aug_iter)
  plot(as.raster(batch[1,,,]))
}

datagen <- image_data_generator(rescale = 1/255, width_shift_range=0.2, height_shift_range=0.2)
aug_iter<- flow_images_from_data(img_array, generator = datagen, 
                                 batch_size = 1)
axs<- par(mfrow = c(3,2), pty = 's')
for (i in 1:6) {
  batch<- generator_next(aug_iter)
  plot(as.raster(batch[1,,,]))
}

datagen <- image_data_generator(rescale = 1/255, horizontal_flip=T, vertical_flip=T)
aug_iter<- flow_images_from_data(img_array, generator = datagen, 
                                 batch_size = 1)
axs<- par(mfrow = c(3,1), pty = 's')
for (i in 1:3) {
  batch<- generator_next(aug_iter)
  plot(as.raster(batch[1,,,]))
}

datagen <- image_data_generator(rescale = 1/255, brightness_range=(0.4:1.5))
aug_iter<- flow_images_from_data(img_array, generator = datagen, 
                                 batch_size = 1)
axs<- par(mfrow = c(3,1), pty = 's')
for (i in 1:3) {
  batch<- generator_next(aug_iter)
  plot(as.raster(batch[1,,,]))
}

datagen <- image_data_generator(rescale = 1/255, zoom_range = 0.3)
aug_iter<- flow_images_from_data(img_array, generator = datagen, 
                                 batch_size = 1)
axs<- par(mfrow = c(3,1), pty = 's')
for (i in 1:3) {
  batch<- generator_next(aug_iter)
  plot(as.raster(batch[1,,,]))
}

datagen <- image_data_generator(rescale = 1/255, rotation_range = 140,  
                                width_shift_range = (0.2:0.9),
                                height_shift_range = (0.2:0.9), 
                                shear_range = (0.2:0.9), 
                                brightness_range=(0.4:1.5), 
                                horizontal_flip = T, vertical_flip = T, 
                                fill_mode = "nearest")
aug_iter<- flow_images_from_data(img_array, generator = datagen, 
                                 batch_size = 1)
axs<- par(mfrow = c(3,3), pty = 's')
for (i in 1:12) {
  batch<- generator_next(aug_iter)
  plot(as.raster(batch[1,,,]))
}

# Загрузка данных 2 категорий
fnames_tdog<- list.files(train_dogs_dir, full.names = TRUE)
img_path_cats<- fnames_tcat[60:69] 
img_path_dogs<- fnames_tdog[60:69]
img_path<- c(img_path_cats, img_path_dogs)

loadpics = function(filenames) {
  a = lapply(filenames, image_load, target_size = c(100,100))
  b = lapply(a, image_to_array)
  c = lapply(b, array_reshape, dim = c(100, 100, 3))
  d = normalize(c, axis = 1)
  return(d)
  }

trainx = loadpics(img_path) 
trainlabel = to_categorical(c(1, 1,1,1,1,1,1,1,1,1, 0, 0,0,0,0,0,0,0,0,0))

# Формирование набора из 2 изображений каждого класса

train_generator <- flow_images_from_data(x = trainx, y = trainlabel,
    datagen, batch_size = 20)
batch <- generator_next(train_generator)
str(batch)

img_path_cats<- fnames_tcat[80:89] 
img_path_dogs<- fnames_tdog[80:89]
img_path<- c(img_path_cats, img_path_dogs)
testx = loadpics(img_path) 
testlabel = trainlabel

cnn <- keras_model_sequential() %>%
    layer_conv_2d(filters = 32, kernel_size = c(3,3), activation = "relu",
        input_shape = c(100, 100, 3)) %>% 
  layer_batch_normalization()%>%
  layer_conv_2d(filters = 32, kernel_size = c(3,3), padding = 'Same',
                activation = 'relu')%>%
  layer_batch_normalization()%>%
  layer_max_pooling_2d(pool_size = c(2, 2))%>%
  layer_dropout(rate = 0.2) %>% 
  layer_conv_2d(filters = 64, kernel_size = c(3,3),padding = 'Same',
                activation = 'relu')%>%
  layer_batch_normalization()%>%
  layer_conv_2d(filters = 64, kernel_size = c(3, 3), activation = "relu") %>%
  layer_max_pooling_2d(pool_size = c(2, 2)) %>%
  layer_conv_2d(filters = 64, kernel_size = c(2, 2), activation = "relu") %>% 
  layer_dropout(rate = 0.2) %>%
  layer_flatten() %>%
  layer_dense(units=1024,activation='relu')%>%
  layer_dense(units=512,activation='relu')%>%
  layer_dense(units=256,activation='relu')%>%
  layer_dense(units = 2, activation = "softmax")
cnn %>% compile(
  loss = "binary_crossentropy",
  optimizer = optimizer_adam(),
  metrics = keras$metrics$AUC()
)

summary(cnn)

history_cnn <- cnn %>%
    fit(train_generator, epochs = 20,
        verbose = 0)
plot(history_cnn)

cnn %>%
    keras::evaluate(testx, testlabel)

datagen <- image_data_generator(
  featurewise_center = F,
  samplewise_center=F,
  featurewise_std_normalization = F,
  samplewise_std_normalization=F,
  zca_whitening=F,
  horizontal_flip = F,
  vertical_flip = F,
  width_shift_range = 0.15,
  height_shift_range = 0.15,
  rotation_range = 0.15,
  shear_range = 0.15)
train_generator <- flow_images_from_data(x = trainx, y = trainlabel,
    datagen, batch_size = 128)
# Определим так же тестовые данные для проверки сети:
valid_generator <- flow_images_from_data(x = testx, y = testlabel,
    datagen, batch_size = 128)

history_cnn <- cnn %>%
    fit_generator(train_generator, steps_per_epoch = 1, epochs = 10, 
                  validation_data = valid_generator)
plot(history_cnn) + 
  scale_x_continuous(limits = c(0, length(history_cnn$metrics$val_loss)))

cnn %>% save_model_hdf5("cats_and_dogs.h5")
