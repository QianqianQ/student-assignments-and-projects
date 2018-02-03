setwd("C:/Users/tracy/Desktop/Multivariate Statistical Analysis/作业/作业 9/directory") 
install.packages("MASS") 
library(MASS) 
al<-read.table("ALCOHOL.txt",header=T,sep="\t") 
dim(al) 
View(al) 
al.lda<-lda(TYPE~. ,data=al) 
names(al.lda) 
al.lda$prior  
al.lda$N   
al.lda$means  
al.lda$scaling 
newdrink <- data.frame(MEOH=500,ACET=400,BU1=3,MEPR=30,ACAL=20,LNPRO1=10) 
predict(al.lda,newdata=newdrink)$class 