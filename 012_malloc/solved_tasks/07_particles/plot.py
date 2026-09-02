#!/usr/bin/env python3
# sudo apt install python3-matplotlib
# sudo chmod +x plot.py
"""Рисует траектории частиц: высоту, фазовый портрет и энергию.

    python3 plot.py trace.txt             # GUI-окно (WSLg)
    python3 plot.py trace.txt out.png     # сохранить в PNG

app печатает только конечное состояние, поэтому траекторию собираем прогонами
самой программы: k = 0, 1, 2, ... шагов — и берём её вывод как точку графика.
Никакой физики здесь не считается, все числа приходят из app.
"""
import subprocess
import sys

if len(sys.argv) < 2:
    sys.exit("usage: python3 plot.py data.txt [out.png]")

data_file = sys.argv[1]
out = sys.argv[2] if len(sys.argv) > 2 else None

# исходные данные: N, N пар (x v), STEPS DT G
tokens = open(data_file).read().split()
n = int(tokens[0])
start = tokens[1:1 + 2 * n]
steps, dt, g = int(tokens[1 + 2 * n]), float(tokens[2 + 2 * n]), float(tokens[3 + 2 * n])

head = "%d\n%s\n" % (n, " ".join(start))


def state_after(k):
    """Состояние после k шагов — из вывода app (две строки: x и v)."""
    r = subprocess.run(["./app"], input=head + f"{k} {dt} {g}\n",
                       capture_output=True, text=True)
    if r.returncode != 0:
        sys.exit(f"app вернул {r.returncode}: {r.stderr.strip()}")
    nums = []
    for tok in r.stdout.split():
        try:
            nums.append(float(tok))
        except ValueError:  # 'Enter n:' цифр не содержит и отсеется
            pass
    return nums[:n], nums[n:2 * n]


xs = [[] for _ in range(n)]  # xs[i][k] — высота i-й частицы после k шагов
vs = [[] for _ in range(n)]
for k in range(steps + 1):
    x, v = state_after(k)
    for i in range(n):
        xs[i].append(x[i])
        vs[i].append(v[i])

t = [k * dt for k in range(steps + 1)]
# энергия на единицу массы: кинетическая + потенциальная (g отрицательное)
energy = [[0.5 * vs[i][k] ** 2 - g * xs[i][k] for k in range(steps + 1)] for i in range(n)]

try:
    import matplotlib
    matplotlib.use("Agg" if out else "TkAgg")
    import matplotlib.pyplot as plt

    fig = plt.figure(figsize=(12, 7))
    gs = fig.add_gridspec(2, 2, height_ratios=[1.4, 1], hspace=0.35, wspace=0.25)
    colors = plt.cm.viridis([i / max(n - 1, 1) * 0.85 for i in range(n)])

    ax = fig.add_subplot(gs[0, :])
    for i in range(n):
        ax.plot(t, xs[i], color=colors[i], linewidth=1.4, label=f"частица {i}")
    ax.axhline(0, color="#333", linewidth=1.2)
    ax.set_xlabel("время, с")
    ax.set_ylabel("высота x")
    ax.set_title(f"Отскоки с потерей 20% скорости за удар (n={n}, dt={dt:g}, g={g:g})")
    ax.grid(alpha=0.25)
    if n <= 6:
        ax.legend(loc="upper right", framealpha=0.9, ncol=n)

    ax = fig.add_subplot(gs[1, 0])
    for i in range(n):
        ax.plot(xs[i], vs[i], color=colors[i], linewidth=1.0)
    ax.axhline(0, color="#bbb", linewidth=0.7)
    ax.axvline(0, color="#bbb", linewidth=0.7)
    ax.set_xlabel("высота x")
    ax.set_ylabel("скорость v")
    ax.set_title("Фазовый портрет: витки стягиваются к покою")
    ax.grid(alpha=0.25)

    ax = fig.add_subplot(gs[1, 1])
    for i in range(n):
        ax.plot(t, energy[i], color=colors[i], linewidth=1.2)
    ax.set_xlabel("время, с")
    ax.set_ylabel("энергия v²/2 + |g|·x")
    ax.set_title("Между ударами постоянна, на ударе падает в 0.8² = 0.64 раза")
    ax.grid(alpha=0.25)

    if out:
        plt.savefig(out, dpi=110)
        print("сохранено:", out)
    else:
        try:
            plt.show()
        except Exception as e:
            plt.savefig("particles.png", dpi=110)
            print(f"нет дисплея ({e}); сохранил в particles.png")
except ImportError:
    print("(matplotlib нет — только текст; для GUI: sudo apt install python3-matplotlib python3-tk)")
    for i in range(n):
        print(f"частица {i}: старт x={xs[i][0]:g}, максимум {max(xs[i]):.4f}, "
              f"конец {xs[i][-1]:.4f}, энергия {energy[i][0]:.3f} -> {energy[i][-1]:.3f}")
