#install.packages("caTools")
#install.packages("randomForest")
library(caTools)
library(randomForest)

data(iris)
str(iris)

split = sample.split(iris, SplitRatio = 0.7)
training_data = subset(iris, split == TRUE)
testing_data = subset(iris, split == FALSE)

# Fitting Random Forest to the train dataset
# What does seed function do in R?
# seed() function in R is used to create reproducible results when 
# writing code that involves creating variables that take on random values.
set.seed(120) # Setting seed
classifier_RF = randomForest(x = training_data[-5], y = training_data$Species, ntree = 500)
classifier_RF

# Predicting the Test set results
y_pred = predict(classifier_RF, testing_data[-5])

# Confusion Matrix
table(testing_data$Species, y_pred)

plot(classifier_RF)        # Plotting model
importance(classifier_RF)  # Importance plot
varImpPlot(classifier_RF)  # Variable importance plot