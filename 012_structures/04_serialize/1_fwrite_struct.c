#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// посмотреть сам файл: xxd raw.bin
// https://cppreference.com/c/io

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
  struct reading r;
  memset(&r, FILL_BYTE, sizeof(r));

  r.valid = true;
  r.value = 21.5;
  r.sensor = 3;
  r.station = 1001;
  r.alarm = false;

  FILE* f = fopen("raw.bin", "wb");

  if (f == NULL) {
    fprintf(stderr, "cannot open raw.bin\n");
    return 1;
  }

  size_t written = fwrite(&r, sizeof(r), 1, f);
  fclose(f);

  if (written != 1) {
    fprintf(stderr, "cannot write raw.bin\n");
    return 1;
  }

  struct reading loaded;
  f = fopen("raw.bin", "rb");

  if (f == NULL) {
    fprintf(stderr, "cannot open raw.bin\n");
    return 1;
  }

  size_t got = fread(&loaded, sizeof(loaded), 1, f);
  fclose(f);

  if (got != 1) {
    fprintf(stderr, "cannot read raw.bin\n");
    return 1;
  }

  printf("raw.bin: %zu bytes\n", sizeof(loaded));
  printf("value = %g, station = %d, sensor = %d, valid = %d, alarm = %d\n\n",
         loaded.value, loaded.station, loaded.sensor, loaded.valid,
         loaded.alarm);

  dump_bytes(&loaded, sizeof(loaded));  // AA в padding приехали из файла

  return 0;
}
