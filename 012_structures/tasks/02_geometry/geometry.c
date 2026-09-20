#include "geometry.h"

#include <math.h>

// TODO: static-помощники: EPS для сравнений с нулём и cross(u, v)

struct vector vector_between(struct point a, struct point b)
{
    // TODO: координаты b минус координаты a
    struct vector v = {0.0, 0.0};
    return v;
}

double vector_dot(struct vector u, struct vector v)
{
    // TODO: u.x * v.x + u.y * v.y
    return 0.0;
}

double vector_length(struct vector v)
{
    // TODO: корень из скалярного произведения вектора на себя
    return 0.0;
}

struct vector vector_normalize(struct vector v)
{
    // TODO: поделить координаты на длину; нулевой вектор -> (0, 0)
    struct vector unit = {0.0, 0.0};
    return unit;
}

double point_segment_distance(struct point p, struct segment s)
{
    // TODO: t = (AP · AB) / (AB · AB), обрезать в [0, 1];
    //       ближайшая точка A + t * AB, вернуть расстояние до неё;
    //       AB · AB == 0 (отрезок-точка) -> t = 0
    return 0.0;
}

struct intersection segments_intersect(struct segment s1, struct segment s2)
{
    // TODO: d = cross(r, s); |d| < EPS -> пересечения нет;
    //       t = cross(Q - P, s) / d, u = cross(Q - P, r) / d;
    //       оба в [0, 1] -> точка P + t * r
    struct intersection result = {false, {0.0, 0.0}};
    return result;
}
