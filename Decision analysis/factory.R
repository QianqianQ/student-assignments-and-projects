library("rstan")
library("ggplot2")
rstan_options(auto_write = TRUE)
options(mc.cores = parallel::detectCores())

# utility function
utility<-function(sold,not_sold){
  P_sold<-sold/(sold+not_sold)
  P_not <- not_sold/(sold+not_sold)
  u <- 100 *P_sold-100*P_not
  return(u)
}

# import and organize data
raw_data<-read.table("factory.txt")
factory_data<-list(N = ncol(raw_data)*nrow(raw_data),
                   K = ncol(raw_data),
                   x = rep(1:ncol(raw_data),nrow(raw_data)),
                   y = c(t(raw_data[,1:ncol(raw_data)]))
)

# Stan
hf_fit<-stan(file="hierarchical_factory.stan",data=factory_data)
hf_result<-extract(hf_fit,permuted=TRUE)

# Calculate the utility of the six machines
U<-c()
for (i in 1:ncol(raw_data)){
  sold <-sum(hf_result$ypred[,i]>=85)
  not_sold<-sum(hf_result$ypred[,i]<85)
  u <-utility(sold,not_sold)
  U<-c(U,u)
}
print(U)

# Calculate the utility of the 7th machine
sold_7<-sum(hf_result$y7_pred>=85)
not_sold_7<-sum(hf_result$y7_pred<85)
u7<-utility(sold_7,not_sold_7)
print(u7)
