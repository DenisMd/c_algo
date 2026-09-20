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
  if (s == NULL) {
    return;
  }

  double old_mean = stats_mean(s);  // у пустого 0, шаг m2 тогда тоже 0

  if (s->n == 0 || x < s->min) s->min = x;
  if (s->n == 0 || x > s->max) s->max = x;

  s->n++;
  s->sum += x;

  double new_mean = stats_mean(s);

  s->m2 += (x - old_mean) * (x - new_mean);  // шаг Уэлфорда
}

double stats_mean(const struct stats* s)
{
  assert(s != NULL);

  if (s->n == 0) {
    return 0.0;
  }

  return s->sum / s->n;
}

double stats_variance(const struct stats* s)
{
  assert(s != NULL);

  if (s->n == 0) {
    return 0.0;
  }

  return s->m2 / s->n;
}

double stats_stddev(const struct stats* s) { return sqrt(stats_variance(s)); }
