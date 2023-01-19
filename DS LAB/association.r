# install.packages("arules")
# install.packages("arulesViz")
library(arules)
library(arulesViz)

# file naming in ubuntu
# /home/userName/Desktop/folderName/fileName.csv

data("Groceries")
# summary(Groceries)

dataset = read.transactions('bn.csv')

model1 = apriori(dataset,parameter=list(support=0.002,confidence=0.5))
inspect(head(model1,5))
plot(model1,method="grouped")

# model2 = apriori(Groceries,parameter=list(support=0.002,confidence=0.5,minlen=4))
# inspect(head(model2,4))
# plot(model2,method="grouped")