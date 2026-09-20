#include <stdio.h>

struct vec2 {
  double x;
  double y;
};

const struct vec2 GRAVITY = {0.0, -9.81};
const double DT = 0.2;

struct vec2 add(struct vec2 a, struct vec2 b)
{
  struct vec2 sum = {a.x + b.x, a.y + b.y};
  return sum;
}

struct vec2 scale(struct vec2 v, double k)
{
  struct vec2 res = {v.x * k, v.y * k};
  return res;
}

int main()
{
  struct vec2 pos = {0.0, 0.0};
  struct vec2 vel = {8.0, 10.0};

  for (int step = 0; pos.y >= 0.0; step++) {
    printf("t = %.1f: pos = (%5.2f, %5.2f), vel = (%5.2f, %6.2f)\n", step * DT,
           pos.x, pos.y, vel.x, vel.y);

    vel = add(vel, scale(GRAVITY, DT));  // результат scale сразу идёт в add
    pos = add(pos, scale(vel, DT));
  }

  // add(pos, vel);  // pos не изменится: результат вернули и выбросили

  return 0;
}
