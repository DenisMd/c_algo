#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "geometry.h"

const double TOLERANCE = 1e-6;

void read_point(struct point* p)
{
  if (scanf("%lf %lf", &p->x, &p->y) != 2) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
}

void read_segment(struct segment* s)
{
  read_point(&s->a);
  read_point(&s->b);
}

void read_input(struct segment* s1, struct segment* s2, struct point* p)
{
  printf("Enter two segments and a point: ");
  read_segment(s1);
  read_segment(s2);
  read_point(p);
}

int main()
{
  struct segment s1, s2;
  struct point p;

  read_input(&s1, &s2, &p);

  struct vector v1 = vector_between(s1.a, s1.b);
  struct vector v2 = vector_between(s2.a, s2.b);
  struct vector unit = vector_normalize(v1);

  printf("v1 = (%.4f, %.4f), |v1| = %.4f\n", v1.x, v1.y, vector_length(v1));
  printf("unit v1 = (%.4f, %.4f), |unit| = %.4f\n", unit.x, unit.y,
         vector_length(unit));
  printf("dot(v1, v2) = %.4f\n", vector_dot(v1, v2));

  double distance = point_segment_distance(p, s1);
  assert(distance >= 0.0);
  printf("distance from point to s1 = %.4f\n", distance);

  struct intersection hit = segments_intersect(s1, s2);

  if (hit.exists) {
    assert(point_segment_distance(hit.p, s1) < TOLERANCE &&
           point_segment_distance(hit.p, s2) < TOLERANCE);
    printf("intersection: (%.4f, %.4f)\n", hit.p.x, hit.p.y);
  } else {
    printf("intersection: none\n");
  }

  return 0;
}
