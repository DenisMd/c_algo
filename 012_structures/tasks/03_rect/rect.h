#ifndef RECT_H
#define RECT_H

#include <stdbool.h>

struct point {
    double x;
    double y;
};

struct rect {  // пустой, если min.x >= max.x или min.y >= max.y
    struct point min;
    struct point max;
};

struct rect rect_make(struct point a, struct point b);
bool rect_is_empty(struct rect r);
double rect_area(struct rect r);

struct rect rect_intersect(struct rect a, struct rect b);
struct rect rect_union(struct rect a, struct rect b);
bool rect_contains(struct rect outer, struct rect inner);

#endif
