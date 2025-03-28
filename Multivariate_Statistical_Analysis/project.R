setwd("F:/学习资料/已完成/Multivariate Statistical Analysis/project/directory")
data <- read.csv("HR_comma_sep.csv")
library(factoextra)
install.packages("ca")
library(ggplot2)
library(ca)
dim(data)
View(data)
summary(data)
par(mfrow=c(2,3))
hist(data[,1],main="satisfaction level",ylab=NULL,xlab=NULL,col=c("steelblue"))
hist(data[,2],main="last evaluation",ylab=NULL,xlab=NULL,col=c("steelblue"))
hist(data[,3],main="number of projects",ylab=NULL,xlab=NULL,col=c("steelblue"))
hist(data[,4],main="average monthly hours",ylab=NULL,xlab=NULL,col=c("steelblue"))
hist(data[,5],main="time spent at companies",ylab=NULL,xlab=NULL,col=c("steelblue"))
par(mfrow=c(1,3))
tmp1 <- table(data[,6])
lab1 <- round(100*tmp1/sum(tmp1),1)
pielabels1 <- paste(lab1,"%",sep="")
cols <- c("blue","red","green","yellow")
pie(tmp1,col=cols,main="Whether had a accident",labels=pielabels1,cex=1.5)
legend("bottomleft",names(lab1),fill=cols,horiz=F,cex=1)
tmp2 <- table(data[,7])
lab2 <- round(100*tmp2/sum(tmp2),1)
pielabels2 <- paste(lab2,"%",sep="")
cols <- c("blue","red","green","yellow")
pie(tmp2,col=cols,main="Whether has left",labels=pielabels2,cex=1.5)
legend("bottomleft",names(lab2),fill=cols,horiz=F,cex=1)
tmp3 <- table(data[,8])
lab3 <- round(100*tmp3/sum(tmp3),1)
pielabels3 <- paste(lab3,"%",sep="")
cols <- c("blue","red","green","yellow")
pie(tmp3,col=cols,main="Whether has promotion",labels=pielabels3,cex=1.5)
legend("bottomleft",names(lab3),fill=cols,horiz=F,cex=1)
tmp4 <- table(data[,9])
lab4 <- round(100*tmp4/sum(tmp4),1)
pielabels4 <- paste(lab4,"%",sep="")
cols <- c("blue","red","green","yellow")
pie(tmp4,col=cols,main="Department",labels=pielabels4,cex=1.5)
legend("bottomleft",names(lab4),fill=cols,horiz=F,cex=0.5)
tmp5 <- table(data[,10])
lab5 <- round(100*tmp5/sum(tmp5),1)
pielabels5 <- paste(lab5,"%",sep="")
cols <- c("blue","red","green","yellow")
pie(tmp5,col=cols,main="salary",labels=pielabels5,cex=1.5)
legend("bottomleft",names(lab5),fill=cols,horiz=F,cex=0.5)
data$sales<-as.factor(data$sales)
data$salary<-as.factor(data$salary)
data$salary<-ordered(data$salary,levels=c("low","medium","high"))
library(corrplot)
cor(data[,1:8])
corrplot(cor(data[,1:8]),method="number")



X.pca = prcomp(X,center=TRUE,scale.=TRUE)
print(X.pca$rotation)
library(factoextra)
library(ggplot2)
data$salary = as.numeric(data$salary)
hr = subset(data,data$left==1)
X = hr[,c(1:6,8,10)]
Y = hr[,7]
X.pca = prcomp(X,center=TRUE,scale.=TRUE)
print(X.pca$rotation)
print(summary(X.pca))
par(mfrow=c(1,2))
fviz_screeplot(X.pca,choice='eigenvalue')
fviz_pca_var(X.pca)
new=as.data.frame(predict(X.pca,newdata=X))
  
set.seed(100)
new.cluster<-kmeans(new,3,nstart=20)
new$cluster<-as.factor(new.cluster$cluster)
ggplot(data=new,mapping = aes(x=PC1,y=PC2,color=cluster))+
  geom_point(shape=1)+
  ggtitle("Clusters of employees who left(k=3)")+ 
  theme(plot.title = element_text(hjust = 0.5))
par(mfrow=c(2,3))
hist(hr[,1],main="satisfaction level",ylab=NULL,xlab=NULL,col=c("steelblue"))
hist(hr[,2],main="last evaluation",ylab=NULL,xlab=NULL,col=c("steelblue"))
hist(hr[,3],main="number of projects",ylab=NULL,xlab=NULL,col=c("steelblue"))
hist(hr[,4],main="average monthly hours",ylab=NULL,xlab=NULL,col=c("steelblue"))
hist(hr[,5],main="time spent at companies",ylab=NULL,xlab=NULL,col=c("steelblue"))


library(ggplot2)
library(plyr)
library(dplyr)
library(reshape2)
data$Work_accident <-factor(data$Work_accident,labels=c("NO_ACCIDENT","YES_ACCIDENT"))
data$left <-   factor(data$left, labels =c("NOT LEFT","LEFT"))
data$promotion_last_5years <- factor(data$promotion_last_5year,labels =c("NO_PROMOTION","YES_PROMOTION"))
colnames(data)[colnames(data)=="sales"] <- "department"
data_long <-  melt(data, values = colnames(data_long))
ggplot(data_long,aes(x = value , fill = left)) +  geom_bar()  + facet_wrap(~variable, scales = 'free') + ylab("Frecuency")


data2 <-  melt(data, values = colnames(data[,6:10]))
ggplot(data2[,6:10],aes(x = value , fill = left)) +  geom_bar()  + facet_wrap(~variable, scales = 'free') + ylab("Frecuency")

par(mfrow=c(2,3))

ggplot(data, aes(x=left , fill=data$Work_accident)) + geom_bar() + scale_fill_manual(values=wes_palette(n=3, name="GrandBudapest"))
ggplot(data, aes(x= left, fill=promotion_last_5years)) + geom_bar() + scale_fill_manual(values=wes_palette(n=3, name="GrandBudapest"))
ggplot(data, aes(x= left, fill=department)) + geom_bar() + scale_fill_manual(values=wes_palette(n=3, name="GrandBudapest"))
ggplot(data, aes(x= left, fill=salary)) + geom_bar() + scale_fill_manual(values=wes_palette(n=3, name="GrandBudapest"))