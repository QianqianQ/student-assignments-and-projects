data{
  int<lower=0> N; // number of data points
  vector[N] x; // time
  vector[N] y; // number of drownings 
  real xpred; // input location for prediction
}
parameters{
  real alpha;
  real beta;
  real<lower=0> sigma;
}
transformed parameters{
  vector[N] mu;
  mu=alpha+beta*x;
}
model{
  y~normal(mu,sigma);
}
generated quantities{
  real ypred;
  vector[N] log_lik;
  ypred = normal_rng(alpha+beta*xpred,sigma);
  for(n in 1:N)
    log_lik[n]=normal_lpdf(y[n] | alpha + beta*x[n],sigma);
}