#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void read_input(double *ox, double *oy, double *oz, double *dx, double *dy, double *dz,
                double *cx, double *cy, double *cz, double *r)
{
  printf("Enter O, D, C, r (10 numbers): ");
  if (scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", ox, oy, oz, dx, dy, dz, cx, cy,
            cz, r) != 10) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
  if (*r <= 0.0) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
  if (*dx == 0.0 && *dy == 0.0 && *dz == 0.0) {
    fprintf(stderr, "Zero direction!\n");
    exit(1);
  }
}

double dot(double ax, double ay, double az, double bx, double by, double bz)
{
  return ax * bx + ay * by + az * bz;
}

// Решает a*t^2 + b*t + c = 0 (a != 0).
// Возвращает число вещественных корней (0, 1 или 2) и пишет их в *t0, *t1
// по возрастанию (t0 <= t1). При одном корне t0 == t1.
int solve_quadratic(double a, double b, double c, double *t0, double *t1)
{
  assert(a != 0.0);

  double disc = b * b - 4.0 * a * c;
  if (disc < 0.0) {
    return 0;  // вещественных корней нет
  }

  double sq = sqrt(disc);
  double lo = (-b - sq) / (2.0 * a);
  double hi = (-b + sq) / (2.0 * a);

  // Упорядочиваем: при a < 0 деление меняет знак и lo мог бы стать больше hi
  if (lo <= hi) {
    *t0 = lo;
    *t1 = hi;
  } else {
    *t0 = hi;
    *t1 = lo;
  }

  return disc == 0.0 ? 1 : 2;
}

int intersect_sphere(double ox, double oy, double oz, double dx, double dy, double dz,
                     double cx, double cy, double cz, double r, double *t)
{
  // OC = O - C
  double ocx = ox - cx;
  double ocy = oy - cy;
  double ocz = oz - cz;

  // Коэффициенты квадратного уравнения a*t^2 + b*t + c = 0
  double a = dot(dx, dy, dz, dx, dy, dz);
  double b = 2.0 * dot(ocx, ocy, ocz, dx, dy, dz);
  double c = dot(ocx, ocy, ocz, ocx, ocy, ocz) - r * r;

  // Направление ненулевое (проверено во read_input), значит a > 0
  assert(a > 0.0);

  double t0, t1;
  if (solve_quadratic(a, b, c, &t0, &t1) == 0) {
    return 0;  // корней нет — луч проходит мимо
  }

  if (t0 >= 0.0) {
    *t = t0;  // ближайшее пересечение — вход в сферу
    return 1;
  }
  if (t1 >= 0.0) {
    *t = t1;  // начало луча внутри сферы — берём выход
    return 1;
  }

  return 0;  // оба корня позади луча — сфера сзади
}

int main()
{
  double ox, oy, oz, dx, dy, dz, cx, cy, cz, r;

  read_input(&ox, &oy, &oz, &dx, &dy, &dz, &cx, &cy, &cz, &r);

  double t;
  if (intersect_sphere(ox, oy, oz, dx, dy, dz, cx, cy, cz, r, &t)) {
    printf("Hit! t = %f\n", t);
    printf("point = (%f, %f, %f)\n", ox + t * dx, oy + t * dy, oz + t * dz);
  } else {
    printf("Miss\n");
  }

  return 0;
}
