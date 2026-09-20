#include "rect.h"

static const struct rect EMPTY = {{0.0, 0.0}, {0.0, 0.0}};

static double min_d(double a, double b) { return a < b ? a : b; }

static double max_d(double a, double b) { return a > b ? a : b; }

struct rect rect_make(struct point a, struct point b)
{
  struct rect r = {{min_d(a.x, b.x), min_d(a.y, b.y)},
                   {max_d(a.x, b.x), max_d(a.y, b.y)}};
  return r;
}

bool rect_is_empty(struct rect r)
{
  return r.min.x >= r.max.x || r.min.y >= r.max.y;
}

double rect_area(struct rect r)
{
  if (rect_is_empty(r)) {
    return 0.0;
  }

  return (r.max.x - r.min.x) * (r.max.y - r.min.y);
}

struct rect rect_intersect(struct rect a, struct rect b)
{
  if (rect_is_empty(a) || rect_is_empty(b)) {
    return EMPTY;
  }

  struct rect r = {{max_d(a.min.x, b.min.x), max_d(a.min.y, b.min.y)},
                   {min_d(a.max.x, b.max.x), min_d(a.max.y, b.max.y)}};

  if (rect_is_empty(r)) {  // разошлись хотя бы по одной оси
    return EMPTY;
  }

  return r;
}

struct rect rect_union(struct rect a, struct rect b)
{
  if (rect_is_empty(a) && rect_is_empty(b)) {
    return EMPTY;
  }

  if (rect_is_empty(a)) {
    return b;
  }

  if (rect_is_empty(b)) {
    return a;
  }

  struct rect r = {{min_d(a.min.x, b.min.x), min_d(a.min.y, b.min.y)},
                   {max_d(a.max.x, b.max.x), max_d(a.max.y, b.max.y)}};
  return r;
}

bool rect_contains(struct rect outer, struct rect inner)
{
  if (rect_is_empty(outer) || rect_is_empty(inner)) {
    return false;
  }

  return outer.min.x <= inner.min.x && outer.min.y <= inner.min.y &&
         inner.max.x <= outer.max.x && inner.max.y <= outer.max.y;
}
