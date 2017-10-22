
data{
  int<lower=0> J; // number of doses
  vector[J] x; // values of doses
  int<lower=0> n[J]; // number of animals
  int <lower=0> y[J]; // number of deaths
  }
parameters{
  real alpha;
  real beta;
}
transformed parameters{
  vector[J] logits;
  logits = alpha + beta*x; // Link function
}
model{
  y~binomial_logit(n,logits);
}
