#!/usr/bin/env python3
import subprocess
import random
import math
import matplotlib.pyplot as plt
from tqdm import tqdm

def tests_count(n):
	return int(math.gamma(n**(1/5) + 4))

green_n_points = []
green_moves_points = []

for n in tqdm(range(1, 500), desc="Processing n values"):
	t = tests_count(n)
	moves_ok = []
	ok_count = 0
	for _ in tqdm(range(t), desc=f"n = {n}", leave=False):
		nums = random.sample(range(0, n), n)
		args = list(map(str, nums))
		ps = subprocess.run(["./push_swap"] + args, capture_output=True, text=True)
		moves_output = ps.stdout.strip()
		count = len(moves_output.splitlines()) if moves_output else 0
		ck = subprocess.run(["./checker"] + args, input=moves_output, capture_output=True, text=True)
		res = ck.stdout.strip()
		if res == "OK":
			ok_count += 1
			moves_ok.append(count)
			green_n_points.append(n)
			green_moves_points.append(count)
	if moves_ok:
		avg = sum(moves_ok) / len(moves_ok)
		mn = min(moves_ok)
		mx = max(moves_ok)
	else:
		avg = mn = mx = 0
	ok_rate = ok_count / t * 100
	print(f"n = {n:3d} | Tests: {t:3d} | Avg: {avg:.2f} | Min: {mn} | Max: {mx} | OK rate: {ok_rate:.1f}%")

plt.scatter(green_n_points, green_moves_points, color="green", s=10)
plt.xlabel("Number of elements")
plt.ylabel("Number of moves")
plt.title("push_swap performance (OK tests only)")
plt.grid(True)
plt.tight_layout()
plt.show()
