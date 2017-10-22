library("rstan")
library("ggplot2")
rstan_options(auto_write = TRUE)
options(mc.cores = parallel::detectCores())

biossary_data <- list(J=4,
                      x=c(-0.86,-0.30,-0.05,0.73),
                      n=c(5,5,5,5),
                      y=c(0,1,3,5))
biossary_fit<-stan(file="biossary.stan",data=biossary_data,iter=1000,chains=10)
print(biossary_fit)
biossary_result<-extract(biossary_fit)
p = data.frame(alpha=biossary_result$alpha,beta=biossary_result$beta)
ggplot(p,aes(alpha,beta))+geom_point(shape=21, fill="blue", color="darkred")