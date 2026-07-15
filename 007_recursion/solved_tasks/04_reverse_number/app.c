#include <stdio.h>
#include <stdlib.h>

void read_input(int* n)
{
  printf("Enter n: ");
  if (scanf("%d", n) != 1) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
}

// Вспомогательная функция: acc — уже собранное перевёрнутое число.
int reverse_helper(int n, int acc)
{
  if (n == 0) {
    return acc;                                 // база: разбирать больше нечего
  }
  return reverse_helper(n / 10, acc * 10 + n % 10); // шаг: отрываем последнюю цифру
}

// Публичная функция: запуск рекурсии с «пустым» аккумулятором.
int reverse_number(int n)
{
  return reverse_helper(n, 0);
}

int main()
{
  int n;

  read_input(&n);

  printf("%d\n", reverse_number(n));

  return 0;
}
