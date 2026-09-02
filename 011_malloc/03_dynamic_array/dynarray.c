#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// сколько чисел введут - заранее неизвестно, поэтому массив растёт по ходу дела

int *grow(int *arr, size_t size, size_t *cap)
{
  size_t new_cap = (*cap == 0) ? 4 : *cap * 2; // удваиваем: рост по +1 дал бы O(n^2) копирований

  int *tmp = realloc(arr, new_cap * sizeof(int)); // realloc(NULL, n) работает как malloc(n)

  if(tmp == NULL) { // результат ВСЕГДА в новую переменную: при ошибке старый блок ещё жив
    printf("  realloc failed, doing it by hand\n");

    tmp = malloc(new_cap * sizeof(int)); // руками делаем то же, что realloc делает внутри

    if(tmp == NULL) {
      free(arr);
      fprintf(stderr, "out of memory!\n");
      exit(1);
    }

    if(arr != NULL) {
      memcpy(tmp, arr, size * sizeof(int)); // копируем только занятую часть, не всю ёмкость
      free(arr);                            // старый блок отпускаем ПОСЛЕ копирования
    }
  }

  printf("  grow %zu -> %zu, data at %p\n", *cap, new_cap, (void*)tmp);

  *cap = new_cap;
  return tmp;
}

int main()
{
  int *arr = NULL;
  size_t size = 0; // сколько чисел реально лежит
  size_t cap = 0;  // сколько влезет без нового realloc
  int x;

  printf("enter numbers, Ctrl+D to stop:\n");

  while(scanf("%d", &x) == 1) {
    if(size == cap) {
      arr = grow(arr, size, &cap); // старый указатель после realloc использовать НЕЛЬЗЯ
    }

    arr[size++] = x;
  }

  if(size == 0) {
    printf("nothing to do\n");
    free(arr);
    return 0;
  }

  int *tmp = realloc(arr, size * sizeof(int)); // отдаём назад хвост: cap -> size

  if(tmp != NULL) { // если ужать не вышло, старый блок остаётся рабочим
    arr = tmp;
  }

  printf("\nread %zu numbers, capacity now %zu\n", size, size);

  for(size_t i=0; i < size; i++) {
    printf("arr[%zu] = %d\n", i, arr[i]);
  }

  free(arr);
  arr = NULL;

  return 0;
}
