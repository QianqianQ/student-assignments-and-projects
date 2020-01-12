library("rstan")
library("ggplot2")
library("loo")
rstan_options(auto_write = TRUE)
options(mc.cores = parallel::detectCores())
# import and organize data
raw_data<-read.table("factory.txt")
factory_data<-list(N = ncol(raw_data)*nrow(raw_data),
    K = ncol(raw_data),
    x = rep(1:ncol(raw_data),nrow(raw_data)),
    y = c(t(raw_data[,1:ncol(raw_data)]))
)

# pooled model
pf_fit<-stan(file="pooled_factory.stan",data=factory_data)
pf_result<-extract(pf_fit,permuted=TRUE)
log_lik_pf <- extract_log_lik(pf_fit, parameter_name = 'log_lik')
loo_pf <- loo(log_lik_pf)
print(loo_pf)
k1<-loo_pf$pareto_k
k1_df<-data.frame(x=k1)
loo_pf$elpd_loo
loo_pf$p_loo

# separate model
sf_fit<-stan(file="separate_factory.stan",data=factory_data)
log_lik_sf <- extract_log_lik(sf_fit, parameter_name = 'log_lik')
sf_result<-extract(sf_fit,permuted=TRUE)
loo_sf <- loo(log_lik_sf)
print(loo_sf)
k2<-loo_sf$pareto_k
k2_df<-data.frame(x=k2)
loo_sf$elpd_loo
loo_sf$p_loo

# hierarchical model
hf_fit<-stan(file="hierarchical_factory.stan",data=factory_data)
hf_result<-extract(hf_fit,permuted=TRUE)
log_lik_hf <- extract_log_lik(hf_fit, parameter_name = 'log_lik')
loo_hf <- loo(log_lik_hf)
print(loo_hf)
k3<-loo_hf$pareto_k
k3_df<-data.frame(x=k3)
loo_hf$elpd_loo
loo_hf$p_loo

# plot k-values
p1<-ggplot(data=k1_df,aes(x=k1_df$x))+
  geom_histogram(color="darkblue",,fill="lightblue")+
  labs(title="Pooled model")+
  labs(x="k-value") + 
  theme(plot.title = element_text(hjust = 0.5))+
  xlim(-0.2,1)

p2<-ggplot(data=k2_df,aes(x=k2_df$x))+
  geom_histogram(color="darkblue",,fill="lightblue")+
  labs(title="Separate model")+
  labs(x="k-value") + 
  theme(plot.title = element_text(hjust = 0.5))+
  xlim(-0.2,1)

p3<-ggplot(data=k3_df,aes(x=k3_df$x))+
  geom_histogram(color="darkblue",,fill="lightblue")+
  labs(title="Hierarchical model")+
  labs(x="k-value") + 
  theme(plot.title = element_text(hjust = 0.5))+
  xlim(-0.2,1)
require(gridExtra)
grid.arrange(p1,p2,p3,ncol=3)