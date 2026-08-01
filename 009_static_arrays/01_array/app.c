#include <stdio.h>

#define ARR_SIZE 5

int main()
{
  int my_arr[ARR_SIZE] = {1,2,3,4,5}; // РАЗАМЕР МАССИВА ДОЛЖЕН БЫТЬ ИЗВЕСТЕН В МОМЕНТ КОМПИЛЯЦИ!!!!!

  my_arr[0] = 1;
  my_arr[1] = 2;
  my_arr[2] = 3;
  my_arr[3] = 4;
  my_arr[4] = 5;

  printf("sizeof(my_arr) = %zu bytes\n\n",sizeof(my_arr));

  printf("arr[0] = %d\n",my_arr[0]);
  printf("arr[1] = %d\n",my_arr[1]);
  printf("arr[2] = %d\n",my_arr[2]);
  printf("arr[3] = %d\n",my_arr[3]);
  printf("arr[4] = %d\n",my_arr[4]);

  return 0;
}