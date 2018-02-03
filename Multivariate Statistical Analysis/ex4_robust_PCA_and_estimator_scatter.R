#MCD is affine equivariant
#Fast MCD not affine equivariant
#install.packages("rrcov")#run only once
#a
library(rrcov)
help("CovMcd")
setwd("//home.org.aalto.fi/qinq1/data/Desktop/Directory")
wood<-read.table("wood.txt",header=T)
dim(wood)
View(wood)
#b
plot(wood)
#c
scov<-cov(wood)
#Note that a know bug here,for alpha=1 gives incorrect results
rcov<-CovMcd(wood,alpha=1/2)#Note big C
#covMcd(wood,alpha=1/2)$cov
#rcov is S4 object, main difference is that you access the slots via @
rcov@cov
scov
#d
#Note that this calculates mahalanobis^2
#If the original data is normally distributed,
#then the squared the mahalanobis distances follow chi-squared distibution
#with p-degrees of freedom(p=number of variables)
s.maha<-mahalanobis(wood,center=colMeans(wood),cov=scov)
r.maha<-mahalanobis(wood,center=rcov@center,cov=rcov@cov)
qqplot(qchisq(ppoints(20),df=5),s.maha,main="Using regular covariance")
qqline(s.maha,distribution=function(p) qchisq(p,df=5))
qqplot(qchisq(ppoints(20),df=5),r.maha,main="Using MCD")
qqline(r.maha,distribution=function(p) qchisq(p,df=5))
dim(wood)
plot(c(1,20),range(sqrt(c(s.maha,r.maha))),type='n',xlab="Observation",ylab="Mahalanobis distance")
points(1:20,sqrt(s.maha),col="blue")
points(1:20,sqrt(r.maha),col="red",pch=16)
legend("topleft",col=c("blue","red"),legend=c("Classic","MCD"),pch=c(1,16))
View(wood)
PCA1<-princomp(wood,cor=T)
summary(PCA1)
pairs(PCA1$scores)
plot(PCA1$scores[,1],PCA1$scores[,2])
pairs(wood)
#big P and big C
#scale=TRUE is the same as before cor=T
PCA2<-PcaCov(wood,scale=TRUE)
summary(PCA2)
#Note the S4 @
pairs(PCA2@scores)
PCA1$loadings
PCA2@loadings

# Exercise 2
#normal- and t-distribution are elliptical parts a,b
#part c not elliptical distribution
set.seed(456)
n<-200
library(mvtnorm)
D1<-rmvnorm(n,mean=c(0,0),sigma=diag(2))
plot(D1)
D2<-rmvt(n,df=5,sigma=diag(2))
plot(D2)
X1<-rweibull(n,shape=1,scale=2)
X2<-rgamma(n,shape=2,scale=1)
D3<-cbind(X1,X2)
plot(D3)
#note that not all symmetric distributions are elliptical
#Note that fast Mcd not affine equivariant
#this is why n might not help get exactly the same results
cov1<-cov(D1)
rcov1<-CovMcd(D1,alpha=1/2)@cov
cov1/cov1[1,1]
rcov1/rcov1[1,1]
cov2<-cov(D2)
rcov2<-CovMcd(D2,alpha=1/2)@cov
cov3<-cov(D3)
rcov3<-CovMcd(D3,alpha=1/2)@cov

#HW
#(a)
#First find the sample breakdown point
#then n->infinity
#Consider seperately even and odd sample sizes
#(they should have the same limit)
#Floor-operator makes things harder
#Check your answer
#(b)
#check the R-code made by Pauliina(under EX4)
#(it is in bivariate case,univariate is enough here)
#Explain your figures and make sure everything necessary is visible
#Make sure that hte functions are visible on the plot
#range
#(c)
#Lecture slidesss
