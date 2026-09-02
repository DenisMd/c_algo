#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

void read_input(int a[], size_t* n)
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

int* unique(const int* a, size_t n, size_t* out_n)
{
  *out_n = 0;

  if (n == 0) {
    return NULL; // нечего выделять
  }

  int* u = malloc(n * sizeof(int)); // худший случай: все элементы разные
  if (u == NULL) {
    return NULL; // память не дали — решает вызывающий
  }

  size_t m = 0;
  for (size_t i = 0; i < n; i++) {
    bool seen = false;
    for (size_t j = 0; j < m; j++) {
      if (u[j] == a[i]) {
        seen = true;
        break;
      }
    }
    if (!seen) {
      u[m++] = a[i];
    }
  }

  int* tmp = realloc(u, m * sizeof(int)); // отдаём хвост назад: n -> m
  if (tmp != NULL) { // если ужать не вышло, старый блок остаётся рабочим
    u = tmp;
  }

  *out_n = m;
  return u;
}

int main()
{
  int a[MAX_N];
  size_t n;

  read_input(a, &n);
  assert(n <= MAX_N); // read_input это гарантирует

  size_t m;
  int* u = unique(a, n, &m);
  if (u == NULL && n > 0) {
    fprintf(stderr, "Allocation failed!\n");
    return 1;
  }
  assert(m <= n); // уникальных не больше, чем элементов

  printf("%zu\n", m);
  print_array(u, m);

  free(u);
  u = NULL;

  return 0;
}
