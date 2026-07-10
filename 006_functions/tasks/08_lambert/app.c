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
    // TODO: скалярное произведение ax*bx + ay*by + az*bz
    return 0;
}

double length(double x, double y, double z)
{
    // TODO: длина вектора sqrt(x² + y² + z²)
    return 0;
}

double angle_deg(double nx, double ny, double nz, double lx, double ly, double lz)
{
    // TODO: cos = dot / (|N| * |L|); зажать в [-1, 1]; acos; перевести в градусы
    return 0;
}

double lambert(double nx, double ny, double nz, double lx, double ly, double lz)
{
    // TODO: яркость = max(0, dot / (|N| * |L|))
    return 0;
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
