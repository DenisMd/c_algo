#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_input(int* n)
{
  printf("n = ");

  if (scanf("%d", n) != 1 || *n <= 0) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
}

int* make_malloc(size_t n)
{
  int* arr = malloc(n * sizeof(int));  // cast void* -> int*

  if (arr == NULL) {  // проверять надо всегда
    fprintf(stderr, "malloc failed!\n");
    exit(1);
  }

  /*
  for(size_t i=0; i < n; i++) {
    arr[i] = 0;
  }*/
  memset(arr, 0, n);

  return arr;
}

/*
calloc часто быстрее «malloc + обнулить вручную»,
потому что свежие страницы от ядра уже обнулены (ядро обязано их обнулить, чтобы
данные одного процесса не утекли в другой) — и обнулять повторно не надо.
*/
int* make_calloc(size_t n)
{
  int* arr = calloc(n, sizeof(int));

  if (arr == NULL) {
    fprintf(stderr, "calloc failed!\n");
    exit(1);
  }

  return arr;
}

void print_array(const char* name, const int* arr, size_t n)
{
  printf("%s:", name);

  for (size_t i = 0; i < n; i++) {
    printf(" %d", arr[i]);
  }

  printf("\n");
}

int main()
{
  int n;
  read_input(&n);

  int* a = make_malloc(n);
  int* b = make_calloc(n);

  print_array("after malloc (undefined)", a, n);
  print_array("after calloc (zeroed)", b, n);

  for (size_t i = 0; i < (size_t)n; i++) {
    a[i] = (int)i * 10;
  }

  print_array("after fill", a, n);

  printf("allocated %zu bytes each\n", n * sizeof(int));

  free(a);  // на каждый malloc/calloc ровно один free
  free(b);

  a = NULL;  // чтобы не остался висячий указатель
  b = NULL;

  return 0;
}
