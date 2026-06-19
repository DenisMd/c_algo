#include <stdio.h>
#include <math.h>

int main()
{
    const double SPEED_LIGHT = 2.998e8; // m/s
    const double SPEED_LIGHT_SQUARE = SPEED_LIGHT*SPEED_LIGHT;
    const double ELECTRON_VOLTS_IN_J = 6.242e18;

    double mass;
    double speed;
    double relativistic_energy;
    double lorenz_factor;

    scanf("%lf%lf",&mass, &speed);

    double speed_square = speed * speed;

    double x = speed_square/SPEED_LIGHT_SQUARE;
    lorenz_factor = 1. / sqrt(1 - x);
    relativistic_energy = lorenz_factor * mass * SPEED_LIGHT_SQUARE;
    
    printf("Rel energy - %e J\n", relativistic_energy);
    printf("Rel energy - %e eV\n", relativistic_energy*ELECTRON_VOLTS_IN_J);

    return 0;
}