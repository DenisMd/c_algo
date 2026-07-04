#include <stdio.h>

int main()
{
  int num;
  if (scanf("%d", &num) != 1) {
    fprintf(stderr, "invalid input");
    return 1;
  }

  int i = 0;
  while (i < num) {
    printf("i = %d\n", i);
    i++;
  }

  return 0;
}