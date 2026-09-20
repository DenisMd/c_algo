#include "geometry.h"

#include <math.h>

static const double EPS = 1e-9;

static double cross(struct vector u, struct vector v)
{
  return u.x * v.y - u.y * v.x;  // ноль, если векторы параллельны
}

struct vector vector_between(struct point a, struct point b)
{
  struct vector v = {b.x - a.x, b.y - a.y};
  return v;
}

double vector_dot(struct vector u, struct vector v)
{
  return u.x * v.x + u.y * v.y;
}

double vector_length(struct vector v) { return sqrt(vector_dot(v, v)); }

struct vector vector_normalize(struct vector v)
{
  struct vector unit = {0.0, 0.0};
  double len = vector_length(v);

  if (len < EPS) {  // у нулевого вектора направления нет
    return unit;
  }

  unit.x = v.x / len;
  unit.y = v.y / len;

  return unit;
}

double point_segment_distance(struct point p, struct segment s)
{
  struct vector ab = vector_between(s.a, s.b);
  struct vector ap = vector_between(s.a, p);
  double len2 = vector_dot(ab, ab);
  double t = 0.0;

  if (len2 > EPS) {  // иначе отрезок выродился в точку и t остаётся нулём
    t = vector_dot(ap, ab) / len2;

    if (t < 0.0) t = 0.0;
    if (t > 1.0) t = 1.0;
  }

  struct point nearest = {s.a.x + t * ab.x, s.a.y + t * ab.y};

  return vector_length(vector_between(nearest, p));
}

struct intersection segments_intersect(struct segment s1, struct segment s2)
{
  struct intersection result = {false, {0.0, 0.0}};

  struct vector r = vector_between(s1.a, s1.b);
  struct vector s = vector_between(s2.a, s2.b);
  double d = cross(r, s);

  if (fabs(d) < EPS) {  // параллельны или лежат на одной прямой
    return result;
  }

  struct vector pq = vector_between(s1.a, s2.a);
  double t = cross(pq, s) / d;
  double u = cross(pq, r) / d;

  if (t < -EPS || t > 1.0 + EPS || u < -EPS || u > 1.0 + EPS) {
    return result;  // прямые пересеклись за пределами отрезков
  }

  result.exists = true;
  result.p.x = s1.a.x + t * r.x;
  result.p.y = s1.a.y + t * r.y;

  return result;
}
