#include <stdalign.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

const int FILL_BYTE = 0xAA;
const size_t BYTES_PER_ROW = 8;

struct reading {
  bool valid;
  double value;
  short sensor;
  int station;
  bool alarm;
};

void dump_bytes(const void* ptr, size_t size)
{
  if (ptr == NULL) {
    return;
  }

  const unsigned char* bytes = ptr;

  for (size_t i = 0; i < size; i++) {
    if (i % BYTES_PER_ROW == 0) {
      printf("%2zu:", i);
    }

    printf(" %02X", bytes[i]);

    if (i % BYTES_PER_ROW == BYTES_PER_ROW - 1 || i + 1 == size) {
      printf("\n");
    }
  }
}

int main()
{
  printf("alignof: bool = %zu, short = %zu, int = %zu, double = %zu\n\n",
         alignof(bool), alignof(short), alignof(int), alignof(double));

  struct reading r;
  memset(&r, FILL_BYTE, sizeof(r));  // байты, которые останутся AA, - padding

  r.valid = true;
  r.value = 21.5;
  r.sensor = 3;
  r.station = 1001;
  r.alarm = false;

  printf("field    offset  size\n");
  printf("valid    %6zu  %4zu\n", offsetof(struct reading, valid),
         sizeof(r.valid));
  printf("value    %6zu  %4zu\n", offsetof(struct reading, value),
         sizeof(r.value));
  printf("sensor   %6zu  %4zu\n", offsetof(struct reading, sensor),
         sizeof(r.sensor));
  printf("station  %6zu  %4zu\n", offsetof(struct reading, station),
         sizeof(r.station));
  printf("alarm    %6zu  %4zu\n\n", offsetof(struct reading, alarm),
         sizeof(r.alarm));

  size_t fields = sizeof(r.valid) + sizeof(r.value) + sizeof(r.sensor) +
                  sizeof(r.station) + sizeof(r.alarm);

  printf("fields = %zu bytes, sizeof = %zu bytes, alignof = %zu\n\n", fields,
         sizeof(r), alignof(struct reading));

  dump_bytes(&r, sizeof(r));

  return 0;
}
