import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import multivariate_normal
from scipy.stats import norm

# data
x = np.array([-0.86, -0.30, -0.05, 0.73])
n = np.array([5, 5, 5, 5])
y = np.array([0, 1, 3, 5])

# log posterior distribution with parameter a, b
def log_posterior_distribution(a,b):
    ilogit_abx = 1 / (np.exp(-(a + b * x)) + 1)
    log_p =np.log(np.prod(ilogit_abx**y * (1 - ilogit_abx)**(n - y)))
    return log_p

chains = 10  # number of chains
iterations = 1000  # number of iterations
starting_point =[0,5]  # starting points
a=np.zeros((iterations,chains))  # parameter a
b=np.zeros((iterations,chains))  # parameter b
a[0,0]=starting_point[0]
b[0,0]=starting_point[1]

# Metropolis algorithm
for i in range(iterations):
    for j in range(chains):
        # sample a set of proposal parameters.a~N(a[i-1,j],3),b~n(b[i-1,j],3)
        a_new = norm.rvs(loc=a[i-1,j],scale=np.sqrt(3),size=1) 
        b_new = norm.rvs(loc=b[i-1,j],scale=np.sqrt(3),size=1)
        # calculate the new and the previous one log posterior distributions
        log_p_new = log_posterior_distribution(a_new,b_new)
        log_p_prev = log_posterior_distribution(a[i-1,j],b[i-1,j])
        # generate a random number between 0 and 1
        rand = np.random.uniform(0,1)
        # calculate the ratio of the densities
        # do comparision and set parameters (BDA3 P278)
        if min(np.log(1),log_p_new - log_p_prev)>np.log(rand):
            a[i,j]= a_new
            b[i,j]= b_new
        else:
            a[i,j]=a[i-1,j]
            b[i,j]=b[i-1,j]

# (remove the 200 warm-up samples)
a=a[200:]
b=b[200:]
# scatter plot
plt.figure()
plt.scatter(a,b,s=10,edgecolor='black')  
plt.xlabel(r'$\alpha$')
plt.ylabel(r'$\beta$')
plt.title("Scatter plot with Metropolis algorithm")

# posterior density 
plt.figure()
A = np.linspace(-2, 6, 100)
B = np.linspace(0, 25, 100)
ilogit_abx = 1 / (np.exp(-(A[:,None] + B[:,None,None] * x)) + 1)
p = np.prod(ilogit_abx**y * (1 - ilogit_abx)**(n - y), axis=2)
plt.contourf(p, origin='lower', aspect='auto', 
extent=(A[0], A[-1], B[0], B[-1]))
plt.xlim([-2,6])
plt.ylim([0,25])
plt.ylabel(r'$\beta$')
plt.xlabel(r'$\alpha$')
plt.grid('off')
plt.title('posterior density')

# psrf
def psrf(samples):
    # Calculate means W of the variances
    W = np.mean(np.var(samples,axis=1,ddof=1),axis=0)
    # Calculate variances B (in fact B/n) of the means
    Bpn = np.var(np.mean(samples,axis=1),ddof=1,axis=0)
    B = Bpn*800
    Vh = (800-1)/800*W +Bpn
    R = np.sqrt(Vh/W)
    return R

print("The R of a: {:.6f}".format(psrf(a)))
print("The R of b: {:.6f}".format(psrf(b)))

plt.show()
