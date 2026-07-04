#include <stdio.h>

int main()
{
  int rows;
  if (scanf("%d", &rows) != 1) {
    fprintf(stderr, "invalid input \n");
    return 1;
  }

  for (int i=0; i < rows; i++) {
    for (int j=0; j <= i; j++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}