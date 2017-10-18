import numpy as np
from scipy.stats import beta
import matplotlib.pyplot as plt


# Read data from the file
file = open("algae.txt", 'r')
y = 0  # y represents the amount of sites where algae present
n = 0  # N represents total observations
for line in file:
    for char in line:
        if char == '1':
            y += 1
            n += 1
        if char == '0':
            n += 1

print("y = {}, n={}".format(y, n))

# Beta(2,10) prior for pi
a = 2
b = 10

# Posterior distribution Beta(a+y,b+n-y)
dist = beta(a+y, b+n-y)
x = np.arange(0.05, 0.3, 0.001)
pd = dist.pdf(x)
plt.figure()
plt.plot(x, pd)
plt.autoscale(axis='x', tight=True)
plt.xlabel(r'$\pi$')
plt.title("posterior "  r'$p(\pi|y,n)$')

# a)
mean = dist.mean()
median = dist.median()
variance = dist.var()
# mean = (a+y)/(a+b+n)
# variance = ((mean*(1-mean))/(a+b+n+1))
print("mean = {:.6f}\n"
      "median = {:.6f}\n"
      "variance = {:.6f}".format(mean, median, variance))

# find the points in y that are between 2.5% and 97.5% quantile
x_95_idx = (x > dist.ppf(0.025)) & (x < dist.ppf(0.975))
print("The central 95\% interval: [{:.6f},{:.6f}]"
      .format(dist.ppf(0.025), dist.ppf(0.975)))
plt.fill_between(x[x_95_idx], pd[x_95_idx], color='0.85')
plt.text(dist.median(), 8, "95%", horizontalalignment='center')

# b)
smaller_than_20percent = dist.cdf(0.2)
print("The probability that pi"
      " is smaller than 0.2: {:.6f}\n"
      .format(smaller_than_20percent))

# d)
# compare 5 cases
# prior distribution: Beta(0.161*n, (1-0.161)*n)
# for n = 6, 18, 54, 162, 486
prior_a = np.array([0.161*(6*3**i) for i in range(5)])
prior_b = np.array([(1-0.161)*(6*3**i) for i in range(5)])

# corresponding posteriors with y,n
posterior_a = prior_a + y
posterior_b = prior_b + n - y

# calculate prior and posterior densities
prior_pd = beta.pdf(x, prior_a[:, np.newaxis], prior_b[:, np.newaxis])
posterior_pd = beta.pdf(x, posterior_a[:, np.newaxis],
                        posterior_b[:, np.newaxis])

# plot 5 subplots
fig, axes = plt.subplots(nrows=5, ncols=1, figsize=(8, 15))
for i, ax in enumerate(axes):
    post1 = ax.plot(x, pd, color='orange',
                    linewidth=3, label="posterior with beta(2,10) prior")
    prior = ax.plot(x, prior_pd[i], 'k:', label="prior")
    post2 = ax.plot(x, posterior_pd[i], color='k',
                    dashes=(6, 8), label="posterior")
    ax.annotate(r'$\alpha/(\alpha+\beta)=0.161, \quad '
                r'\alpha+\beta={}$'.format(6*3**i), xy=(0.2, 15))
    box = ax.get_position()
    ax.set_position([box.x0, box.y0, box.width * 0.8, box.height])

axes[0].autoscale(axis='x', tight=True)
plt.legend(loc='center left', bbox_to_anchor=(1, 5))


for i in range(5):
    print("prior: a={},b={}".format(prior_a[i], prior_b[i]))
    print("posterior: a={},b={}".
          format(posterior_a[i], posterior_b[i]))
    dist = beta(posterior_a[i], posterior_b[i])
    mean = dist.mean()
    median = dist.median()
    variance = dist.var()
    print("mean ={:.6f}, median={:.6f}, "
          "variance={:.6f}".format(mean, median, variance))
    x_95_idx = (x > dist.ppf(0.025)) & (x < dist.ppf(0.975))
    print("The central 95\% interval: "
          "[{:.6f},{:.6f}]\n".
          format(dist.ppf(0.025), dist.ppf(0.975)))

plt.show()
