import numpy as np
from scipy import stats
import matplotlib.pyplot as plt
import sinvchi2
import plot_tools

# data
y1 = np.loadtxt("windshieldy1.txt")  
n1 = len(y1)  # The amount of samples
sample_mean1 = np.mean(y1)
sample_variance1 = np.var(y1, ddof=1)

y2 = np.loadtxt("windshieldy2.txt")  
n2 = len(y2)  # The amount of samples
sample_mean2 = np.mean(y2)
sample_variance2 = np.var(y2, ddof=1)

#generate samples
s1 = stats.t.rvs(df=n1-1,loc=sample_mean1,scale=np.sqrt(sample_variance1/n1),size=1000)
s2 = stats.t.rvs(df=n2-1,loc=sample_mean2,scale=np.sqrt(sample_variance2/n2),size=1000)
s_mean_dif = s1 - s2

mean = np.mean(s_mean_dif)
median = np.median(s_mean_dif)
variance = np.var(s_mean_dif,ddof=1)
interval_95_min = np.percentile(s_mean_dif,2.5)
interval_95_max = np.percentile(s_mean_dif,97.5)
print("mean: {:.6f}\nmedian: {:.6f}\nvariance:{:.6f}\n"
	  "The central 95% interval: [{:.6f}, {:.6f}]"
	  .format(mean,median,variance,interval_95_min,interval_95_max))
plt.hist(s_mean_dif)
plt.xlabel(r'$\mu_{d}$')
plt.ylabel('frequency')
plt.title("histogram of 1000 samples")
plt.show()