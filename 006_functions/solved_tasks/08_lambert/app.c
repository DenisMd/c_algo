#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void read_input(double *nx, double *ny, double *nz, double *lx, double *ly, double *lz)
{
  printf("Enter N and L (6 numbers): ");
  if (scanf("%lf %lf %lf %lf %lf %lf", nx, ny, nz, lx, ly, lz) != 6) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
  if ((*nx == 0.0 && *ny == 0.0 && *nz == 0.0) ||
      (*lx == 0.0 && *ly == 0.0 && *lz == 0.0)) {
    fprintf(stderr, "Zero vector!\n");
    exit(1);
  }
}

double dot(double ax, double ay, double az, double bx, double by, double bz)
{
  return ax * bx + ay * by + az * bz;
}

double length(double x, double y, double z)
{
  // hypot считает гипотенузу устойчиво (без переполнения на x*x).
  // В стандартной C hypot двухаргументный, поэтому для 3D вкладываем.
  return hypot(hypot(x, y), z);
}

double angle_deg(double nx, double ny, double nz, double lx, double ly, double lz)
{
  double cos_a = dot(nx, ny, nz, lx, ly, lz) /
                 (length(nx, ny, nz) * length(lx, ly, lz));

  // Зажимаем в [-1, 1]: из-за погрешности double acos(1.0000...2) даст nan
  if (cos_a > 1.0) {
    cos_a = 1.0;
  }
  if (cos_a < -1.0) {
    cos_a = -1.0;
  }

  return acos(cos_a) * 180.0 / M_PI;
}

double lambert(double nx, double ny, double nz, double lx, double ly, double lz)
{
  double ln = length(nx, ny, nz);
  double ll = length(lx, ly, lz);

  // Предусловие: нулевой вектор отсекается ещё во read_input
  assert(ln > 0.0 && ll > 0.0);

  double cos_a = dot(nx, ny, nz, lx, ly, lz) / (ln * ll);

  // Грань, отвёрнутая от света, не освещается "с изнанки"
  return cos_a < 0.0 ? 0.0 : cos_a;
}

int main()
{
  double nx, ny, nz, lx, ly, lz;

  read_input(&nx, &ny, &nz, &lx, &ly, &lz);

  printf("dot = %f\n", dot(nx, ny, nz, lx, ly, lz));
  printf("angle = %f deg\n", angle_deg(nx, ny, nz, lx, ly, lz));
  printf("brightness = %f\n", lambert(nx, ny, nz, lx, ly, lz));

  return 0;
}
