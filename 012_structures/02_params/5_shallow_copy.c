#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct samples {
  double* data;
  size_t n;
};

const double SENSOR_OFFSET = -0.5;

struct samples make_samples(const double* values, size_t n)
{
  if (values == NULL || n == 0) {
    struct samples empty = {NULL, 0};
    return empty;
  }

  struct samples s = {malloc(n * sizeof(double)), n};

  if (s.data == NULL) {
    fprintf(stderr, "malloc failed!\n");
    exit(1);
  }

  memcpy(s.data, values, n * sizeof(double));
  return s;
}

void free_samples(struct samples* s)
{
  if (s == NULL) {
    return;
  }

  free(s->data);
  s->data = NULL;
  s->n = 0;
}

void calibrate(struct samples s, double offset)
{
  for (size_t i = 0; i < s.n; i++) {
    s.data[i] += offset;  // s - копия, но data указывает на тот же блок
  }

  s.n = 0;  // а это изменение останется в копии
}

void print_samples(struct samples s)
{
  printf("data = %p, n = %zu:", (void*)s.data, s.n);

  for (size_t i = 0; i < s.n; i++) {
    printf(" %.2f", s.data[i]);
  }

  printf("\n");
}

int main()
{
  double readings[] = {20.4, 20.9, 21.3, 21.1};
  size_t n = sizeof(readings) / sizeof(readings[0]);

  struct samples raw = make_samples(readings, n);
  struct samples backup = raw;  // скопировали указатель, а не данные
  struct samples saved = make_samples(raw.data, raw.n);

  calibrate(raw, SENSOR_OFFSET);

  printf("raw:    ");
  print_samples(raw);
  printf("backup: ");
  print_samples(backup);
  printf("saved:  ");
  print_samples(saved);

  free_samples(&raw);
  free_samples(&saved);
  // free_samples(&backup);  // double free: обнулился только raw.data

  return 0;
}
