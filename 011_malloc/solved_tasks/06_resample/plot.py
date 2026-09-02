#!/usr/bin/env python3
# sudo apt install python3-matplotlib
# sudo chmod +x plot.py
"""Рисует исходный массив и результат ресемплинга на одной сетке.

    ./app < sine.txt | python3 plot.py sine.txt             # GUI-окно (WSLg)
    ./app < sine.txt | python3 plot.py sine.txt out.png     # сохранить в PNG

Результат берётся из вывода app (stdin), исходный массив и m — из входного
файла. Обе кривые кладём на общую ось — сетку исходного массива 0 .. n-1:
j-й выходной отсчёт стоит там же, где его считала программа,
в точке pos = j * (n - 1) / (m - 1).
"""
import sys

if len(sys.argv) < 2:
    sys.exit("usage: ./app < data.txt | python3 plot.py data.txt [out.png]")

data_file = sys.argv[1]
out = sys.argv[2] if len(sys.argv) > 2 else None

# результат из вывода программы; 'Enter n, a, m:' цифр не содержит и отсеется
res = []
for tok in sys.stdin.read().split():
    try:
        res.append(float(tok))
    except ValueError:
        pass

# исходные данные: N, N чисел, M
tokens = open(data_file).read().split()
n = int(tokens[0])
a = [float(t) for t in tokens[1:1 + n]]
m = int(tokens[1 + n])

if len(res) != m:
    sys.exit(f"в выводе {len(res)} чисел, а ожидалось m={m}")

# позиции выходных отсчётов на исходной сетке — та самая формула из задания
pos = [j * (n - 1) / (m - 1) if m > 1 else 0.0 for j in range(m)]

kind = "апсемплинг" if m > n else "прореживание" if m < n else "копия"

try:
    import matplotlib
    matplotlib.use("Agg" if out else "TkAgg")
    import matplotlib.pyplot as plt

    plt.figure(figsize=(11, 5))
    plt.plot(range(n), a, color="#999", linewidth=1.0, zorder=1,
             label=f"исходный массив, n={n}")
    plt.plot(pos, res, color="crimson", linewidth=1.8, zorder=3,
             label=f"после resample, m={m}")
    if m <= 40:  # при большом m маркеры сливаются в сплошную полосу
        plt.plot(pos, res, "o", color="crimson", markersize=5, zorder=4)
    if n <= 40:
        plt.plot(range(n), a, "o", color="#444", markersize=5, zorder=5,
                 markeredgecolor="white")

    plt.xlabel("позиция на исходной сетке (0 .. n-1)")
    plt.ylabel("значение")
    plt.title(f"Линейная интерполяция: n={n} -> m={m} ({kind})")
    plt.margins(y=0.25)  # место сверху, чтобы легенда не легла на данные
    plt.legend(loc="upper right", framealpha=0.9)
    plt.grid(alpha=0.25)

    if out:
        plt.savefig(out, dpi=110)
        print("сохранено:", out)
    else:
        try:
            plt.show()
        except Exception as e:
            plt.savefig("resample.png", dpi=110)
            print(f"нет дисплея ({e}); сохранил в resample.png")
except ImportError:
    print("(matplotlib нет — только текст; для GUI: sudo apt install python3-matplotlib python3-tk)")
    print(f"n={n} -> m={m} ({kind})")
    lo, hi = min(a + res), max(a + res)
    span = (hi - lo) or 1.0
    for j in range(m):
        col = round(40 * (res[j] - lo) / span)
        print(f"pos {pos[j]:7.2f} | {' ' * col}* {res[j]:g}")
