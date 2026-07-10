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

int intersect_sphere(double ox, double oy, double oz, double dx, double dy, double dz,
                     double cx, double cy, double cz, double r, double *t)
{
    // TODO: свести к квадратному уравнению a*t^2 + b*t + c = 0
    // OC = O - C
    // a = D·D, b = 2*(OC·D), c = OC·OC - r*r
    // disc = b*b - 4*a*c; disc < 0 -> мимо
    // t0 = (-b - sqrt(disc)) / (2a), t1 = (-b + sqrt(disc)) / (2a)
    // Вернуть ближайший неотрицательный корень через *t

    return 0;
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
