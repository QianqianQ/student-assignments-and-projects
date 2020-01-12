#a)
center<-function(Y){
  Y-mean(Y)
}
covariance <- function(X){
  Xc <-apply(X,2,center)
  cov1 <- t(Xc)%*%Xc/(nrow(Xc)-1)
  return(cov1)
}
#A <- covariance(X)
#B <- cov(X)
#error <- B-A
#error should close to 0

#b)
sqrtofinv <- function(A){
  eig <- eigen(A)
  d <- eig$values
  d <- (d+abs(d))/2
  d2 <- 1/sqrt(d)
  d2[d==0]<-0
  V <- eig$vectors
  ans <- V%*%diag(d2)%*%t(V)
  return(ans)
}

#c)
Correlation <- function(A){
  corr <- cov2cor(A) 
  #cov2cor scales a covariance matrix 
  #into the corresponding correlation matrix efficiently.
  return(corr)
}
