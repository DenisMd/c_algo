#include <stdio.h>

#define G 6.674e-11

struct planet {
  double mass;
  double radius;
};

int main()
{
  struct planet earth = {5.972e24, 6.371e6};
  struct planet mars = {6.417e23, 3.390e6};

  struct planet jupiter;
  jupiter.mass = 1.898e27;
  jupiter.radius = 7.149e7;

  printf("sizeof(struct planet) = %zu bytes\n", sizeof(struct planet));
  printf("sizeof(earth)         = %zu bytes\n\n", sizeof(earth));

  double g_earth = G * earth.mass / (earth.radius * earth.radius);
  double g_mars = G * mars.mass / (mars.radius * mars.radius);
  double g_jupiter = G * jupiter.mass / (jupiter.radius * jupiter.radius);

  printf("earth:   mass = %.3e kg, radius = %.3e m, g = %.2f m/s^2\n",
         earth.mass, earth.radius, g_earth);
  printf("mars:    mass = %.3e kg, radius = %.3e m, g = %.2f m/s^2\n",
         mars.mass, mars.radius, g_mars);
  printf("jupiter: mass = %.3e kg, radius = %.3e m, g = %.2f m/s^2\n",
         jupiter.mass, jupiter.radius, g_jupiter);

  return 0;
}
