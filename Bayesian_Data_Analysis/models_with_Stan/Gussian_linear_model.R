library("rstan")
library("ggplot2")
rstan_options(auto_write = TRUE)
options(mc.cores = parallel::detectCores())
# import and organize data
raw_data<-read.table("drowning.txt")
drowning_data<-list(N=nrow(raw_data),
           x=raw_data$V1,
           y=raw_data$V2,
           xpred=2016
)

# fit Stan model
drowning_fit<-stan(file="drowning.stan",data=drowning_data)
drowning_result<-extract(drowning_fit,permuted=TRUE)
beta<-drowning_result$beta
mu<-drowning_result$mu
mu<-as.array(mu)

# show the trend
df_xy<-data.frame(x=drowning_data$x,y=drowning_data$y)

m_50<-c()
m_2p5<-c()
m_97p5<-c()
for(i in 1:length(drowning_data$x)){
  per_50 = quantile(mu[,i],0.5)
  per_2p5=quantile(mu[,i],0.025)
  per_97p5=quantile(mu[,i],0.975)
  m_50<-c(m_50,per_50)
  m_2p5<-c(m_2p5,per_2p5)
  m_97p5<-c(m_97p5,per_97p5)
}
m_50<-as.array(m_50)
m_2p5<-as.array(m_2p5)
m_97p5<-as.array(m_97p5)
df_mu<-data.frame(x=drowning_data$x,y1=m_50,y2=m_2p5,y3=m_97p5)

ggplot(df_xy,aes(df_xy$x))+
  geom_point(aes(y=df_xy$y),color="blue")+
  geom_line(aes(y=df_mu$y1),color="red")+
  geom_line(aes(y=df_mu$y2),linetype="dashed",color="red")+
  geom_line(aes(y=df_mu$y3),linetype="dashed",color="red")+
  labs(title="Trend in the number of people drown",
       x="year",y="number of people")+
  theme(plot.title = element_text(hjust = 0.5))
  
# plot histogram related to beta
beta_data<-data.frame(x=beta)
ggplot(data=beta_data,aes(x=beta_data))+
  geom_histogram(color="darkblue",,fill="lightblue")+
  scale_x_continuous(breaks=seq(-6,0,0.5))+
  labs(title="histogram of the slope",x=expression(beta))+
  theme(plot.title = element_text(hjust = 0.5))
mean(beta)
quantile(beta,c(0.025,0.975))

# plot histogram related to pred_y
ypred<-drowning_result$ypred
pred_y<-data.frame(x=ypred)
ggplot(data=pred_y,aes(x=pred_y))+
geom_histogram(bins=100,binwidth=10,color="darkblue",,fill="lightblue")+
scale_x_continuous(breaks=seq(0,320,20))+
labs(title=expression(paste("histogram of the posterior predictive distribution at ", 
                            tilde(x), "=2016")),x=expression(tilde(y)))+
  theme(plot.title = element_text(hjust = 0.5))
mean(ypred)
