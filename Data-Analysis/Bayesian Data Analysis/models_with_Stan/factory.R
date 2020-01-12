library("rstan")
library("ggplot2")
rstan_options(auto_write = TRUE)
options(mc.cores = parallel::detectCores())
# import and organize data
raw_data<-read.table("factory.txt")
factory_data<-list(N = ncol(raw_data)*nrow(raw_data),
    K = ncol(raw_data),
    x = rep(1:ncol(raw_data),nrow(raw_data)),
    y = c(t(raw_data[,1:ncol(raw_data)]))
)

# separate model
sf_fit<-stan(file="separate_factory.stan",data=factory_data)
sf_result<-extract(sf_fit,permuted=TRUE)

# mu
mu<-sf_result$mu
mu_df<-data.frame(x=mu)
ggplot(data=mu_df,aes(x=mu_df$x.6))+
  geom_histogram(color="darkblue",,fill="lightblue",bins=50)+
  scale_x_continuous(breaks=seq(0,200,20))+
  labs(title=expression(paste("histogram of the ",
                              mu[6],"|",y[6])),x=expression(mu[6]))+
  theme(plot.title = element_text(hjust = 0.5))
mean(mu_df$x.6)
quantile(mu,c(0.025,0.975))

# ypred
ypred<-sf_result$ypred
pred_y<-data.frame(x=ypred)
ggplot(data=pred_y,aes(x=pred_y))+
  geom_histogram(color="darkblue",,fill="lightblue",bins=50)+
  scale_x_continuous(breaks=seq(-100,300,50))+
  labs(title=expression(paste("histogram of the ",
                              tilde(y)[6],"|",y[6])),x=expression(tilde(y)[6]))+
  theme(plot.title = element_text(hjust = 0.5))
mean(ypred)
quantile(ypred,c(0.025,0.975))


# pooled model
pf_fit<-stan(file="pooled_factory.stan",data=factory_data)
pf_result<-extract(pf_fit,permuted=TRUE)

# mu
mu<-pf_result$mu
mu_df<-data.frame(x=mu)
ggplot(data=mu_df,aes(x=mu_df))+
  geom_histogram(color="darkblue",,fill="lightblue",bins=50)+
  scale_x_continuous(breaks=seq(0,200,20))+
  labs(title=expression(paste("histogram of the ",
                              mu[6],"|",y)),x=expression(mu[6]))+
  theme(plot.title = element_text(hjust = 0.5))
mean(mu_df$x)
quantile(mu,c(0.025,0.975))

# ypred
ypred<-pf_result$ypred
pred_y<-data.frame(x=ypred)
ggplot(data=pred_y,aes(x=pred_y))+
  geom_histogram(color="darkblue",,fill="lightblue",bins=50)+
  scale_x_continuous(breaks=seq(-100,300,50))+
  labs(title=expression(paste("histogram of the ",
                              tilde(y)[6],"|",y)),x=expression(tilde(y)[6]))+
  theme(plot.title = element_text(hjust = 0.5))
mean(ypred)
quantile(ypred,c(0.025,0.975))

# hierarchical model
hf_fit<-stan(file="hierarchical_factory.stan",data=factory_data)
hf_result<-extract(hf_fit,permuted=TRUE)

# mu
mu<-hf_result$mu
mu_df<-data.frame(x=mu)
ggplot(data=mu_df,aes(x=mu_df$x.6))+
  geom_histogram(color="darkblue",,fill="lightblue",bins=50)+
  scale_x_continuous(breaks=seq(0,200,20))+
  labs(title=expression(paste("histogram of the ",
                              mu[6],"|",y[6])),x=expression(mu[6]))+
  theme(plot.title = element_text(hjust = 0.5))
mean(mu_df$x.6)
quantile(mu_df$x.6,c(0.025,0.975))

# ypred
ypred<-hf_result$ypred
pred_y<-data.frame(x=ypred)
ggplot(data=pred_y,aes(x=pred_y))+
  geom_histogram(color="darkblue",,fill="lightblue",bins=50)+
  scale_x_continuous(breaks=seq(-100,300,50))+
  labs(title=expression(paste("histogram of the ",
                              tilde(y)[6],"|",y[6])),x=expression(tilde(y)[6]))+
  theme(plot.title = element_text(hjust = 0.5))
mean(ypred)
quantile(ypred,c(0.025,0.975))

# the 7th machine
mu7_pred<-hf_result$mu7_pred
pred_mu7<-data.frame(x=mu7_pred)
ggplot(data=pred_mu7,aes(x=pred_mu7))+
  geom_histogram(color="darkblue",,fill="lightblue",bins=50)+
  scale_x_continuous(breaks=seq(-100,300,50))+
  labs(title=expression(paste("histogram of the ",
                              mu[7],"|",y)),x=expression(mu[7]))+
  theme(plot.title = element_text(hjust = 0.5))
mean(mu7_pred)
quantile(mu7_pred,c(0.025,0.975))



