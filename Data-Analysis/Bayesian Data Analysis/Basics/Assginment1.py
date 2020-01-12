import numpy as np
from scipy.stats import beta
import matplotlib.pyplot as plt

# a)
mean = 0.2
var = 0.01
a = mean*((mean*(1-mean)/var)-1)
b = a*(1-mean)/mean

x = np.arange(0.0, 1.0, 0.001)
y = beta.pdf(x, a, b)

plt.figure()
plt.plot(x, y)
plt.xlabel('x')
plt.ylabel('Beta(x,a,b)')
plt.title("density function of Beta-distribution")
plt.grid(True)


# b)
samples = beta.rvs(a, b, size=1000)
plt.figure()
plt.hist(samples, 20)
plt.xlim([0, 1])
plt.xlabel('x')
plt.ylabel('frequency')
plt.title("histogram of 1000 samples")


# c)
sample_mean = np.mean(samples)
sample_var = np.var(samples, ddof=1)
beta_mean, beta_var = beta.stats(a, b, moments="mv")
# beta_mean = a/(a+b)
# beta_var = (a*b)/(((a+b)**2)*(a+b+1))
print("sample mean = %.6f, "
      "sample variance = %.6f"
      % (sample_mean, sample_var))
print("true mean = %.6f, "
      "true variance = %.6f"
      % (beta_mean, beta_var))

# d)
cp95_interval = np.percentile(samples, [2.5, 97.5])
print("The central 95%-intercal:" 
      " {}".format(cp95_interval))

plt.show()
