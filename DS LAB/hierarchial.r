# data1 = data.frame(x=c(2,2,8,5,7,6,1,4,3), y=c(10,5,4,8,5,4,2,9,9))
data2 = data.frame(x=c(1,1,7,4,6,5,1,4,3), y=c(9,6,3,8,6,5,2,9,9))

distance_mat <- dist(data2, method = "euclidean")
distance_mat

set.seed(240)  # Setting seed
model <- hclust(distance_mat, method = "average")
plot(model)