#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "rect.h"

const double TOLERANCE = 1e-9;

void read_point(struct point* p)
{
  if (scanf("%lf %lf", &p->x, &p->y) != 2) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
}

void read_rect(struct rect* r)
{
  struct point a, b;

  read_point(&a);
  read_point(&b);

  *r = rect_make(a, b);
}

void read_input(struct rect* a, struct rect* b)
{
  printf("Enter two rectangles (two corners each): ");
  read_rect(a);
  read_rect(b);
}

void print_rect(struct rect r)
{
  if (rect_is_empty(r)) {
    printf("empty");
  } else {
    printf("(%.2f, %.2f)-(%.2f, %.2f)", r.min.x, r.min.y, r.max.x, r.max.y);
  }

  printf(", area = %.2f\n", rect_area(r));
}

void print_flag(bool value)
{
  if (value) {
    printf("yes\n");
  } else {
    printf("no\n");
  }
}

int main()
{
  struct rect a, b;

  read_input(&a, &b);

  struct rect common = rect_intersect(a, b);
  struct rect box = rect_union(a, b);

  assert(rect_area(common) <= rect_area(box) + TOLERANCE);

  printf("a = ");
  print_rect(a);
  printf("b = ");
  print_rect(b);
  printf("intersect = ");
  print_rect(common);
  printf("union = ");
  print_rect(box);

  printf("a contains b: ");
  print_flag(rect_contains(a, b));
  printf("b contains a: ");
  print_flag(rect_contains(b, a));

  return 0;
}
