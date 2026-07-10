#include <stdio.h>

// Каждая функция вызывает следующую -> кадры (frames) складываются в стек:
// main -> first -> second -> third
// Пока third не вернётся, все три кадра "висят" в памяти один над другим.

int third(int x)
{
    int local = x * 2; // локальная переменная в кадре third
    printf("  third:  x=%d, local=%d\n", x, local);
    // Поставь breakpoint на строку ниже и в gdb набери: bt
    return local;
}

int second(int x)
{
    int local = x + 100; // своя копия local, в отдельном кадре
    printf(" second:  x=%d, local=%d\n", x, local);
    return third(local);
}

int first(int x)
{
    int local = x + 10; // ещё одна независимая local
    printf("first:   x=%d, local=%d\n", x, local);
    return second(local);
}

int main()
{
    int result = first(1);
    printf("result = %d\n", result);
    return 0;
}
