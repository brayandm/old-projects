from matplotlib import pyplot as plt
import numpy as np
import sys
import os

names = []
cants = []

for i in range(1,len(sys.argv),2):
	names.append(sys.argv[i])
	cants.append(int(sys.argv[i+1]))

fig=plt.figure()

ax=fig.add_axes([0,0,1,1])

ax.axis('equal')

ax.pie(cants, labels=names,autopct=lambda p:f'{(round(p*sum(cants)/100)) :.0f} residentes')

plt.show()