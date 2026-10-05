import numpy as np
import matplotlib.pyplot as plt

plt.close()

data = np.loadtxt("orbite.txt")

t = data[:, 0]

xs = data[:, 1]
ys = data[:, 2]
zs = data[:, 3]

xt = data[:, 4]
yt = data[:, 5]
zt = data[:, 6]


# Création du graphique 3D
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Trajectoire de la Terre
ax.plot(xt, yt, zt, label="Terre")

# Soleil à l'origine
ax.scatter(xs, ys, zs, color='orange', label="Soleil")

ax.set_xlabel("x [UA]")
ax.set_ylabel("y [UA]")
ax.set_zlabel("z [UA]")

ax.set_title("Orbite de la Terre autour du Soleil")

ax.legend()

plt.show()
