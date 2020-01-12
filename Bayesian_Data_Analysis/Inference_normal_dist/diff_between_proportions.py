import numpy as np
from scipy.stats import beta
import matplotlib.pyplot as plt

# a)
# data
n0 = 674
y0 = 39
n1 = 680
y1 = 22

# prior Beta(1/2,1/2)
a = 1/2
b = 1/2

# posterior distribution for p0,p1 seperately
dist0 = beta(a+y0, b+n0-y0)
dist1 = beta(a+y1, b+n1-y1)

# samples from dist0 and dist1
s0 = dist0.rvs(size=1000)
s1 =dist1.rvs(size=1000)

# generate posterior of odds ratio
oods_ratio = (s1/(1-s1))/(s0/(1-s0))
mean = np.mean(oods_ratio)
median = np.median(oods_ratio)
variance = np.var(oods_ratio,ddof=1)
interval_95_min = np.percentile(oods_ratio,2.5)
interval_95_max = np.percentile(oods_ratio,97.5)
print("mean: {:.6f}\nmedian: {:.6f}\nvariance:{:.6f}\n"
	  "The central 95% interval: [{:.6f}, {:.6f}]"
	  .format(mean,median,variance,interval_95_min,interval_95_max))
plt.hist(oods_ratio)
plt.xlabel('odds ratio')
plt.ylabel('frequency')
plt.title("histogram of 1000 samples")

# b)
# case 1: beta(1,1)
pa1 = 1
pb1 = 1

dist_case10 = beta(pa1+y0, pb1+n0-y0)
dist_case11 = beta(pa1+y1, pb1+n1-y1)

s_case10 = dist_case10.rvs(size=1000)
s_case11 =dist_case11.rvs(size=1000)

oods_ratio1 = (s_case11/(1-s_case11))/(s_case10/(1-s_case10))
mean1 = np.mean(oods_ratio1)
median1= np.median(oods_ratio1)
variance1= np.var(oods_ratio1)
interval_95_min1 = np.percentile(oods_ratio1,2.5)
interval_95_max1 = np.percentile(oods_ratio1,97.5)
print("case1:")
print("mean: {:.6f}\nmedian: {:.6f}\nvariance:{:.6f}\n"
	  "The central 95% interval: [{:.6f}, {:.6f}]"
	  .format(mean1,median1,variance1,interval_95_min1,interval_95_max1))


# case 2: beta(10,10)
pa2 = 10
pb2 = 10

dist_case20 = beta(pa2+y0, pb2+n0-y0)
dist_case21 = beta(pa2+y1, pb2+n1-y1)

s_case20 = dist_case20.rvs(size=1000)
s_case21 =dist_case21.rvs(size=1000)

oods_ratio2 = (s_case21/(1-s_case21))/(s_case20/(1-s_case20))
mean2 = np.mean(oods_ratio2)
median2= np.median(oods_ratio2)
variance2= np.var(oods_ratio2)
interval_95_min2 = np.percentile(oods_ratio2,2.5)
interval_95_max2 = np.percentile(oods_ratio2,97.5)
print("case2:")
print("mean: {:.6f}\nmedian: {:.6f}\nvariance: {:.6f}\n"
	  "The central 95% interval: [{:.6f}, {:.6f}]"
	  .format(mean2,median2,variance2,interval_95_min2,interval_95_max2))

# case 3: beta(100,100)
pa3 = 100
pb3 = 100

dist_case30 = beta(pa3+y0, pb3+n0-y0)
dist_case31 = beta(pa3+y1, pb3+n1-y1)

s_case30 = dist_case30.rvs(size=1000)
s_case31 =dist_case31.rvs(size=1000)

oods_ratio3 = (s_case31/(1-s_case31))/(s_case30/(1-s_case30))
mean3 = np.mean(oods_ratio3)
median3= np.median(oods_ratio3)
variance3= np.var(oods_ratio3)
interval_95_min3 = np.percentile(oods_ratio3,2.5)
interval_95_max3 = np.percentile(oods_ratio3,97.5)
print("case3:")
print("mean: {:.6f}\nmedian: {:.6f}\nvariance: {:.6f}\n"
	  "The central 95% interval: [{:.6f}, {:.6f}]"
	  .format(mean3,median3,variance3,interval_95_min3,interval_95_max3))

# plot the histograms
fig,axes = plt.subplots(nrows=3, ncols=1, figsize=(8, 15))
axes[0].hist(oods_ratio1)
axes[1].hist(oods_ratio2)
axes[2].hist(oods_ratio3)
axes[0].set_title("histogram of oods_ratio")
axes[0].annotate("prior:Beta(1,1)",xy=(1,200))
axes[1].annotate("prior:Beta(10,10)",xy=(1,200))
axes[2].annotate("prior:Beta(100,100)",xy=(1,200))
axes[0].autoscale(axis='x', tight=True)
plt.show()

