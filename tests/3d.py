#!/usr/bin/env python3
import subprocess
import random
import math
import time
import matplotlib.pyplot as plt
import numpy as np
from tqdm import tqdm
from mpl_toolkits.mplot3d import Axes3D  # para gráficas 3D
from matplotlib.widgets import CheckButtons

# Variables de configuración
N_MAX = 500
PUSH_SWAP_PATH = "./push_swap"
CHECKER_PATH = "./checker"
TIMEOUT = 5  # tiempo límite en segundos para push_swap

def tests_count(n):
    return (20)
	# Determina el número de tests a ejecutar para un n dado
#	return int(math.gamma(n**(1/5) + 4))

# Listas para almacenar los puntos (para gráficos 3D)
green_n_points = []
green_moves_points = []
green_time_points = []

red_n_points = []
red_moves_points = []
red_time_points = []

for n in tqdm(range(1, N_MAX), desc="Procesando valores de n"):
	t = tests_count(n)
	moves_list = []
	time_list = []
	ok_count = 0
	for _ in tqdm(range(t), desc=f"n = {n}", leave=False):
		# Generar permutación aleatoria de números [0, n)
		nums = random.sample(range(0, n), n)
		args = list(map(str, nums))
		# Ejecutar push_swap con límite de tiempo
		try:
			start = time.time()
			ps = subprocess.run([PUSH_SWAP_PATH] + args, capture_output=True, text=True, timeout=TIMEOUT)
			duration = time.time() - start
			moves_output = ps.stdout.strip()
			count = len(moves_output.splitlines()) if moves_output else 0
		except subprocess.TimeoutExpired:
			duration = TIMEOUT
			count = 0
			moves_output = ""
		# Ejecutar checker para validar la salida, salvo si hubo timeout (o no hubo output)
		if moves_output:
			ck = subprocess.run([CHECKER_PATH] + args, input=moves_output, capture_output=True, text=True)
			res = ck.stdout.strip()
		else:
			res = "KO"
		# Si el checker da OK se graficará en verde, si no, en rojo
		if res == "OK":
			ok_count += 1
			moves_list.append(count)
			time_list.append(duration)
			green_n_points.append(n)
			green_moves_points.append(count)
			green_time_points.append(duration)
		else:
			red_n_points.append(n)
			red_moves_points.append(count)
			red_time_points.append(duration)
	# Mostrar resumen para cada n
	if moves_list:
		avg_moves = sum(moves_list) / len(moves_list)
		mn_moves = min(moves_list)
		mx_moves = max(moves_list)
		avg_time = sum(time_list) / len(time_list)
		mn_time = min(time_list)
		mx_time = max(time_list)
	else:
		avg_moves = mn_moves = mx_moves = 0
		avg_time = mn_time = mx_time = 0
	ok_rate = ok_count / t * 100
	print(f"n = {n:3d} | Tests: {t:3d} | Movimientos: avg {avg_moves:.2f} min {mn_moves} max {mx_moves} | Tiempo: avg {avg_time:.4f}s min {mn_time:.4f}s max {mx_time:.4f}s | OK rate: {ok_rate:.1f}%")

# Calcular regresión lineal solo con los puntos verdes (OK)
if len(green_n_points) > 0:
	green_n_array = np.array(green_n_points)
	green_moves_array = np.array(green_moves_points)
	green_time_array = np.array(green_time_points)
	# Regresión lineal para movimientos vs n
	coeff_moves = np.polyfit(green_n_array, green_moves_array, 1)
	# Regresión lineal para tiempo vs n
	coeff_time = np.polyfit(green_n_array, green_time_array, 1)
	# Generar valores para la línea de regresión
	n_range = np.linspace(green_n_array.min(), green_n_array.max(), 200)
	pred_moves = np.polyval(coeff_moves, n_range)
	pred_time = np.polyval(coeff_time, n_range)
else:
	print("No se obtuvieron puntos verdes para la regresión.")
	n_range = np.linspace(1, N_MAX, 200)
	pred_moves = np.zeros_like(n_range)
	pred_time = np.zeros_like(n_range)

# Crear gráfica 3D
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
scatter_green = ax.scatter(green_n_points, green_moves_points, green_time_points, color="green", s=10, label="OK (checker)")
scatter_red = ax.scatter(red_n_points, red_moves_points, red_time_points, color="red", s=10, label="KO (checker o timeout)")
line_reg = ax.plot(n_range, pred_moves, pred_time, color="blue", linewidth=2, label="Regresión lineal (solo verdes)")[0]

ax.set_xlabel("Número de elementos", fontsize=14)
ax.set_ylabel("Número de movimientos", fontsize=14)
ax.set_zlabel("Tiempo de ejecución (s)", fontsize=14)
ax.set_title("Rendimiento de push_swap", fontsize=16)
ax.legend(fontsize=12)

# Widget interactivo para seleccionar qué series mostrar
rax = plt.axes([0.02, 0.4, 0.15, 0.15])
check = CheckButtons(rax, ['Ver verdes', 'Ver rojos', 'Ver regresión'], [True, True, True])

def func(label):
	if label == 'Show OK':
		visible = not scatter_green.get_visible()
		scatter_green.set_visible(visible)
	elif label == 'Show KO':
		visible = not scatter_red.get_visible()
		scatter_red.set_visible(visible)
	elif label == 'Show regression':
		visible = not line_reg.get_visible()
		line_reg.set_visible(visible)
	plt.draw()

check.on_clicked(func)

plt.tight_layout()
plt.show()
