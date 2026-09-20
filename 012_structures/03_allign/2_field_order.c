#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

const size_t READINGS_PER_YEAR = 365 * 24 * 60;
const double MB = 1024.0 * 1024.0;

struct reading_bad {
  bool valid;
  double value;
  short sensor;
  int station;
  bool alarm;
};

struct reading_good {  // по убыванию выравнивания: 8, 4, 2, 1, 1
  double value;
  int station;
  short sensor;
  bool valid;
  bool alarm;
};

int main()
{
  printf("field     bad  good\n");
  printf("value   %5zu %5zu\n", offsetof(struct reading_bad, value),
         offsetof(struct reading_good, value));
  printf("station %5zu %5zu\n", offsetof(struct reading_bad, station),
         offsetof(struct reading_good, station));
  printf("sensor  %5zu %5zu\n", offsetof(struct reading_bad, sensor),
         offsetof(struct reading_good, sensor));
  printf("valid   %5zu %5zu\n", offsetof(struct reading_bad, valid),
         offsetof(struct reading_good, valid));
  printf("alarm   %5zu %5zu\n", offsetof(struct reading_bad, alarm),
         offsetof(struct reading_good, alarm));
  printf("sizeof  %5zu %5zu\n\n", sizeof(struct reading_bad),
         sizeof(struct reading_good));

  printf("%zu readings per year (one per minute):\n", READINGS_PER_YEAR);
  printf("bad:  %.1f MB\n",
         READINGS_PER_YEAR * sizeof(struct reading_bad) / MB);
  printf("good: %.1f MB\n",
         READINGS_PER_YEAR * sizeof(struct reading_good) / MB);

  return 0;
}
