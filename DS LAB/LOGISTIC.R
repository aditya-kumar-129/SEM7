#install.packages("dplyr")
library(dplyr)
summary(mtcars)

#install.packages("caTools")
#install.packages("ROCR")
library(caTools)
library(ROCR)

split = sample.split(mtcars,SplitRatio = 0.8)

training_Data = subset(mtcars, split == TRUE)
testing_Data = subset(mtcars, split == FALSE)

logistic_Model = glm(vs ~ wt + disp, training_Data, family = binomial)
summary(logistic_Model)

predict_reg = predict(logistic_Model, testing_Data , type = "response")
predict_reg = ifelse(predict_reg > 0.5,1,0)

table(testing_Data$vs, predict_reg)

missing_class_error = mean(predict_reg != testing_Data$vs)
print(paste("Accuracy = ", 1- missing_class_error))

ROC_prediction = prediction(predict_reg, testing_Data$vs)
ROC_Performance = performance(ROC_prediction, "tpr", "fpr")
auc = performance(ROC_prediction, "auc")

plot(ROC_Performance, main = "ROC CURVE")
abline(a = 0, b = 1)    # a, b: It specifies the intercept and the slope of the line