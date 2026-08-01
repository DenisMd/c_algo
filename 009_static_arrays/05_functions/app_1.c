#include <stdio.h>

#define ARR_SIZE 10


void init_array(int arr[], size_t size) {
  for(size_t i=0; i < size; i++) {
    arr[i] = i;
  }
}

void print_array(const int arr[], size_t size) {
  for(size_t i=0; i < size; i++) {
    printf("arr[%zu] = %d\n", i, arr[i]);
  }
}


int main()
{
  int arr[ARR_SIZE];

  init_array(arr, ARR_SIZE);
  print_array(arr, ARR_SIZE);

  return 0;
}