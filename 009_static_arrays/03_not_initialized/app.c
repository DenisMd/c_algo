#include <stdio.h>

#define ARR_SIZE 1000

int main()
{
  int arr[ARR_SIZE]; // = {0}
  
  for(size_t i=0; i < ARR_SIZE; i++) {
    printf("arr[%zu] = %d\n", i, arr[i]); // UB
  }

  return 0;
}