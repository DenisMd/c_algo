#include <stdio.h>

int main()
{
  unsigned int x = 0x01020304;
  unsigned char* p = (unsigned char*)&x;

  printf("x = 0x%08X\n", x);
  printf("bytes in memory: %02X %02X %02X %02X\n", p[0], p[1], p[2], p[3]);

  if (p[0] == 0x04) {
    printf("little endian\n");
  } else if (p[0] == 0x01) {
    printf("big endian\n");
  } else {
    printf("unknown\n");
  }

  return 0;
}
