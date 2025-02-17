#!/usr/bin/env python3
"""
Script para evaluar el rendimiento de push_swap en casos concretos:
n = 2, 3, 5, 100 y 500.

Para cada n, se generan varias pruebas (la cantidad se calcula con la función gamma)
y se comprueba que la secuencia de movimientos devuelta por push_swap sea correcta.
Solo se consideran los tests que resultan en "OK" para la gráfica.
"""

import subprocess
import random
import math
import matplotlib.pyplot as plt
from tqdm import tqdm

# Valores específicos de n a probar
N_VALUES = [2, 3, 5, 100, 500]

def tests_count(n):
    """
    Calcula la cantidad de pruebas a realizar para un valor de n.
    Se utiliza la función gamma para determinar la cantidad.
    """
    return int(math.gamma(n ** (1/5) + 4))

def run_tests_for_n(n):
    """
    Ejecuta las pruebas para un valor específico de n.
    
    Retorna:
        - stats: diccionario con estadísticas (cantidad de tests, promedio, mínimo, máximo y tasa OK)
        - points: lista de tuplas (n, cantidad de movimientos) para cada test OK, para graficar.
    """
    total_tests = tests_count(n)
    moves_ok = []
    ok_count = 0

    for _ in tqdm(range(total_tests), desc=f"Pruebas para n = {n}", leave=False):
        # Generar una permutación aleatoria de números de 0 a n-1
        numbers = random.sample(range(n), n)
        args = list(map(str, numbers))

        # Ejecutar push_swap
        ps = subprocess.run(["./push_swap"] + args, capture_output=True, text=True)
        moves_output = ps.stdout.strip()
        move_count = len(moves_output.splitlines()) if moves_output else 0

        # Ejecutar checker para validar la secuencia de movimientos
        ck = subprocess.run(["./checker"] + args, input=moves_output, capture_output=True, text=True)
        result = ck.stdout.strip()

        if result == "OK":
            ok_count += 1
            moves_ok.append(move_count)

    # Calcular estadísticas
    avg_moves = sum(moves_ok) / len(moves_ok) if moves_ok else 0
    min_moves = min(moves_ok) if moves_ok else 0
    max_moves = max(moves_ok) if moves_ok else 0
    ok_rate = ok_count / total_tests * 100

    stats = {
        "n": n,
        "tests": total_tests,
        "avg": avg_moves,
        "min": min_moves,
        "max": max_moves,
        "ok_rate": ok_rate
    }
    points = [(n, count) for count in moves_ok]

    return stats, points

def main():
    all_points = []

    print("Iniciando pruebas con valores específicos de n:")
    for n in tqdm(N_VALUES, desc="Procesando valores de n"):
        stats, points = run_tests_for_n(n)
        all_points.extend(points)
        print(f"n = {stats['n']:3d} | Tests: {stats['tests']:3d} | Avg: {stats['avg']:.2f} | "
              f"Min: {stats['min']} | Max: {stats['max']} | OK rate: {stats['ok_rate']:.1f}%")

    # Preparar datos para la gráfica
    if all_points:
        n_vals, moves_vals = zip(*all_points)
    else:
        n_vals, moves_vals = [], []

    plt.figure(figsize=(8, 6))
    plt.scatter(n_vals, moves_vals, color="green", s=40, alpha=0.7)
    plt.xlabel("Número de elementos", fontsize=12)
    plt.ylabel("Cantidad de movimientos", fontsize=12)
    plt.title("Rendimiento de push_swap (solo pruebas OK)", fontsize=14)
    plt.grid(True, linestyle="--", alpha=0.5)
    plt.tight_layout()
    plt.show()

if __name__ == '__main__':
    main()
