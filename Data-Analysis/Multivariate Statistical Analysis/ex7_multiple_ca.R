setwd("C:/Users/tracy/Desktop/Multivariate Statistical Analysis/作业/作业7/directory")
tea<-read.table("TEA.txt",header=T,sep="\t")
dim(tea)
names(tea)
View(tea)
par(mfrow=c(2,3))
for(i in dim(tea)[2]){
  top<-table(tea[,i])
  lab<-round(100*tmp/(sum(tmp)),1)
  pielabels<-paste(lab,"%",sep="")
  cols<-c("black","grey","green","red")
  title<-paste("question",i,sep="")
  pie(tmp,main=title,col=cols,labels=pielabels,cex=0.8)
  legend("topleft",names(lab),fill=cols,horiz=F,cex=0.5)
    
  
}
top<-table(tea[,1])
lab<-round(100*tmp/(sum(top)),1)
par(mfrow=c(1,1))
library(ca)
install.packages('ggplot2')
library(ggplot2)
help(mjca)
tea.mca<-mjca(tea,lambda="indicator")
names(tea.mca)
tea.mca$factors
tea.mca$levels.n
tea.mca$sv^2
summary(tea.mca)
plot(tea.mca)
points(tea.mca$rowcoord)
#nicer plot
cats<-apply(tea,2,function(x) nlevels(as.factor(x)))
tea.vars<-data.frame(tea.mca$colcoord,variable=rep(names(cats),cats))
tea.obs<-data.frame(tea.mca$rowcoord)
rownames(tea.vars)<-tea.mca$levelnames
ggplot()+
  geom_text(data=tea.vars,aes(x=x1,y=x2,colour=variable,label=rownames(tea.vars)))+
  geom_text(data=tea.obs,aes(x=x1,y=x2,label=rownames(tea.obs)))+
  geom_hline(yintercept=0,colour="grey70")#+
  #geom_yline(xintercept=0,colour="grey70")+
  #title
