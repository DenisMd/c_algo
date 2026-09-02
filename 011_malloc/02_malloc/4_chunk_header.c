#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

// glibc хранит служебный заголовок ПЕРЕД тем адресом, который вернул malloc:
//
//   [ prev_size 8 ][ size 8 ][ данные... ]
//                            ^
//                            этот адрес и получает пользователь
//
// в поле size младшие 3 бита заняты флагами, поэтому их маскируем

size_t chunk_size(void* ptr)  // ЭТО ДЕТАЛЬ РЕАЛИЗАЦИИ GLIBC, а не стандарт C
{
  size_t raw = *((size_t*)ptr - 1);  // шаг назад на 8 байт = поле size UB!!
  return raw & ~(size_t)0x7;
}

// 3 младших бита: PREV_INUSE, IS_MMAPPED, NON_MAIN_ARENA
size_t chunk_flags(void* ptr) { return *((size_t*)ptr - 1) & 0x7; }

void show(size_t bytes)
{
  void* p = malloc(bytes);

  if (p == NULL) {
    exit(1);
  }

  printf("request %5zu -> chunk %5zu, usable %5zu, flags %zu\n", bytes,
         chunk_size(p),
         malloc_usable_size(p),  // законный способ спросить то же самое
         chunk_flags(p));

  free(p);
}

int main()
{
  printf("sizeof(size_t) = %zu\n\n", sizeof(size_t));

  // на нетронутой куче блоки ложатся вплотную: расстояние = размер чанка
  char* a = malloc(100);
  char* b = malloc(100);

  printf("a     = %p\n", (void*)a);
  printf("b     = %p\n", (void*)b);
  printf("b - a = %td bytes (chunk of a = %zu)\n\n", b - a, chunk_size(a));

  free(a);
  free(b);

  size_t sizes[] = {1, 8, 24, 25, 100, 1000};

  for (size_t i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
    show(sizes[i]);
  }

  // именно поэтому free() принимает ТОЛЬКО указатель: размер он читает сам
  int* arr = malloc(10 * sizeof(int));

  printf("\narr of 10 ints: asked %zu, chunk %zu\n", 10 * sizeof(int),
         chunk_size(arr));

  free(arr);  // free знает про 48, хотя мы просили 40

  return 0;
}
