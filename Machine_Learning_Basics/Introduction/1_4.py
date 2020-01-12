import numpy as np 
import matplotlib.pyplot as plt 

N = 2
ind = np.arange(N)
B_0 = (0,2)
B_1 = (2,0)
p1 = plt.bar(ind,B_0,width=0.5)
p2 = plt.bar(ind,B_1,width=0.5)
plt.xticks(ind,('0','1'))
plt.yticks(np.arange(0,3,1))
plt.xlabel("C")
plt.ylabel("count")
plt.legend((p1[0],p2[0]),('B-0','B-1'),bbox_to_anchor=(0.85, 1.15), loc=2, borderaxespad=0.)


plt.figure()
A_0 = (0,0)
A_1 = (2,2)
p3 = plt.bar(ind,A_0,width=0.5)
p4 = plt.bar(ind,A_1,width=0.5)
plt.xticks(ind,('0','1'))
plt.yticks(np.arange(0,3,1))
plt.xlabel("C")
plt.ylabel("count")
plt.legend((p3[0],p4[0]),('A-0','A-1'),bbox_to_anchor=(0.85, 1.15), loc=2, borderaxespad=0.)

plt.show()