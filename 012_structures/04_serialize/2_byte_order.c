#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define RECORD_SIZE 16

const size_t VALUE_AT = 0;
const size_t STATION_AT = 8;
const size_t SENSOR_AT = 12;
const size_t VALID_AT = 14;
const size_t ALARM_AT = 15;
const size_t BYTES_PER_ROW = 8;

struct reading {
  double value;
  int32_t station;
  int16_t sensor;
  bool valid;
  bool alarm;
};

bool host_is_little_endian(void)
{
  const int probe = 1;
  const unsigned char* bytes = (const unsigned char*)&probe;

  return bytes[0] == 1;
}

// в файле big-endian: на little-endian машине копируем задом наперёд
void copy_be(void* dst, const void* src, size_t n)
{
  if (dst == NULL || src == NULL) {
    return;
  }

  unsigned char* to = dst;
  const unsigned char* from = src;
  bool reverse = host_is_little_endian();

  for (size_t i = 0; i < n; i++) {
    to[i] = reverse ? from[n - 1 - i] : from[i];
  }
}

bool save_reading(FILE* f, const struct reading* r)
{
  if (f == NULL || r == NULL) {
    return false;
  }

  unsigned char buf[RECORD_SIZE];

  copy_be(buf + VALUE_AT, &r->value, sizeof(r->value));
  copy_be(buf + STATION_AT, &r->station, sizeof(r->station));
  copy_be(buf + SENSOR_AT, &r->sensor, sizeof(r->sensor));
  buf[VALID_AT] = r->valid;
  buf[ALARM_AT] = r->alarm;

  return fwrite(buf, 1, RECORD_SIZE, f) == RECORD_SIZE;
}

bool load_reading(FILE* f, struct reading* r)
{
  if (f == NULL || r == NULL) {
    return false;
  }

  unsigned char buf[RECORD_SIZE];

  if (fread(buf, 1, RECORD_SIZE, f) != RECORD_SIZE) {
    return false;
  }

  copy_be(&r->value, buf + VALUE_AT, sizeof(r->value));
  copy_be(&r->station, buf + STATION_AT, sizeof(r->station));
  copy_be(&r->sensor, buf + SENSOR_AT, sizeof(r->sensor));
  r->valid = buf[VALID_AT] != 0;
  r->alarm = buf[ALARM_AT] != 0;

  return true;
}

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

void print_reading(const struct reading* r)
{
  if (r == NULL) {
    return;
  }

  printf("value = %g, station = %d, sensor = %d, valid = %d, alarm = %d\n",
         r->value, r->station, r->sensor, r->valid, r->alarm);
}

int main()
{
  struct reading r = {21.5, 1001, 3, true, false};

  FILE* f = fopen("reading.bin", "wb");

  if (f == NULL) {
    fprintf(stderr, "cannot open reading.bin\n");
    return 1;
  }

  bool saved = save_reading(f, &r);
  fclose(f);

  if (!saved) {
    fprintf(stderr, "cannot write reading.bin\n");
    return 1;
  }

  f = fopen("reading.bin", "rb");

  if (f == NULL) {
    fprintf(stderr, "cannot open reading.bin\n");
    return 1;
  }

  struct reading loaded;
  struct reading as_is;

  bool ok = load_reading(f, &loaded);
  rewind(f);
  ok = ok && fread(&as_is, sizeof(as_is), 1, f) == 1;  // без разбора полей
  fclose(f);

  if (!ok) {
    fprintf(stderr, "cannot read reading.bin\n");
    return 1;
  }

  printf("memory:\n");
  dump_bytes(&r, sizeof(r));
  printf("reading.bin:\n");
  dump_bytes(&as_is, sizeof(as_is));

  printf("\nload_reading: ");
  print_reading(&loaded);
  printf("fread as is:  ");
  print_reading(&as_is);

  return 0;
}
