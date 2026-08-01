#!/usr/bin/env python3
"""Рисует гистограмму по корзинам — вывод app + исходные данные.

    ./app < data.txt | python3 plot.py data.txt            # GUI-окно (WSLg)
    ./app < data.txt | python3 plot.py data.txt hist.png   # сохранить в PNG

Счётчики корзин читаются из stdin (строки 'k: count'), а границы [min, max]
и ширину берём из data.txt, чтобы подписать ось X в реальных единицах.
"""
import re
import sys

if len(sys.argv) < 2:
    sys.exit("usage: ./app < data.txt | python3 plot.py data.txt [out.png]")

data_file = sys.argv[1]
out = sys.argv[2] if len(sys.argv) > 2 else None

# 1) счётчики корзин из вывода программы
counts = []
for line in sys.stdin:
    m = re.match(r"\s*(\d+)\s*:\s*(\d+)", line)  # 'Enter n:' не совпадёт
    if m:
        counts.append(int(m.group(2)))

# 2) сами данные из входного файла: N, затем N чисел, затем B
tokens = open(data_file).read().split()
n = int(tokens[0])
data = [float(t) for t in tokens[1:1 + n]]
lo, hi = min(data), max(data)
b = len(counts)
width = (hi - lo) / b if hi > lo else 1.0
edges = [lo + k * width for k in range(b + 1)]

try:
    import matplotlib
    matplotlib.use("Agg" if out else "TkAgg")
    import matplotlib.pyplot as plt

    plt.bar(edges[:-1], counts, width=width, align="edge",
            color="steelblue", edgecolor="white", linewidth=0.5)
    plt.xlabel("значение")
    plt.ylabel("сколько попало")
    plt.title(f"Гистограмма: N={n}, B={b}, диапазон [{lo:g}, {hi:g}]")

    if out:
        plt.savefig(out, dpi=110)
        print("сохранено:", out)
    else:
        try:
            plt.show()
        except Exception as e:
            plt.savefig("hist.png", dpi=110)
            print(f"нет дисплея ({e}); сохранил в hist.png")
except ImportError:
    print("(matplotlib нет — рисую текстом; для GUI: sudo apt install python3-matplotlib python3-tk)")
    hi_c = max(counts) or 1
    for k, c in enumerate(counts):
        bar = "#" * round(40 * c / hi_c)
        print(f"[{edges[k]:6.2f}, {edges[k+1]:6.2f}) | {bar} {c}")
