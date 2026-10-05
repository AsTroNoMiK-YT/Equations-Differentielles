import numpy as np
import matplotlib.pyplot as plt

plt.close()
data = np.loadtxt("osc.txt")

x = data[:, 0]
y = data[:, 1]
h = data[0, 2]

Wo = 2.0
A = 1
phi = 0
x_theo = np.arange(1,50+h,h)
y_theo = A*np.cos(Wo*x_theo + 0)

# Tracé
plt.figure(figsize=(15, 10))
plt.plot(x, y, 'og',markersize=1,label="Oscillateur numérique")
plt.plot(x_theo,y_theo,'r',markersize=1,alpha=0.5,label="Oscillateur théorique")
plt.xlabel("Axe X")
plt.ylabel("Axe Y")
plt.grid()
plt.legend()
plt.show()
