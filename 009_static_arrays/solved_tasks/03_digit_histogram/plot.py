#!/usr/bin/env python3
"""Рисует гистограмму цифр по выводу app.

    ./app < basic.txt | python3 plot.py           # GUI-окно (WSLg)
    ./app < basic.txt | python3 plot.py hist.png   # сохранить в PNG
"""
import re
import sys

# вытаскиваем пары 'd: count'; строку 'Enter n:' regex просто не матчит
counts = [0] * 10
for line in sys.stdin:
    m = re.search(r"(\d)\s*:\s*(\d+)", line)
    if m:
        counts[int(m.group(1))] = int(m.group(2))

out = sys.argv[1] if len(sys.argv) > 1 else None

try:
    import matplotlib
    matplotlib.use("Agg" if out else "TkAgg")  # в файл -> Agg, на экран -> Tk (WSLg)
    import matplotlib.pyplot as plt

    plt.bar(range(10), counts, color="steelblue")
    plt.xticks(range(10))
    plt.xlabel("цифра")
    plt.ylabel("сколько раз")
    plt.title("Гистограмма цифр")

    if out:
        plt.savefig(out)
        print("сохранено:", out)
    else:
        try:
            plt.show()  # окно
        except Exception as e:
            plt.savefig("hist.png")  # нет дисплея — падать не будем
            print(f"нет дисплея ({e}); сохранил в hist.png")
except ImportError:
    # matplotlib нет — рисуем текстом, чтобы не падать
    print("(matplotlib нет — рисую текстом; для GUI: sudo apt install python3-matplotlib python3-tk)")
    for d, c in enumerate(counts):
        print(f"{d} | {'#' * c} {c}")
