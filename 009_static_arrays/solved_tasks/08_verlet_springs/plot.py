#!/usr/bin/env python3
"""Рисует эволюцию центральной массы (лог из app) во времени.

    ./app < chain.txt | python3 plot.py            # GUI-окно (WSLg)
    ./app < chain.txt | python3 plot.py trace.png  # сохранить в PNG
"""
import sys

out = sys.argv[1] if len(sys.argv) > 1 else None

# лог = по одному числу на строку; префикс 'Enter n:' не парсится как float
trace = []
for tok in sys.stdin.read().split():
    try:
        trace.append(float(tok))
    except ValueError:
        pass

try:
    import matplotlib
    matplotlib.use("Agg" if out else "TkAgg")
    import matplotlib.pyplot as plt

    plt.figure(figsize=(11, 4.5))
    plt.plot(range(len(trace)), trace, color="crimson", linewidth=1)
    plt.axhline(0, color="#bbb", linewidth=0.7)
    plt.xlabel("шаг")
    plt.ylabel("положение центральной массы")
    plt.title(f"Верле: колебание центра цепочки ({len(trace)} шагов)")

    if out:
        plt.savefig(out, dpi=110)
        print("сохранено:", out)
    else:
        try:
            plt.show()
        except Exception as e:
            plt.savefig("trace.png", dpi=110)
            print(f"нет дисплея ({e}); сохранил в trace.png")
except ImportError:
    print("(matplotlib нет — только текст; для GUI: sudo apt install python3-matplotlib python3-tk)")
    print(f"шагов: {len(trace)}, min={min(trace):.4f}, max={max(trace):.4f}")
