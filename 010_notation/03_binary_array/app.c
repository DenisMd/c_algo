#include <stdio.h>
#include <limits.h>

void reverse_array(int arr[], int size)
{
  for (int i = 0; i < size / 2; i++) {
    int tmp = arr[i];
    arr[i] = arr[size - 1 - i];
    arr[size - 1 - i] = tmp;
  }
}

void print_array(int arr[], int size)
{
  for (int i = 0; i < size; i++) {
    printf("%d", arr[i]);
  }
  printf("\n");
}

int main()
{
  int n = 13;

  printf("n = %d\n", n);

  int bits[sizeof(int)*CHAR_BIT];
  int count = 0;

  while (n > 0) {
    bits[count] = n % 2;
    n = n / 2;
    count++;
  }

  reverse_array(bits, count);
  print_array(bits, count);

  return 0;
}
