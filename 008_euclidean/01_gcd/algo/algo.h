#ifndef ALGO_H
#define ALGO_H

// ---- Алгоритм Евклида: НОД (наибольший общий делитель) ----

// Идея: gcd(a, b) == gcd(b, a mod b), пока b не станет нулём.
// Работает, потому что любой общий делитель a и b делит и остаток a mod b.

// Итеративная версия (цикл while).
long long gcd(long long a, long long b);

// Рекурсивная версия — та же формула, записанная буквально.
long long gcd_rec(long long a, long long b);

#endif
