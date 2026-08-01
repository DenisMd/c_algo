#include <stdio.h>
#include <stdint.h> // SIZE_MAX

#define ARR_SIZE 10


void init_array(int arr[], size_t size) {
  for(size_t i=0; i < size; i++) {
    arr[i] = i*i - 5*i + 3; // немного разброса: и минусы, и повторы
  }
}

void print_array(const int arr[], size_t size) {
  for(size_t i=0; i < size; i++) {
    printf("arr[%zu] = %d\n", i, arr[i]);
  }
}

int array_min(const int arr[], size_t size) {
  int min = arr[0];
  for(size_t i=1; i < size; i++) {
    if(arr[i] < min) {
      min = arr[i];
    }
  }
  return min;
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

long array_sum(const int arr[], size_t size) {
  long sum = 0;
  for(size_t i=0; i < size; i++) {
    sum += arr[i];
  }
  return sum;
}

double array_avg(const int arr[], size_t size) {
  return (double)array_sum(arr, size) / size;
}

// вариант 1: возвращает индекс первого вхождения или -1, если не найдено.
// минус: индекс приводится к long, на очень больших массивах может не влезть
long linear_search_signed(const int arr[], size_t size, int target) {
  for(size_t i=0; i < size; i++) {
    if(arr[i] == target) {
      return (long)i;
    }
  }
  return -1;
}

// вариант 2: возвращает индекс первого вхождения
// или SIZE_MAX (максимальное значение size_t), если не найдено.
// тип совпадает с индексом, sentinel не занимает валидный индекс
size_t linear_search(const int arr[], size_t size, int target) {
  for(size_t i=0; i < size; i++) {
    if(arr[i] == target) {
      return i;
    }
  }
  return SIZE_MAX;
}


int main()
{
  int arr[ARR_SIZE];

  init_array(arr, ARR_SIZE);
  print_array(arr, ARR_SIZE);

  printf("min = %d\n", array_min(arr, ARR_SIZE));
  printf("max = %d\n", array_max(arr, ARR_SIZE));
  printf("sum = %ld\n", array_sum(arr, ARR_SIZE));
  printf("avg = %.2f\n", array_avg(arr, ARR_SIZE));

  int target = 3;

  long idx_s = linear_search_signed(arr, ARR_SIZE, target);
  if(idx_s >= 0) {
    printf("linear_search_signed(%d) -> index %ld\n", target, idx_s);
  } else {
    printf("linear_search_signed(%d) -> not found\n", target);
  }

  size_t idx = linear_search(arr, ARR_SIZE, target);
  if(idx != SIZE_MAX) {
    printf("linear_search(%d) -> index %zu\n", target, idx);
  } else {
    printf("linear_search(%d) -> not found\n", target);
  }

  return 0;
}
