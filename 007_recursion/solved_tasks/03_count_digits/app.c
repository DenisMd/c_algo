#include <assert.h>
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

int count_digits(int n)
{
  // n / 10 == 0  <=>  осталась одна цифра (работает и для 0, и для отрицательных:
  // знак при делении отбрасывается вместе с разрядом, -7 / 10 == 0)
  if (n / 10 == 0) {
    return 1;                        // база
  }

  return 1 + count_digits(n / 10);   // шаг: отбрасываем последнюю цифру
}

int main()
{
  int n;

  read_input(&n);

  int result = count_digits(n);
  assert(result >= 1);

  printf("%d\n", result);

  return 0;
}
