data<-read.table("SCIENCEDOCTORATES.txt",header=T,row.names=1)
View(data)
dim(data)
S<-as.matrix(data[-13,-9])

#Form the attraction repulsion matrix
class(S)
prop.table(S,1)
#prop.table() and margin.table() want a matrix type pbject(use matrix())
#You dont need any extra packages here

#1.See what prop.table does(what are the row and column profiles?)
prop.table(S)
sum(prop.table(S))
prop.table(S,1)#Row profiles
rowSums(prop.table(S,1))
#2.See what margin.table does
marigin.table(S)
sum(S)

margin.table(S,1)
rowSums(S)

margin.table(S,2)
colSum(S)
#3.Form the matrix of expected number of observations under independence
v1<-matrix(margin.table(S,1),ncol=1)
v2<-matrix(margin.table(S,2),nrow=1)
#or make thenm as vectors and use outers
E<-v1%*%v2/sum(S) #E=expected number of obserbations under independence
AR.matrix<-S/E #s=Observed number of observation
View(round(AR.matrix,2))
#Value near 1: The year and science independent
#Values <1: The science is less frequent in the specific year(repulsion)
#Value>1: The science is more frequent in the specific year(attraction)

library(ggplot2)

#(you can use margin.table() in 3 and simple vector operations)
#4.Calculate the attraction repulsion matrix
#5.Interpret the AR-matrix

#(a)(b)Use this R-code as a  starting point
#(c)Think as repulsion with respect to something
#During the exercise the following was a bit buggy
library(ggplot2)
library(reshape2)
library(digest)
install.packages("reshape2")
install.packages(c("stringi","ggplot2","stringi"))
class(melted)
#Note that ggplot wants data.frames
melted<-melt(AR.matrix)
ggplot(melted,aes(x=Var1,y=Var2,fill=value))+
  geom_tile()+scale_fill_gradient2(low="blue",high="red",mid="white",midpoint=(or 1,good)median(melted$value),limit=c(0,5,1,55),name="AR value")
library(ggplot2)
