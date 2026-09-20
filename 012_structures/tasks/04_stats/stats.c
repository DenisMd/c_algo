#include "stats.h"

#include <assert.h>
#include <math.h>

void stats_init(struct stats* s)
{
    if (s == NULL) {
        return;
    }

    s->n = 0;
    s->sum = 0.0;
    s->min = 0.0;
    s->max = 0.0;
    s->m2 = 0.0;
}

void stats_add(struct stats* s, double x)
{
    // TODO: обновить n, sum, min, max; первое число сразу и min, и max
    // TODO (расширение): m2 += (x - старое среднее) * (x - новое среднее)
}

double stats_mean(const struct stats* s)
{
    // TODO: sum / n, у пустого - 0
    return 0.0;
}

double stats_variance(const struct stats* s)
{
    // TODO (расширение): m2 / n, у пустого - 0
    return 0.0;
}

double stats_stddev(const struct stats* s)
{
    // TODO (расширение): корень из дисперсии
    return 0.0;
}
