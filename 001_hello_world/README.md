# 001_hello_world

## 1. Компиляция

```bash
gcc app.c -o app
```

Собирает исполняемый файл `app`.

## 2. Компиляция с отладочной информацией

```bash
gcc -g app.c -o app
```

Добавляет символы отладки для `gdb`.

## 3. Препроцессинг

```bash
gcc -E app.c -o app.i
```

Раскрывает `#include` и макросы, результат в `app.i`.

## 4. Ассемблер x86

```bash
gcc -S -masm=intel app.c -o app.s
```

Генерирует исходный код на ассемблере в `app.s` (синтаксис Intel).

## 5. Объектный файл

```bash
gcc -c app.c -o app.o
objdump -d app.o
readelf -s app.o
```

`gcc -c` — компиляция без линковки.  
`objdump -d` — дизассемблирование секций кода.  
`readelf -s` — таблица символов.

## 6. Динамические библиотеки

```bash
gcc app.c -o app
ldd app
```

`ldd` — список `.so`, которые подгружаются при запуске.
