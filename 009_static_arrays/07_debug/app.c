#include <stdio.h>

// Учебная программа для отладки массивов в gdb.
// Специально собирается с -g -O0, чтобы переменные не оптимизировались
// и по ним можно было ходить пошагово. См. README.md — там команды gdb.

#define ARR_SIZE 8

// массив-параметр: тут int arr[] на самом деле указатель (int*),
// поэтому в gdb `print arr` покажет адрес, а не элементы (см. README).
long array_sum(const int arr[], size_t size) {
  long sum = 0;
  for(size_t i=0; i < size; i++) {
    sum += arr[i]; // удобное место для watch/step
  }
  return sum;
}

int array_max(const int arr[], size_t size) {
  int max = arr[0];
  for(size_t i=1; i < size; i++) {
    if(arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

int main()
{
  int arr[ARR_SIZE];

  // заполняем в цикле — хорошая точка, чтобы поставить breakpoint и
  // посмотреть, как массив наполняется шаг за шагом.
  for(size_t i=0; i < ARR_SIZE; i++) {
    arr[i] = (int)(i * i) - 3; // немного разброса: есть и минусы
  }

  long sum = array_sum(arr, ARR_SIZE);
  int  max = array_max(arr, ARR_SIZE);

  printf("sum = %ld, max = %d\n", sum, max);

  return 0;
}
