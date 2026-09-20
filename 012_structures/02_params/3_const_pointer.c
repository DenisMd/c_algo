#include <assert.h>
#include <stdio.h>

#define HOURS 24

struct day_log {
  int day;
  int month;
  double temp[HOURS];
};

double avg_by_value(struct day_log log)  // копируется вся структура с массивом
{
  printf("avg_by_value:   &log   = %p, sizeof(log)   = %zu bytes\n",
         (void*)&log, sizeof(log));

  double sum = 0.0;

  for (size_t h = 0; h < HOURS; h++) {
    sum += log.temp[h];
  }

  return sum / HOURS;
}

double avg_by_pointer(const struct day_log* log)
{
  assert(log != NULL);  // return занят под среднее, вернуть false некуда

  printf("avg_by_pointer:  log   = %p, sizeof(log)   = %zu bytes\n", (void*)log,
         sizeof(log));

  // log->temp[0] = 0.0;  // ошибка: через указатель на const писать нельзя

  double sum = 0.0;

  for (size_t h = 0; h < HOURS; h++) {
    sum += log->temp[h];
  }

  return sum / HOURS;
}

int main()
{
  struct day_log today = {
      15, 4, {4.1,  3.6,  3.2,  2.9,  2.7,  2.8,  3.5,  5.0,
              7.2,  9.4,  11.3, 12.8, 13.9, 14.6, 14.9, 14.7,
              14.0, 12.8, 11.1, 9.5,  8.2,  7.0,  5.9,  5.0}};

  printf("main:           &today = %p, sizeof(today) = %zu bytes\n\n",
         (void*)&today, sizeof(today));

  double avg = avg_by_value(today);
  printf("%02d.%02d: avg = %.2f\n\n", today.day, today.month, avg);

  avg = avg_by_pointer(&today);
  printf("%02d.%02d: avg = %.2f\n", today.day, today.month, avg);

  return 0;
}
