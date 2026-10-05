import numpy as np
import matplotlib.pyplot as plt

plt.close()
# Lecture du fichier
data = np.loadtxt("erreurs.txt")

h = data[:, 0]
err_euler = data[:, 1]
err_heun = data[:, 2]
err_rk4 = data[:, 3]

# Tracé
plt.loglog(h, err_euler, 'o-', label="Euler")
plt.loglog(h, err_heun, 's-', label="Heun")
plt.loglog(h, err_rk4, '^-', label="RK4")

plt.xlabel("Pas h")
plt.ylabel("Erreur")
plt.title("Erreur en fonction du pas h")
plt.grid(True, which="both")
plt.legend()

plt.show()
