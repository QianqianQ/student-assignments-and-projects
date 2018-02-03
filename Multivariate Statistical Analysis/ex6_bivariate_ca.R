setwd("C:/Users/tracy/Desktop/Multivariate Statistical Analysis/作业/作业6/directory")
#install packacges("ca") #run this if you dont have it install
library(ca)
install.packages("ca")
library(ca)
data<-read.table("SCIENCEDOCTORATES.txt",header=T,row.names=1)
dim(data)
SD<-data[-13,-9]
View(SD)
#satistically test if the rows(field of science) and the columns(years) are independent
#Hint:chi-square

#Google multinomial distribution
#(generalized binomial distribution)
help(ca)
help("chisq.test")
#From last week the matrix of expected frequentcies E
v1<-matrix(colSums(SD),nrow=1)
v2<-matrix(rowSums(SD),ncol=1)
#J is number of rows in the frequency table
#K is number of columns in the frequency table
n=sum(SD)
J<-nrow(SD)
K<-ncol(SD)
E<-v2%*%v1/n
W<-0 #W is T in the whitebooard
for(j in 1:J){
   for(k in 1:K){
     W<-W+SD[j,k]-E[j,k]^2/E[j,k]
   }
}
#n_(jk) follow multinomial
#H0:Discipline and Year are independent (in USA)
#H1: discipline and Year are not independent (in USA)
chisq.test(SD)
pchisq(W,df=((J-1)*(K-1)),lower.tail=F)
#Reject H0
#->there is evidence of statistically significant association between the years and the sciences
SD.ca<-ca(SD)
names(SD.ca)
summary(SD.ca)
plot(SD.ca)
names(SD.ca)
#SV=singular values
#for a symmetric matrix, singular values=engenvalues
#package ca uses SVD instead of eigendecompostion
#(SVD sometimes has some computational advantages)
SD.ca$sv
sum(SD.ca$colinertia)
sum(SD.ca$rowinertia)
W/n
sum(SD.ca$sv^2)
#Inertia:T/n in the whiteboard,"total" variation
SD.ca$colinertia
SD.ca$colnames
#Inertia for kth column: Fix k and sum over j
#0.0014121599 =colinertia of Y1970
W2<-0 #W is T in the whitebooard
k2<-3
for(j in 1:J){
  
    W2<-W2+SD[j,k2]-E[j,k2]^2/E[j,k2]
  
}
W2/n
SD.ca$rowinertia
SD.ca$rownames
#The following 3, not relevant here
names(SD.ca)
SD.ca$nd
SD.ca$colsup

SD.ca$N #Original table
#Consider all dimensions
#variables in the "center" are independent
SD.ca$coldist #Distance from the "center" for columns
SD.ca$rowdist
SD.ca$rowcoord #Scaled coordinates
SD.ca$colcoord
#Multiply with the singular values to get the same ones as in summary(SD.ca)
SD.ca$rowcoord[11,]*SD.ca$sv #Anthropology
SD.ca$rownames
names(SD.ca)
#Now get these from margin.table()
sum(SD.ca$rowmass)
SD.ca$colmass
names(SD.ca)
plot(SD.ca,arrows=c(T,T),dim=c(1,2))
#in summary, everything multiplied by 1000
summary(SD.ca)
#qlt=quality of representation(see lecture slides)
dim(SD)
#for the plot , angle>90,repulsion, angle<90. attraction, angle=90,independent
#AR-matrix index <1,>1,=1
#pdf()
#plot
#dev.off
#might not work
install.packages("rgl")
plot3d.ca(SD.ca)
