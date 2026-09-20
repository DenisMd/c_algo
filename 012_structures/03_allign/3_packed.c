#include <stdalign.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

// в файле НАРОЧНО невыровненный указатель: gcc предупреждает, UBSan ловит
//   gcc -Wall -Wextra -std=c17 -fsanitize=undefined -g -o packed 3_packed.c
//   ./packed

const double SENSOR_OFFSET = -0.5;

struct __attribute__((packed)) reading_packed {
  bool valid;
  double value;
  short sensor;
  int station;
  bool alarm;
};

void calibrate(double* value, double offset)
{
  if (value == NULL) {
    return;
  }

  *value += offset;
}

int main()
{
  struct reading_packed r = {true, 21.5, 3, 1001, false};

  printf("sizeof = %zu, alignof = %zu\n", sizeof(r),
         alignof(struct reading_packed));
  printf("value: offset = %zu, alignof(double) = %zu\n\n",
         offsetof(struct reading_packed, value), alignof(double));

  calibrate(&r.value, SENSOR_OFFSET);  // double* на адрес, не кратный 8

  printf("r.value = %.1f\n", r.value);

  return 0;
}
