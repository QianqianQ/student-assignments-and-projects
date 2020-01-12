setwd("C:/Users/tracy/Desktop/Multivariate Statistical Analysis/作业/作业8/directory")
dec <- read.table("DECATHLON.txt",header=T,sep="\t")
dim(dec)
View(dec)
X <- as.matrix(dec[,c(13,14)]) 
Y <- as.matrix(dec[,c(3,4,5,6,7,8,9,11,10,12)]) 
XY <- cbind(X,Y)

# (b) Compute sample canonical vectors with corrected scaling
R <- cov(XY) 
R11 <- R[1:2,1:2]  # cov(X)
R22 <- R[3:12,3:12]  # cov(Y)
R21 <- R[3:12,1:2]  # cov(Y,X)
R12 <- R[1:2,3:12]  # cov(X,Y)
R11.inv <- solve(R11)
R22.inv <- solve(R22)
#Non-zero eigenvalues of M1 and M2 are the same
M1 <- R11.inv %*% R12 %*% R22.inv %*% R21
M2 <- R22.inv %*% R21 %*% R11.inv %*% R12
va1 <- eigen(M1)$vectors[,1]
va2 <- eigen(M1)$vectors[,2]
vb1 <- eigen(M2)$vectors[,1]
vb2 <- eigen(M2)$vectors[,2]
# Correct scaling
a1 <- va1/sqrt(va1%*%R11%*%va1)
a2 <- va2/sqrt(va2%*%R11%*%va2)
b1 <- vb1/sqrt(vb1%*%R22%*%vb1)
b2 <- vb2/sqrt(vb2%*%R22%*%vb2)
# The condition for correct scaling is that the following are 1
a1 %*% R11 %*% a1 #Note that here R automatically transposes the first vector
a2 %*% R11 %*% a2
b1 %*% R22 %*% b1
b2 %*% R22 %*% b2
# Note that the following are 0
a1 %*% R11 %*% a2 
b1 %*% R22 %*% b2

#(c)
# Score vectors:
fii1 <- X%*%a1
fii2 <- X%*%a2
eta1 <- Y%*%b1
eta2 <- Y%*%b2
# sample canonical vectors scaled such that the score vectors have variance 1,
# this scaling makes them unique up to sign
var(fii1)
var(fii2)
var(eta1)
var(eta2)
#canonical correlations
#the canonical correlations are also the square roots of the non-zero eigenvalues of M1,M2
round(sqrt(eigen(M1)$values),2)
round(sqrt(eigen(M2)$values),2)

#(d)
#u1= -0.057Height-0.11Weight
#v1=-0.0037R100-0.00071Long_jump+0.0086Shot_put-0.0011High_jump-0.00044R400+0.0030H110
   #+0.0062Dicus_throw-0.0029Javelin-0.0040Pole_vault-0.00075R1500M
plot(fii1,eta1,xlab="u1",ylab="v1",pch="")
text(fii1,eta1,labels=dec$NAME)
# In the plot, x-axis:
# The most left point would be a car with Value=6 (very bad) and Price = 1 (very good)
# --> On the left we have cheap cars that lose value fast (e.g. Wartburg, Trabant)

# The most right point would be a car with Value=1 (very good) and Price = 6 (very bad)
# --> On the right we have cars that are expensive but lose value slowly (e.g. BMW, Jaguar, Ferrari)

# We interpet u1 as the value index of the car, such that high scores on the x-axis indicate that 
# the car is a "worthy" investment. Note also, that Value has almost twice as much weight in the scores
# here (when compared to Price).  

# 6 = very bad, 1 = very good
# v1 <- 0.43Economy - 0.21 Service +0Desing - 0.47Sport - 0.22Safety - 0.4 Easy.h

#y-axis:
# Here, Economy, Sport and Easy handling have the largest weight in this component,
# desing has negligible effect on the scores. 

# The uppermost points have very bad Economy and very good Service, Sport, Safety and Easy.h
# --> The uppermost cars use a lot of fuel but the other qualities are good
# (e.g. BMW, Ferrari)

# The bottommost points have very good economy but the other qualities are very bad
# --> The bottommost cars are economical but other qualities are bad. 

# v1 can be interpreted as a quality index of the car, such that you get a sporty car that is easy 
# to drive in the expense of economy. 

#(e)
# u2 <- - 1.41Price - 1.42 Value 
# v2 <- - 0.46Economy -0.70Service  + 0.06Desing  + 0.00Sport +  0.30Safety  -1.01Easy.h

# Interpret the second component similarly, might be harder (but not impossible)
# since e.g. Ferrari and Wartburg have
# similar profiles. 
plot(fii2,eta2,xlab="u2",ylab="v2",pch="")
text(fii2,eta2,labels=dec$NAME)


