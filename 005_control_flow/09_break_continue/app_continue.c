#include <stdio.h>

int main()
{
  int i;

  for (i = 1; i < 20; i++) {
    // Пропускаем чётные числа
    if (i % 2 == 0) {
      continue;  // переходим к следующей итерации
    }

    // Выводим только нечётные числа
    printf("%d ", i);
  }

  printf("\nLoop ended. i = %d\n", i);
  return 0;
}