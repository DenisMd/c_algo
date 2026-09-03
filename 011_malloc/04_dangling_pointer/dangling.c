#include <stdio.h>
#include <stdlib.h>

// в файле НАРОЧНО две ошибки, gcc выдаёт на них 2 предупреждения
//
// обычная сборка (видно, как значение сначала живёт, потом затирается):
//   gcc -Wall -Wextra -std=c17 -g -o dangling dangling.c
//
// под санитайзером (ловит обращение к мёртвому кадру сразу, до затирания):
//   gcc -Wall -Wextra -std=c17 -fsanitize=address -g -o dangling dangling.c
//   ASAN_OPTIONS=detect_stack_use_after_return=1 ./dangling

void sneaky(int** out)  // адрес локальной переменной уезжает наружу
{
  int x = 42;
  *out = &x;  // x умрёт при выходе из функции, а указатель на неё останется
}

void clobber(void)  // такой же кадр стека -> y ложится ровно на место x
{
  int y = -1;
  printf("clobber: y = %d at %p\n", y, (void*)&y);
}

int* good_malloc(void)  // куча живёт, пока её не освободят
{
  int* p = malloc(sizeof(int));

  if (p == NULL) {
    exit(1);
  }

  *p = 42;
  return p;  // free делает вызывающий
}

void good_out(int* out)  // память выделяет вызывающий, функция только пишет
{
  *out = 42;
}

int* bad(void)  // gcc сам ловит это и заменяет возврат на NULL
{
  int x = 42;
  return &x;
}

int main()
{
  int* dangling;
  sneaky(&dangling);

  printf("right after sneaky(): *dangling = %d\n",
         *dangling);  // кадр ещё не тронут
  clobber();
  printf("after clobber():      *dangling = %d\n\n",
         *dangling);  // значение затёрто

  int* heap = good_malloc();
  printf("from heap:      %d\n", *heap);
  free(heap);

  int local;
  good_out(&local);
  printf("from out-param: %d\n\n", local);

  printf("now calling bad()...\n");
  fflush(stdout);

  int* null_ptr = bad();
  printf("*null_ptr = %d\n", *null_ptr);  // сегфолт: bad() вернула NULL

  return 0;
}
