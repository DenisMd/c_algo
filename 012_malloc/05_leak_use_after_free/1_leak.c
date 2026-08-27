#include <stdio.h>
#include <stdlib.h>

// ПРОГРАММА НАРОЧНО ТЕЧЁТ, санитайзер печатает отчёт при выходе:
//   gcc -Wall -Wextra -std=c17 -fsanitize=address -g -o leak leak.c
//   ./leak

void forgot_free(void) // классика: выделили и забыли
{
  int *p = malloc(100 * sizeof(int));

  if(p == NULL) {
    exit(1);
  }

  p[0] = 42;
  printf("forgot_free:    %zu bytes lost at %p\n", 100 * sizeof(int), (void*)p);
} // p исчезает вместе с функцией, а память остаётся занятой до конца процесса

void overwrite_ptr(void) // вторая классика: затёрли единственный указатель на блок
{
  int *p = malloc(sizeof(int));

  if(p == NULL) {
    exit(1);
  }

  printf("overwrite_ptr:  first block at %p\n", (void*)p);

  p = malloc(sizeof(int)); // адрес первого блока потерян навсегда

  printf("overwrite_ptr:  second block at %p\n", (void*)p);

  free(p); // освободили только второй
}

int main()
{
  forgot_free();
  overwrite_ptr();

  printf("\nexiting\n");

  return 0;
}
