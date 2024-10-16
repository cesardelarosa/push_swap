import subprocess
import numpy as np
import matplotlib.pyplot as plt

def run_push_swap(elements):
	cmd = ['./push_swap'] + list(map(str, elements))
	try:
		output = subprocess.check_output(cmd, text=True).strip()
		return len(output.split())
	except subprocess.CalledProcessError:
		return float('inf')  # Si algo falla, retornamos infinito para evitar problemas

def test_push_swap(size, trials):
	ops = []
	for _ in range(trials):
		elements = np.random.permutation(size)
		ops.append(run_push_swap(elements))
	return np.array(ops)

def main():
	max_size = 500
	step_size = 1
	sizes = range(1, max_size + 1, step_size)  # De 10 a 500, de 5 en 5

	min_ops = []
	max_ops = []
	avg_ops = []

	for size in sizes:
		trials_per_size = 100  # Aumenta el número de pruebas a medida que aumenta el tamaño
		print(f'Testing size {size} with {trials_per_size} trials...')
		operations = test_push_swap(size, trials_per_size)
		min_ops.append(np.min(operations))
		max_ops.append(np.max(operations))
		avg_ops.append(np.mean(operations))
	
	plt.figure(figsize=(10, 6))
	plt.plot(sizes, min_ops, label='Mínimo', color='green')
	plt.plot(sizes, max_ops, label='Máximo', color='red')
	plt.plot(sizes, avg_ops, label='Media', color='blue')
	plt.xlabel('Número de elementos')
	plt.ylabel('Número de operaciones')
	plt.title('Análisis de operaciones de push_swap (de 5 en 5)')
	plt.legend()
	plt.grid(True)
	plt.savefig('push_swap_analysis_step5.png')
	plt.show()

if __name__ == '__main__':
	main()
