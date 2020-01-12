data {
  int<lower=0> N; // number of data points
  int<lower=0> K; // number of groups
  int<lower=1,upper=K> x[N]; // group indicator
  vector[N] y; // measurements
}
parameters {
  real mu0;             // prior mean
  real<lower=0> sigma0; // prior std
  vector[K] mu;             // group means
  real<lower=0> sigma; // common std
}
model {
  mu~normal(mu0,sigma0);
  y ~ normal(mu[x], sigma);
}
generated quantities {
  real ypred;
  real mu7_pred;
  ypred = normal_rng(mu[6],sigma);
  mu7_pred = normal_rng(mu0,sigma0);
}
