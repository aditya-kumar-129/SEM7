# install.packages("ggplot2")
library("ggplot2")
data <- read.csv("weather.csv")
x <- data[-4]
y <- data$Rain
#Apply lm function
relation <- lm(y ~ temperature, data = data)
# summary(relation)

#Find weight of a person with temperature 5.6
a <- data.frame(temperature = 5.6)
result <- predict(relation, a)
print(result)

plot(y, data$temperature, abline(lm(data$temperature ~ y)),
xlab = "temperature in C", ylab = "Rain")