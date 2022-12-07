data(iris)
str(iris)

# install.packages("gtools")
# install.packages("ClusterR")
# install.packages("cluster")
# install.packages("ggfortify")

library(gtools)
library(ClusterR)
library(cluster)
library(ggfortify)

# Fitting K-Means clustering Model to training dataset
set.seed(240) # Setting seed
kmeans = kmeans(iris[-5], centers = 3, nstart = 20)
kmeans

# Cluster identification for each observation
kmeans$cluster

# Confusion Matrix
table(iris$Species, kmeans$cluster)

autoplot(kmeans,iris[-5], frame= TRUE)