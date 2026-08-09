#include <stdio.h>

int numbers[4] = {0x01020304, 0x05060708, 0xAABBCCDD, 0x11223344};

int main()
{
  printf("&numbers = %p\n", (void *)numbers);
  printf("sizeof   = %zu bytes\n", sizeof(numbers));

  FILE *f = fopen("dump.bin", "wb");
  if (f == NULL)
  {
    printf("cannot open file\n");
    return 1;
  }
  fwrite(numbers, sizeof(numbers), 1, f);
  fclose(f);

  return 0;
}
