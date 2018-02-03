import numpy as np
from scipy import stats
import matplotlib.pyplot as plt
import sinvchi2
import os
# data
print(os.getcwd())
y = np.loadtxt("windshieldy1.txt")  
n = len(y)  # The amount of samples
sample_mean = np.mean(y)
sample_variance = np.var(y, ddof=1)

# set random number generator with seed
rng = np.random.RandomState(seed=0)
# factorize the joint posterior p(mu,sigma2|y) to p(sigma2|y)p(mu|sigma2,y)
# sample from the joint posterior using this factorization

# sample from p(sigma2|y)
sigma2 = sinvchi2.rvs(n-1, sample_variance, size=1000, random_state=rng)
# sample from p(mu|sigma2,y) 
mu = sample_mean + np.sqrt(sigma2/n)*rng.randn(*sigma2.shape)
# display sigma instead of sigma2
sigma = np.sqrt(sigma2)
# sample from the predictive distribution p(ynew|y)
# for each sample of (mu, sigma)
ynew = rng.randn(*mu.shape)*sigma + mu

# for mu compute the density in these points
t1 = np.linspace(12, 18, 1000) 
#for sigma compute the density in these points
t2 = np.linspace(1,5,1000)
# for ynew compute the density in these points
xynew = np.linspace(7,23,1000)

# compute the exact marginal density for mu
mu_pm = stats.t.pdf((t1-sample_mean)/np.sqrt(sample_variance/n), n-1)/np.sqrt(sample_variance/n)
# mu_pm = stats.t.pdf(t1, df=(n-1), loc=sample_mean,  scale=np.sqrt(sample_variance/n))
mu_mean = stats.t.mean(df=n-1, loc=sample_mean, scale=np.sqrt(sample_variance/n))
mu_median = stats.t.median(df=n-1, loc=sample_mean, scale=np.sqrt(sample_variance/n))
mu_variance = stats.t.var(df=n-1, loc=sample_mean, scale=np.sqrt(sample_variance/n))
print("For mu:")
print("mean: {:.6f}, median:{:.6f}, variance: {:.6f}"
	.format(mu_mean,mu_median,mu_variance))
# 95% interval
interval_95 = stats.t.interval(0.95, df=n-1, loc=sample_mean, scale=np.sqrt(sample_variance/n))
point_min = stats.t.ppf(0.025,df=n-1, loc=sample_mean, scale=np.sqrt(sample_variance/n))
point_max = stats.t.ppf(0.975,df=n-1, loc=sample_mean, scale=np.sqrt(sample_variance/n))
print("The central 95% interval:[{:.6f},{:.6f}]".format(point_min,point_max))
x_95_idx = (t1 > point_min) & (t1 < point_max)

plt.plot(t1, mu_pm)
plt.xlabel(r'$\mu$')
plt.fill_between(t1[x_95_idx], mu_pm[x_95_idx], color='0.85')
plt.title("marginal density of " r'$\mu$')

# b)
p_new = stats.t.pdf((xynew-sample_mean)/np.sqrt(sample_variance*(1+1/n)), n-1) / np.sqrt(sample_variance*(1+1/n))

y_mean = stats.t.mean(df=n-1,loc=sample_mean,scale=np.sqrt(sample_variance*(1+1/n)))
y_median = stats.t.median(df=n-1,loc=sample_mean,scale=np.sqrt(sample_variance*(1+1/n)))
y_variance = stats.t.var(df=n-1,loc=sample_mean,scale=np.sqrt(sample_variance*(1+1/n)))
print("For y:")
print("mean: {:.6f}, median:{:.6f}, variance: {:.6f}"
	.format(y_mean,y_median,y_variance))
interval2_95 = stats.t.interval(0.95, df=n-1,loc=sample_mean,scale=np.sqrt(sample_variance*(1+1/n)))
point2_min = stats.t.ppf(0.025,df=n-1,loc=sample_mean,scale=np.sqrt(sample_variance*(1+1/n)))
point2_max = stats.t.ppf(0.975,df=n-1,loc=sample_mean,scale=np.sqrt(sample_variance*(1+1/n)))
print("The central 95% interval:[{:.6f},{:.6f}]".format(point2_min,point2_max))
x_95_idx2 = (xynew > point2_min) & (xynew < point2_max)
plt.figure()
plt.plot(xynew,p_new)
plt.xlabel(r'$\tilde{y}$')
plt.fill_between(xynew[x_95_idx2], p_new[x_95_idx2], color='0.85')
plt.title("posterior predictive distribution")
plt.show()