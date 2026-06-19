#include <stdio.h>

int main()
{

    double mass;
    double speed;
    double kinetic_energy;

    scanf("%lf%lf",&mass, &speed);
    double speed_square = speed * speed;
    kinetic_energy = mass * speed_square * 0.5;
    
    printf("Kinetic energy - %f J\n", kinetic_energy);

    return 0;
}