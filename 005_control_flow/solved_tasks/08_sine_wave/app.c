#include <math.h>
#include <stdio.h>
#include <string.h>

int main()
{
  const double x_step = 0.2;
  const double y_step = 0.2;
  const double y_max = 1.0;
  const double y_min = -1.0;
  const double eps = 1e-9;

  int width;

  printf("Enter plot width: ");
  if (scanf("%d", &width) != 1 || width <= 0) {
    fprintf(stderr, "Incorrect input!\n");
    return 1;
  }

  for (double y = y_max; y >= y_min - eps; y -= y_step) {
    if (fabs(y - y_max) < eps || fabs(y - y_min) < eps) {
      printf("%5.1f", y);
    } else {
      printf("     ");
    }
    printf("|");

    for (int x = 0; x < width; x++) {
      if (fabs(sin(x * x_step) - y) < y_step / 2) {
        printf("*");
      } else if (fabs(y) < y_step / 2) {
        printf("-");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }

  printf("     +");
  for (int x = 0; x < width; x++) {
    printf("-");
  }
  printf("\n");

  printf("      0");
  double x_max = x_step * width;
  int x_max_int = (int)x_max;
  int digits_in_xmax = 0; // количество цифр в целой части
  while (x_max_int > 0) {
    digits_in_xmax++;
    x_max_int /= 10;
  }
  // 3 позиции на точку и цифры после нее (.35)
  // 1 на 0 который уже спереди
  int pad = width - digits_in_xmax - 1 - 3; 
  for (int i = 0; i < pad; i++) {
    printf(" ");
  }
  printf("%.2f\n", x_max);

  return 0;
}
