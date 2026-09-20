#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <stdbool.h>

struct point {
    double x;
    double y;
};

struct vector {
    double x;
    double y;
};

struct segment {
    struct point a;
    struct point b;
};

struct intersection {
    bool exists;
    struct point p;  // имеет смысл только при exists == true
};

struct vector vector_between(struct point a, struct point b);
double vector_dot(struct vector u, struct vector v);
double vector_length(struct vector v);
struct vector vector_normalize(struct vector v);

double point_segment_distance(struct point p, struct segment s);
struct intersection segments_intersect(struct segment s1, struct segment s2);

#endif
