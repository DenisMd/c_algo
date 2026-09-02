#include <stdio.h>
#include <stdlib.h>

// ps -o pid,vsz,rss,comm -p $(pgrep -n a.out)
int main(void)
{
  size_t n = 256ull * 1024 * 1024; /* 256 M элементов = 1 ГБ */
  int* p = malloc(n * sizeof(*p));
  if (p == NULL) {
    printf("не вышло\n");
    return 1;
  }

  printf("выделил 1 ГБ. Enter...\n");
  getchar();

  /* трогаем по одному байту на страницу */
  for (size_t i = 0; i < n; i += 1024) {
    p[i] = 1;
  }

  printf("потрогал. Enter...\n");
  getchar();

  free(p);
  return 0;
}