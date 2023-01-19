# install.packages("ggfortify")   #autoplot function is present in this package
library("ggfortify")

# data <- data.frame(x= c(2,2,8,5,7,6,1,4,3), y= c(10,5,4,8,5,4,2,9,9))
data1 = data.frame(x = c(1,1,7,4,6,5,1,4,3), y=c(9,6,3,8,6,5,2,9,9))

# when the center is 2
model = kmeans(data, 2)
model$centers
autoplot(model, data, frame = TRUE)