# 08 hexview

Глобальный массив `numbers[4]` и способы посмотреть его байты в hex.

```bash
gcc -g app.c -o a.out
./a.out
```

## 1. Через файл (программа пишет dump.bin)

```bash
xxd dump.bin
hexdump -C dump.bin
```

## 2. В самом бинарнике (массив лежит в секции .data)

```bash
objdump -s -j .data a.out
```

## 3. Живая память в gdb

```bash
gdb ./a.out
break main
run
x/16xb numbers   # 16 байт
x/4xw numbers    # 4 слова по 4 байта
```
