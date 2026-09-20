#ifndef STATS_H
#define STATS_H

#include <stddef.h>

struct stats {
    size_t n;
    double sum;
    double min;  // min и max имеют смысл только при n > 0
    double max;
    double m2;  // расширение: сумма квадратов отклонений от среднего
};

void stats_init(struct stats* s);
void stats_add(struct stats* s, double x);
double stats_mean(const struct stats* s);

double stats_variance(const struct stats* s);  // расширение
double stats_stddev(const struct stats* s);    // расширение

#endif
