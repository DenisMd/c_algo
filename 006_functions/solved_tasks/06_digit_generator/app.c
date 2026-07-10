#include <stdio.h>
#include <stdlib.h>

void read_input(int *d, int *k)
{
  printf("Enter denominator d and count k: ");
  if (scanf("%d %d", d, k) != 2) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
  // d >= 2: только для правильной дроби 1/d = 0.что-то работает деление в столбик
  if (*d < 2 || *k < 1) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
}

int next_digit(int denom)
{
  // Остаток "переживает" вызовы функции: инициализируется один раз,
  // дальше хранит своё значение между вызовами.
  static int remainder = 1;  // числитель дроби 1/denom

  remainder *= 10;
  int digit = remainder / denom;
  remainder %= denom;

  return digit;
}

int main()
{
  int d, k;

  read_input(&d, &k);

  printf("1/%d = 0.", d);
  for (int i = 0; i < k; i++) {
    printf("%d", next_digit(d));
  }
  printf("\n");

  return 0;
}
