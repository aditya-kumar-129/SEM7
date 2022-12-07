# x = c(1,2,3,4,5,6,7,8,9,10)
# y = c(11,12,13,14,15,16,17,18,19,20)

# data = list(col1=x,col2=y)
# data

# as.data.frame(data)
# relation = lm(data$col2~data$col1)

# plot(y, x, abline(lm(x~y)), xlab="X_AXIS", ylab="Y_AXIS")
# ans = predict(relation,data[])
# ans

getwd()
data = read.csv("income.csv")
head(data)

# install.packages("ggplot2")
# install.packages("dplyr")
library(ggplot2)
library(dplyr)

summary(data)

hist(data$happiness)
plot(happiness ~ income, data)

LM_model = lm(happiness ~ income, data)
summary(LM_model)

graph = ggplot(data, aes(x=income, y=happiness))+ geom_point() + geom_smooth(method="lm", col="black") +
  stat_regline_equation(label.x = 3, label.y = 7)
graph
abline(1,0)