#a)
setwd("C:/Users/tracy/Desktop/Multivariate/ื๗าต/directory")
install.packages("mvtnorm")
library(mvtnorm)
set.seed(123)
N<-100
mean<-matrix(c(4,7),byrow=FALSE,ncol=1)
Si<-matrix(c(10,6,6,8),byrow=TRUE,ncol=2)
x <- rmvnorm(N,mean,Si)
x <- sweep(x,2,colMeans(x),"-")
plot(x)
text(x,labels=c(1:100),pos=1)
r1=range(x[,1])
r2=range(x[,2])

#b)
x.PCA<-princomp(x,cor=FALSE)
#c)
x.PCA$loadings
plot(x.PCA$scores,xlim=r1, ylim =r2)
text(x.PCA$scores[,1:2],labels=c(1:100),pos=1)
#d)

#e)
n <- nrow(x)
x_cov<-(n-1)/n*cov(x)
ei <- eigen(cov_x)
G <- ei$vectors
Y = x%*%G

x_cov_eval <- eigen(x_cov)$values
(x.PCA$sdev)^2
x_cov_eval-(x.PCA$sdev)^2
x.PCA$scores
x.PCA$scores-Y

