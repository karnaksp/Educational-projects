
# Данные предварительно были загружены из <http://archive.ics.uci.edu/ml/datasets/Adult>

# Набор данных о доходах взрослых представляет собой компиляцию данных о доходах на индивидуальном уровне по возрасту, полу, истории образования, профессии, семейному положению, приросту и потере капитала, рабочему времени и расе. Всего он содержит 15 атрибутов и 32561 индивидуальную запись.

# Цель анализа --- разработать классификационную модель для прогнозирования того, превышает ли годовой доход человека 50 000 \$ на основе нескольких атрибутов из набора данных. Таким образом, наша целевая переменная --- это доход, категориальная переменная, которая указывает на то, что человек имеет доход \< \| \>50 000 \$ /год.

dat = read.csv("adult.csv")
str(dat)
summary(dat)
# Чистка данных**

# Переменную «образование» можно удалить. fnlwgt: финальный оценочный вес - не понятно, что значит, поэтому тоже. marital.status указывает на семейное положение человека, поэтому переменная relationship является избыточной. итак, переменные fnlwgt, education и relationship будут удалены.

dat = dat[,-c(3,4,8)] 
# Удалим выбросы в данных 
dat = subset(dat, age <= 72)
dat = subset(dat, education.num >= 4.5)
dat = subset(dat, capital.gain < 99999)

# Преобразование категориальных переменных**

# Если категориальная переменная состоит из слишком большого количества значений полей, мы должны переклассифицировать значения полей категориальных переменных. Проведем реклассификацию по четырем переменным: рабочий класс, семейное положение, родная страна и род занятий.

library(forcats)
dat$occupation = gsub("?", "Unknown", dat$occupation, fixed = T )
dat$occupation = as_factor(dat$occupation)
dat$race = as_factor(dat$race)
dat$sex = as_factor(dat$sex)
dat$workclass = gsub("?", "Unknown", dat$workclass, fixed = T )
dat$workclass = as_factor(dat$workclass)
dat$marital.status = as_factor(dat$marital.status)
levels(dat$marital.status)[c(2,3,4)] = 'Married'
levels(dat$workclass)[c(1,2,7)] = 'Gov'
levels(dat$workclass)[4:5] = 'Self-emp'
t1 = table(dat$native.country) 
prop.table(t1) 
# Поскольку большая доля записей из США, мы группируем переменную native.country на «неамериканские» и «американские».
dat$native.country = as_factor(dat$native.country)
levels(dat$native.country)[c(28)] = 'United-States'
levels(dat$native.country)[c(1:27,29:41)] = 'Non-U.S.'
levels(dat$occupation)[c(6,8,9)] = 'Service'
levels(dat$occupation)[c(4,8)] = 'Professional/Managerial'
levels(dat$occupation)[c(1,7)] = 'Administration'

for (i in c(1, 3, 8, 9, 10)){
  mindf = min(dat[,i])
  maxdf = max(dat[,i])
  dat[,i] =(dat[,i] - mindf)/(maxdf - mindf)
}

# Разделение набора на тренировочные и тестовые**

# Мы случайным образом разделяем набор данных DF на обучающий и тестовый наборы с помощью функции sample(). Обучающий набор DF.training содержит 75% наблюдений, а тестовые данные DF.test --- оставшиеся 25% наблюдений.

DF=dat
set.seed(123)
samp = sample(1:nrow(DF),round(0.75*nrow(DF)))
DF.training = DF[samp,]
DF.test= DF[-samp,]


# Создание фиктивной переменной

# Поскольку нейронная сеть не может обрабатывать категориальные переменные, мы используем функцию dummyVars() из библиотеки Caret для создания индикаторных переменных для категориальных переменных.

library('caret')
dmy.training = dummyVars(" ~ .", data = DF.training)
training.dmy = data.frame(predict(dmy.training, newdata = DF.training))
training.dmy = training.dmy[-37]
names(training.dmy)[names(training.dmy) == "income..50K"] = "income.more.50k" 
dmy.test = dummyVars(" ~ .", data = DF.test)
test.dmy = data.frame(predict(dmy.test, newdata = DF.test))
test.dmy = test.dmy[-37] 
names(test.dmy)[names(test.dmy) == "income..50K"] = "income.more.50k" 
head(training.dmy)

# Создание матрицы для сравнения моделей

# Поскольку мы будем проводить оценку для оценки производительности нескольких моделей, нам нужно подготовить матрицу с именами моделей.

Model.Com = data.frame(matrix(c(0), nrow=4, ncol=9))
colnames(Model.Com) = (c('Models','True Pos', 'True Neg','False Pos', 'False Neg','Overall Error Rate(%)','Accuracy(%)','Sensitivity(%)','Specificity(%)'))
Model.Com$Models = (c('neuralnet3','knn20','CART Tree', 'C4.5Tree1'))

# Построение моделей

# Мы используем neuronet() и обучающий набор training.dmy для построения нейронной сети, применяя 3 скрытых слоя. Причина использования обучающего набора данных с индикаторными переменными заключается в том, что это позволит нам сравнить производительность функции нейронной сети в R.


library(neuralnet)
neuralnet3 = neuralnet(income.50K~., 
                       data = training.dmy, learningrate = 0.1)
estincome.neuralnet3= predict(neuralnet3, test.dmy, method='class')
pred.neuralnet3 = rep('<=50K', length(estincome.neuralnet3))
pred.neuralnet3 [estincome.neuralnet3>=0.5] = '>50K'
pred.neuralnet3 = as.factor(pred.neuralnet3)
DF.test$income = as_factor(DF.test$income)
cm.neuralnet3 = confusionMatrix(reference = DF.test$income, data = pred.neuralnet3, positive = '>50K')
cm.neuralnet3

library(class)
knn.training = training.dmy[-37]
knn.test = test.dmy[-37]
DF_train_labels = DF$income[samp]
DF_test_labels = DF$income[-samp]
estknn.20 = knn(knn.training, knn.test , DF_train_labels, k=20)
cm.knn20 = confusionMatrix(reference = DF.test$income, data = estknn.20, positive = '>50K')
cm.knn20

library(rpart)
library(rpart.plot)
Ctree1 = rpart(income~., data=DF.training, method = "class", model = TRUE,control = rpart.control(minsplit = 1000))
realincome = DF.test$income
estincome.Ctree1 = predict(Ctree1, DF.test, type="class")
cm.Ctree1 = confusionMatrix(reference = DF.test$income, data = estincome.Ctree1, positive = '>50K')
cm.Ctree1

library(C50)
x=DF.training[-12]
y=as_factor(DF.training$income)
C.50tree1 = C5.0(x,y, control = C5.0Control(minCases = 100))
est.C.50tree1 = predict(C.50tree1, DF.test, type='class')
cm.C.50tree1 = confusionMatrix(reference = DF.test$income, data = est.C.50tree1, positive = '>50K')
cm.C.50tree1

# В оценочной матрице Model.Com мы определяем 4 показателя оценки:

# -   Overall Error Rate(%): частота возникновения ошибок. Он рассчитывается путем деления количества всех неверных прогнозов на общее количество набора данных.

# -   Accuracy: рассчитывается как сумма истинных положительных и истинных отрицательных результатов, деленная на общее количество наблюдений набора данных.

# -   Чувствительность: способность моделей идентифицировать высокую долю людей, которые зарабатывают более 50 тысяч в год (положительная группа). Идеальная модель классификации должна иметь чувствительность = 1,0 (или 100%).

# -   Специфичность: способность моделей идентифицировать высокую долю людей, которые зарабатывают менее 50 тысяч в год (отрицательная группа). Идеальная модель классификации должна иметь специфичность = 1,0 (или 100%).


library(dplyr)
library(kableExtra)
library(formattable)

Model.Com[1,2] = neuralnet3.True.Positive = cm.neuralnet3$table[2,2]
Model.Com[1,3] = neuralnet3.True.Negative = cm.neuralnet3$table[1,1]
Model.Com[1,4] = neuralnet3.False.Positive = cm.neuralnet3$table[2,1]
Model.Com[1,5] = neuralnet3.False.Negative = cm.neuralnet3$table[1,2]
Model.Com[2,2] = knn20.True.Positive = cm.knn20$table[2,2]
Model.Com[2,3] = knn20.True.Negative = cm.knn20$table[1,1]
Model.Com[2,4] = knn20.False.Positive = cm.knn20$table[2,1]
Model.Com[2,5] = knn20.False.Negative = cm.knn20$table[1,2]
Model.Com[3,2] = Ctree1.True.Positive = cm.Ctree1$table[2,2]
Model.Com[3,3] = Ctree1.True.Negative = cm.Ctree1$table[1,1]
Model.Com[3,4] = Ctree1.False.Positive = cm.Ctree1$table[2,1]
Model.Com[3,5] = Ctree1.False.Negative = cm.Ctree1$table[1,2]
Model.Com[4,2] = C.50tree1.True.Positive = cm.C.50tree1$table[2,2]
Model.Com[4,3] = C.50tree1.True.Negative = cm.C.50tree1$table[1,1]
Model.Com[4,4] = C.50tree1.False.Positive = cm.C.50tree1$table[2,1]
Model.Com[4,5] = C.50tree1.False.Negative = cm.C.50tree1$table[1,2]

###########################################################################

Overall.Error.Rate = (Model.Com[,4] + Model.Com[,5])/(Model.Com[,2] + Model.Com[,3]+ Model.Com[,4] + Model.Com[,5])*100
Sensitivity = Model.Com[,2]/(Model.Com[,2] + Model.Com[,5])*100 
Specificity = Model.Com[,3]/(Model.Com[,4] + Model.Com[,3])*100  

###########################################################################

Model.Com[1:4,6]=round(Overall.Error.Rate, digits = 3) 
Model.Com[1:4,8]=round(Sensitivity, digits = 3)
Model.Com[1:4,9]=round(Specificity, digits = 3)
Overall.Accuracy = round(100-Model.Com[,6], digits = 3)
Model.Com[1:4,7]=Overall.Accuracy

Model.Com %>%
  mutate(
    Models = cell_spec(Models, color = "white", bold = T, background = spec_color(1:4, end = 0.9, option = "D", direction = 1)),
    `Overall Error Rate(%)` = color_tile("Gold", "LightYellow")(`Overall Error Rate(%)`),
    `Accuracy(%)` = color_tile("Linen", "red")(`Accuracy(%)`),
    `Sensitivity(%)` = color_tile("Linen", "red")(`Sensitivity(%)`),
    `Specificity(%)` = color_tile("Linen", "red")(`Specificity(%)`) 
  )%>%
  kable(escape = F, align = "l") %>%
  kable_styling(bootstrap_options = c("striped", "hover", "condensed","responsive"))%>%
  row_spec(0, font_size = 9)%>%
  column_spec(2:8, bold = T, color = "DimGray")


# Вывод**

# Используя алгоритм C4.5, мы построили удовлетворительную модель для прогнозирования класса дохода человека при этом затратив небольшое количество ресурсов.
