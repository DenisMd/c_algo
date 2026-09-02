#include <stdbool.h>
#include <stdio.h>

#define ARR_SIZE 7

void swap(int* a, int* b)  // без указателей функция меняла бы только свои копии
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

// return занят под статус, поэтому результаты отдаём через указатели
bool min_max(const int* arr, size_t n, int* min, int* max)
{
  if (arr == NULL || n == 0) {
    return false;  // считать нечего, min/max не трогаем
  }

  *min = arr[0];
  *max = arr[0];

  for (size_t i = 1; i < n; i++) {
    if (arr[i] < *min) *min = arr[i];
    if (arr[i] > *max) *max = arr[i];
  }

  return true;
}

int main()
{
  int x = 10, y = 99;

  printf("до swap:    x = %d, y = %d\n", x, y);
  swap(&x, &y);  // передаём АДРЕСА, а не значения
  printf("после swap: x = %d, y = %d\n\n", x, y);

  int arr[ARR_SIZE] = {42, -7, 13, 8, 100, 0, -50};
  int min, max;

  if (min_max(arr, ARR_SIZE, &min, &max)) {
    printf("min = %d, max = %d\n", min, max);
  }

  if (!min_max(NULL, 0, &min, &max)) {
    printf("пустой массив: функция вернула false\n");
  }

  return 0;
}
