#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "stats.h"

const double TOLERANCE = 1e-9;

void read_stream(struct stats* s)
{
  double x;
  int got;

  while ((got = scanf("%lf", &x)) == 1) {
    stats_add(s, x);
  }

  if (got != EOF) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
}

int main()
{
  struct stats s;

  stats_init(&s);

  printf("Enter numbers, Ctrl+D to stop: ");
  read_stream(&s);

  printf("n = %zu\n", s.n);

  if (s.n == 0) {
    printf("no data\n");
    return 0;
  }

  double mean = stats_mean(&s);
  assert(s.min - TOLERANCE <= mean && mean <= s.max + TOLERANCE);

  printf("sum = %.4f\n", s.sum);
  printf("min = %.4f, max = %.4f\n", s.min, s.max);
  printf("mean = %.4f\n", mean);
  printf("variance = %.4f\n", stats_variance(&s));
  printf("stddev = %.4f\n", stats_stddev(&s));

  return 0;
}
