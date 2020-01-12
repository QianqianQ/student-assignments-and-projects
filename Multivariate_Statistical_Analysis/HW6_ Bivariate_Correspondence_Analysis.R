setwd("C:/Users/tracy/Desktop/Multivariate Statistical Analysis/作业/作业6/directory")
install.packages("ca")
library(ca)
data<-read.table("SMOKING.txt",header=T,row.names=1)
dim(data)
View(data)
S<-as.matrix(data[-6,-5])
prop.table(S,1) #Row profiles
prop.table(S,2) #Column profiles
prop.table(S) #Table of relative frequencies
v1 <- matrix(colSums(S),nrow=1)
v2 <- matrix(rowSums(S),ncol=1)
n<-sum(S)
E <- v2 %*% v1/n #Theoretical frequencies under independence
AR.matrix<-S/E #Attraction Repulsion Matrix

I <- dim(S)[1]
J <- dim(S)[2]
w <- 0
for(i in 1:I){
  for(j in 1:J){
    w <- w + ( S[i,j]-E[i,j] )^2/(E[i,j])
  }
}
pchisq(w,df=((I-1)*(J-1)),lower.tail=F)
chisq.test(S)
S.ca <- ca(S)
names(S.ca)
S.ca$sv
S.ca$rowdist
S.ca$rownames
S.ca$coldist
S.ca$colnames
S.ca$rowcoord
S.ca$colcoord 
S.ca$rowinertia 
S.ca$colinertia
sum(S.ca$rowinertia)
sum(S.ca$colinertia)
sum(S.ca$sv^2)
w/n 
S.ca$rowinertia/sum(S.ca$sv^2) 
S.ca$rowmass
S.ca$colmass 
margin.table(as.matrix(S),1)/sum(S)
margin.table(as.matrix(S),2)/sum(S)
S.ca$N 
S.ca
summary(S.ca)
names(summary(S.ca)$rows)
plot(S.ca)
plot(S.ca,arrows=c(T,T),map="symmetric") 
plot(S.ca,arrows=c(T,T),map="symmetric",dim=c(1,2))
install.packages("rgl")
plot3d.ca(S.ca)




