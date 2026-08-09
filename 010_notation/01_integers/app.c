#include <stdio.h>

int main()
{
  int dec = 255;
  int hex = 0xFF;
  int oct = 0377;

  printf("dec = %d\n", dec);
  printf("hex = %d\n", hex);
  printf("oct = %d\n", oct);

  printf("\n");

  int n = 255;

  printf("%%d  -> %d\n", n);
  printf("%%x  -> %x\n", n);
  printf("%%X  -> %X\n", n);
  printf("%%o  -> %o\n", n);

  printf("\n");

  printf("%%#x -> %#x\n", n);
  printf("%%#o -> %#o\n", n);

  return 0;
}
