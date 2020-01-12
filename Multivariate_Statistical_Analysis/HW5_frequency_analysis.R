setwd("C:/Users/tracy/Desktop/Multivariate Statistical Analysis/作业/作业5/directory")
smoking <- read.table("SMOKING.txt",header=T,row.names = 1)
View(smoking)
S <- as.matrix(smoking[-6,-5])
Total<-margin.table(S)
prop.table(S) #Table of relative frequencies
prop.table(S,1) #Row profiles
prop.table(S,2) #Column profiles
RowNum <- matrix(margin.table(S,1),ncol=1)
RowPro<-prop.table(RowNum)
ColNum<- matrix(margin.table(S,2),nrow=1)
ColPro<-prop.table(ColNum)
TPUI<-RowPro%*%ColPro #Form theoretical proportions under independence
TFUI<-Total*TPUI      #Form theoretical frequencies under independence
matrix(margin.table(TFUI,1),ncol=1)
matrix(margin.table(TFUI,2),nrow=1)
# The following also can obtain the result.
#V1 <- matrix(margin.table(S,1),ncol=1)
#V2 <- matrix(margin.table(S,2),nrow=1)
#E <- V1 %*% V2/sum(S)
AR.matrix<-S/TFUI
