#include <stdio.h>

#define ARR_SIZE 10

int main()
{
  int arr[ARR_SIZE];


  for(size_t i=0; i < ARR_SIZE; i++) { // !!!!! используйте строго меньше "<"
    int temp;
    if(scanf("%d",&temp) != 1) {
      fprintf(stderr,"invalid input for arr[%zu]\n",i);
      return 1;
    }
    arr[i] = temp;
  }

  
  for(size_t i=0; i < ARR_SIZE; i++) {
    printf("arr[%zu] = %d\n", i, arr[i]);
  }

  return 0;
}