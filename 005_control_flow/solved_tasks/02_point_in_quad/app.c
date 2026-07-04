#include <stdbool.h>
#include <stdio.h>

int main()
{
  double x1, y1, x2, y2, x3, y3, x4, y4, x, y;

  printf("Enter quad vertices and test point: ");
  if (scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4,
            &y4, &x, &y) != 10) {
    fprintf(stderr, "Incorrect input!\n");
    return 1;
  }

  double turnABC = (x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2);
  double turnBCD = (x3 - x2) * (y4 - y3) - (y3 - y2) * (x4 - x3);
  double turnCDA = (x4 - x3) * (y1 - y4) - (y4 - y3) * (x1 - x4);
  double turnDAB = (x1 - x4) * (y2 - y1) - (y1 - y4) * (x2 - x1);

  bool is_convex;
  if (turnABC > 0) {
    is_convex = turnBCD > 0 && turnCDA > 0 && turnDAB > 0;
  } else if (turnABC < 0) {
    is_convex = turnBCD < 0 && turnCDA < 0 && turnDAB < 0;
  } else {
    is_convex = 0;
  }

  if (!is_convex) {
    printf("Not convex\n");
    return 0;
  }
  printf("Convex\n");

  double crossAB = (x2 - x1) * (y - y1) - (y2 - y1) * (x - x1);
  double crossBC = (x3 - x2) * (y - y2) - (y3 - y2) * (x - x2);
  double crossCD = (x4 - x3) * (y - y3) - (y4 - y3) * (x - x3);
  double crossDA = (x1 - x4) * (y - y4) - (y1 - y4) * (x - x4);

  int inside;
  if (crossAB > 0) {
    inside = crossBC >= 0 && crossCD >= 0 && crossDA >= 0;
  } else if (crossAB < 0) {
    inside = crossBC <= 0 && crossCD <= 0 && crossDA <= 0;
  } else {
    inside = 1;
  }

  if (inside) {
    printf("Inside\n");
  } else {
    printf("Outside\n");
  }

  return 0;
}
