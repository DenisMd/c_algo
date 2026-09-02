#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000

void read_input(int a[], size_t* n, size_t* from, size_t* to)
{
  printf("Enter n: ");
  if (scanf("%zu", n) != 1) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
  if (*n > MAX_N) {
    fprintf(stderr, "Too many elements (max %d)!\n", MAX_N);
    exit(1);
  }
  for (size_t i = 0; i < *n; i++) {
    if (scanf("%d", &a[i]) != 1) {
      fprintf(stderr, "Incorrect input!\n");
      exit(1);
    }
  }
  if (scanf("%zu %zu", from, to) != 2) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
  if (*from > *to || *to > *n) {
    fprintf(stderr, "Need from <= to <= n!\n");
    exit(1);
  }
}

void print_array(const int a[], size_t n)
{
  for (size_t i = 0; i < n; i++) {
    printf("%d", a[i]);
    if (i + 1 < n) {
      printf(" ");
    }
  }
  printf("\n");
}

int* slice(const int* a, size_t n, size_t from, size_t to)
{
  if (from > to || to > n) {
    return NULL; // не доверяем вызывающему: иначе читали бы за пределами a
  }

  size_t len = to - from;
  if (len == 0) {
    return NULL; // пустой срез — нечего выделять
  }

  int* s = malloc(len * sizeof(int));
  if (s == NULL) {
    return NULL; // память не дали — решает вызывающий
  }

  memcpy(s, a + from, len * sizeof(int)); // ровно len элементов, начиная с a[from]

  return s;
}

int main()
{
  int a[MAX_N];
  size_t n, from, to;

  read_input(a, &n, &from, &to);
  assert(from <= to && to <= n); // read_input это гарантирует

  size_t len = to - from;

  int* s = slice(a, n, from, to);
  if (s == NULL && len > 0) {
    fprintf(stderr, "Allocation failed!\n");
    return 1;
  }

  print_array(s, len);

  free(s);
  s = NULL;

  return 0;
}
