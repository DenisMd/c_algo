#include <stdio.h>

#define ARR_SIZE 10

int main()
{
  int arr[ARR_SIZE];


  for(size_t i=0; i < ARR_SIZE; i++) { // !!!!! используйте строго меньше "<"
    arr[i] = i*2 + 1;
  }

  
  for(size_t i=ARR_SIZE-1; i >= 0; i--) {
    printf("arr[%zu] = %d\n", i, arr[i]);
  }

  /*
  for(size_t i=ARR_SIZE; i > 0; i--) {
    printf("arr[%zu] = %d\n", i, arr[i-1]);
  }
  */

  return 0;
}