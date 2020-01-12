setwd("C:/Users/tracy/Desktop/Multivariate Statistical Analysis/作业/作业7/directory")
#a)
install.packages("ade4")
library(ade4)
data<-read.table("WG93_full.txt",header=T,sep='\t')
acm.disjonctif(data)

#b)
install.packages("ca")
library(ca)
dim(data)
View(data)
par(mfrow=c(2,3))
for(i in 1:dim(data)[2]){
  
  tmp <- table(data[,i])
  
  lab <- round(100*tmp/sum(tmp),1)
  
  pielabels <- paste(lab,"%",sep="")
  
  cols <- c("black","grey","green","red","blue","yellow")
  
  title <- paste("Question",i,sep=" ")
  pie(tmp, main=title,col=cols,labels=pielabels,cex=1.2)
  
  legend("topleft",names(lab),fill=cols,horiz=F,cex=0.7)
}
par(mfrow=c(1,1))
data.mca <- mjca(data,lambda="indicator")
names(data.mca)
data.mca$factors
data.mca$levels.n
data.mca$sv^2
(data.mca$sv[1]^2 + data.mca$sv[2]^2) / sum(data.mca$sv^2)
summary(data.mca)
plot(data.mca,arrows=c(T,T),map="symmetric")
points(data.mca$rowcoord) 

install.packages("ggplot2")
library(ggplot2)
cats <- apply(data,2, function(x) nlevels(as.factor(x)) )
data.vars <- data.frame(data.mca$colcoord,Variable= rep(names(cats),cats))
data.obs <- data.frame(data.mca$rowcoord)
rownames(data.vars) <- data.mca$levelnames

ggplot()+
  geom_text(data=data.vars,aes(x=X1,y=X2,colour = Variable,label=rownames(data.vars)))+
  geom_hline(yintercept=0,colour="gray70")+
  geom_vline(xintercept=0,colour="gray70")+
  ggtitle("MCA plot")



