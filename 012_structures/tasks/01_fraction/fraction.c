#include "fraction.h"

#include <stdio.h>

// TODO: вспомогательный НОД со static (алгоритм Евклида, урок 008)

struct fraction fraction_reduce(struct fraction f)
{
    // TODO: поделить числитель и знаменатель на их НОД,
    //       знаменатель оставить положительным, минус - в числителе
    return f;
}

struct fraction fraction_add(struct fraction a, struct fraction b)
{
    // TODO: общий знаменатель a.den * b.den, результат сократить
    struct fraction sum = {0, 1};
    return sum;
}

struct fraction fraction_mul(struct fraction a, struct fraction b)
{
    // TODO: перемножить числители и знаменатели, результат сократить
    struct fraction product = {0, 1};
    return product;
}

void fraction_print(struct fraction f)
{
    // TODO: напечатать "num/den", а при den == 1 - только числитель
}
