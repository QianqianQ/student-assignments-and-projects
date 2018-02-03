library(RColorBrewer)
coul = brewer.pal(3, "Pastel2") 
B_C<-matrix(c(0,2,2,0),nrow=2)
colnames(B_C)=c("0","1")
rownames(B_C)=c("0","1")
barplot(B_C,col=coul,border="white",xlab="C")


