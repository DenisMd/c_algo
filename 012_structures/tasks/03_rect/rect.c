#include "rect.h"

// TODO: static-помощники: канонический пустой прямоугольник, min и max для double

struct rect rect_make(struct point a, struct point b)
{
    // TODO: в min - меньшие координаты по каждой оси, в max - большие
    struct rect r = {{0.0, 0.0}, {0.0, 0.0}};
    return r;
}

bool rect_is_empty(struct rect r)
{
    // TODO: min.x >= max.x или min.y >= max.y
    return true;
}

double rect_area(struct rect r)
{
    // TODO: у пустого 0, иначе ширина * высота
    return 0.0;
}

struct rect rect_intersect(struct rect a, struct rect b)
{
    // TODO: max из двух min и min из двух max по каждой оси;
    //       пустой вход или пустой результат -> канонический пустой
    struct rect r = {{0.0, 0.0}, {0.0, 0.0}};
    return r;
}

struct rect rect_union(struct rect a, struct rect b)
{
    // TODO: min из двух min и max из двух max по каждой оси;
    //       пустой прямоугольник в объединении пропускается
    struct rect r = {{0.0, 0.0}, {0.0, 0.0}};
    return r;
}

bool rect_contains(struct rect outer, struct rect inner)
{
    // TODO: inner целиком внутри outer, границы могут совпадать;
    //       пустой любой из двух -> false
    return false;
}
