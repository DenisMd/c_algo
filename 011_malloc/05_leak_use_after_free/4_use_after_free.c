#include <stdio.h>
#include <stdlib.h>

// ПРОГРАММА НАРОЧНО ОБРАЩАЕТСЯ К ОСВОБОЖДЁННОЙ ПАМЯТИ
//
//   gcc -Wall -Wextra -std=c17 -g -o uaf use_after_free.c
//   ./uaf
//
// санитайзер показывает и место обращения, и место освобождения:
//   gcc -Wall -Wextra -std=c17 -fsanitize=address -g -o uaf use_after_free.c
//   ./uaf

void simple_case(void)  // определение по учебнику
{
  int* p = malloc(sizeof(int));

  if (p == NULL) {
    exit(1);
  }

  *p = 42;
  free(p);  // блок вернулся аллокатору, но p всё ещё хранит его адрес

  printf("simple: *p = %d\n", *p);  // use-after-free: читаем чужое

  // free(p); // а это ещё и double free - аллокатор упадёт сам
}

int* grow(int* arr, size_t* cap)
{
  size_t new_cap = (*cap == 0) ? 4 : *cap * 2;
  int* tmp = realloc(arr, new_cap * sizeof(int));

  if (tmp == NULL) {
    free(arr);
    exit(1);
  }

  *cap = new_cap;
  return tmp;
}

void realloc_case(void)  // так наступают на грабли в реальном коде
{
  int* arr = NULL;
  size_t size = 0;
  size_t cap = 0;

  for (int i = 0; i < 4; i++) {
    if (size == cap) {
      arr = grow(arr, &cap);
    }

    arr[size++] = i;
  }

  // мешает realloc расширить блок на месте, иначе адрес не сменится
  int* blocker = malloc(64);
  int* first = arr;

  printf("\nbefore: arr = %p, first = %p, *first = %d\n", (void*)arr,
         (void*)first, *first);

  // на пятом элементе сработает realloc и блок переедет
  for (int i = 4; i < 8; i++) {
    if (size == cap) {
      arr = grow(arr, &cap);
    }

    arr[size++] = i;
  }

  printf("after:  arr = %p, first = %p, *first = %d\n", (void*)arr,
         (void*)first, *first);

  *first = -1;  // запись в освобождённую память - самый неприятный вариант

  printf("arr[0] = %d (а мы писали -1 совсем не туда)\n", arr[0]);

  free(blocker);
  free(arr);
}
// правильно: хранить ИНДЕКС, он переезд переживает
void realloc_case_fixed(void)
{
  int* arr = NULL;
  size_t size = 0;
  size_t cap = 0;

  for (int i = 0; i < 8; i++) {
    if (size == cap) {
      arr = grow(arr, &cap);
    }

    arr[size++] = i;
  }

  size_t first = 0;

  arr[first] = -1;

  printf("\nfixed:  arr[0] = %d\n", arr[0]);

  free(arr);
}

int main()
{
  simple_case();
  realloc_case();
  realloc_case_fixed();

  return 0;
}
