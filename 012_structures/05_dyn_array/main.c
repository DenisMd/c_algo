#include <stdbool.h>
#include <stdio.h>

#include "dyn_array.h"

struct station {
  int id;
  struct dyn_array* rainfall;  // мм осадков по дням
  // struct dyn_array by_value;  // ошибка: поля скрыты, размер неизвестен
};

bool station_init(struct station* st, int id)
{
  if (st == NULL) {
    return false;
  }

  st->id = id;
  st->rainfall = dyn_array_create();

  return st->rainfall != NULL;
}

void station_free(struct station* st)
{
  if (st == NULL) {
    return;
  }

  dyn_array_destroy(st->rainfall);
  st->rainfall = NULL;
}

void station_print(const struct station* st)
{
  if (st == NULL) {
    return;
  }

  size_t days = dyn_array_size(st->rainfall);
  int total = 0;

  printf("station #%d, %zu days (capacity %zu):", st->id, days,
         dyn_array_capacity(st->rainfall));

  for (size_t day = 0; day < days; day++) {
    int mm = dyn_array_get(st->rainfall, day);
    total += mm;
    printf(" %d", mm);
  }

  printf(", total = %d mm\n", total);
}

int main()
{
  int week[] = {0, 3, 12, 0, 0, 7, 25};
  size_t n = sizeof(week) / sizeof(week[0]);

  struct station st;

  if (!station_init(&st, 1001)) {
    fprintf(stderr, "out of memory\n");
    return 1;
  }

  for (size_t day = 0; day < n; day++) {
    if (!dyn_array_push(st.rainfall, week[day])) {
      fprintf(stderr, "out of memory\n");
      station_free(&st);
      return 1;
    }
  }

  station_print(&st);

  size_t bad_day = 2;
  int old = dyn_array_get(st.rainfall, bad_day);

  if (dyn_array_set(st.rainfall, bad_day, 21)) {
    printf("day %zu fixed: %d -> %d mm\n", bad_day + 1, old,
           dyn_array_get(st.rainfall, bad_day));
  }

  int last;

  if (dyn_array_pop(st.rainfall, &last)) {
    printf("last day removed: %d mm\n", last);
  }

  station_print(&st);

  // st.rainfall->size = 0;  // ошибка: поля видны только в dyn_array.c

  printf("sizeof(struct station) = %zu bytes\n", sizeof(st));

  station_free(&st);

  return 0;
}
