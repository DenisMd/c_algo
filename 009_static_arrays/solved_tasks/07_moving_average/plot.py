#!/usr/bin/env python3
# sudo apt install python3-matplotlib
# sudo chmod +x plot.py
"""Рисует цену, скользящее среднее и метки «золотого креста».

    ./app < aapl.txt | python3 plot.py aapl.txt            # GUI-окно (WSLg)
    ./app < aapl.txt | python3 plot.py aapl.txt out.png    # сохранить в PNG

Дни-сигналы берутся из вывода app (stdin), а цены и окно w — из входного файла.
Линию SMA считаем здесь же, чтобы показать её вместе с ценой.
"""
import sys

if len(sys.argv) < 2:
    sys.exit("usage: ./app < data.txt | python3 plot.py data.txt [out.png]")

data_file = sys.argv[1]
out = sys.argv[2] if len(sys.argv) > 2 else None

# дни-сигналы из вывода программы: первое число — их количество, дальше индексы
nums = [int(t) for t in sys.stdin.read().split() if t.lstrip("-").isdigit()]
cnt = nums[0] if nums else 0
signal_days = nums[1:1 + cnt]

# данные из входного файла: N, N цен, w
tokens = open(data_file).read().split()
n = int(tokens[0])
price = [float(t) for t in tokens[1:1 + n]]
w = int(tokens[1 + n])

# SMA скользящей суммой; для первых w-1 дней — None (разрыв в линии)
sma = [None] * n
s = 0.0
for i in range(n):
    s += price[i]
    if i >= w:
        s -= price[i - w]
    if i >= w - 1:
        sma[i] = s / w

try:
    import matplotlib
    matplotlib.use("Agg" if out else "TkAgg")
    import matplotlib.pyplot as plt

    x = range(n)
    plt.figure(figsize=(11, 5))
    plt.plot(x, price, color="#888", linewidth=1, label="цена")
    plt.plot(x, sma, color="steelblue", linewidth=1.8, label=f"SMA-{w}")
    plt.scatter(signal_days, [price[d] for d in signal_days],
                marker="^", color="green", s=70, zorder=3,
                label=f"крест снизу вверх ({cnt})")
    plt.xlabel("день")
    plt.ylabel("цена")
    plt.title(f"Цена, MA-{w} и бычьи пересечения (N={n})")
    plt.legend()

    if out:
        plt.savefig(out, dpi=110)
        print("сохранено:", out)
    else:
        try:
            plt.show()
        except Exception as e:
            plt.savefig("sma.png", dpi=110)
            print(f"нет дисплея ({e}); сохранил в sma.png")
except ImportError:
    print("(matplotlib нет — только текст; для GUI: sudo apt install python3-matplotlib python3-tk)")
    print(f"N={n}, окно w={w}, сигналов: {cnt}")
    print("дни:", " ".join(map(str, signal_days)))
