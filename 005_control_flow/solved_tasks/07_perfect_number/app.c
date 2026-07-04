#include <stdio.h>

int main()
{
  int n;

  printf("Enter integer N: ");
  if (scanf("%d", &n) != 1) {
    fprintf(stderr, "Incorrect input!\n");
    return 1;
  }

  for (int num = 1; num <= n; num++) {
    int sum = 0;
    for (int i = 1; i < num; i++) {
      if (num % i == 0) {
        sum += i;
      }
    }
    if (sum == num) {
      printf("%d\n", num);
    }
  }

  return 0;
}
