import numpy as np
import matplotlib.pyplot as plt

plt.close()

data = np.loadtxt("ventsolaire.txt")

# Il y a 7 courbes au total
n = len(data) // 7

plt.figure()

for i in range(7):
    courbe = data[i*n:(i+1)*n]

    x = courbe[:, 0]
    u = courbe[:, 1]

    if i < 4:
        u0 = 3.65 + 0.1*i
    else:
        u0 = 0.003 + 0.001*(i-4)

    plt.plot(x, u, label=f"u0 = {u0}")

plt.xlabel("x")
plt.ylabel("u(x)")
plt.legend()
plt.grid()
plt.show()
