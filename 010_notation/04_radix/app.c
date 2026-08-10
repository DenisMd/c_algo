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
    if (i > 0) {
      printf(".");
    }
    printf("%d", arr[i]);
  }
  printf("\n");
}

int main()
{
  int n, radix;
  if (scanf("%d %d", &n, &radix) != 2) {
    printf("input error\n");
    return 1;
  }
  if (radix < 2) {
    printf("radix must be >= 2\n");
    return 1;
  }

  int digits[sizeof(int)*CHAR_BIT];
  int count = 0;

  while (n > 0) {
    digits[count] = n % radix;
    n = n / radix;
    count++;
  }

  reverse_array(digits, count);
  print_array(digits, count);

  return 0;
}
