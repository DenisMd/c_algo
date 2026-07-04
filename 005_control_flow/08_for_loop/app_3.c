#include <stdio.h>

int main()
{
  int num;
  if (scanf("%d", &num) != 1) {
    fprintf(stderr, "invalid input");
    return 1;
  }

  for (int i = num; i >= 0; i--) {
    printf("i=%d\n", i);
  }

  return 0;
}