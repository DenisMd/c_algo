#include <stdio.h>

struct foo {
  int a;
  int b;
};

typedef struct foo foo_t;

typedef struct {
  int a;
  int b;
} bar_t;

int main()
{
  struct foo x = {1, 2};
  foo_t y = {3, 4};
  bar_t z = {5, 6};

  // foo w;  // ошибка: тип называется struct foo или foo_t

  printf("x = {%d, %d}\n", x.a, x.b);
  printf("y = {%d, %d}\n", y.a, y.b);
  printf("z = {%d, %d}\n", z.a, z.b);

  return 0;
}
