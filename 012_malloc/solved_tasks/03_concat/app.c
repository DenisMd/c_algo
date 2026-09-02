#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000

void read_array(int a[], size_t* n)
{
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

void read_input(int a[], size_t* na, int b[], size_t* nb)
{
  printf("Enter na, a, nb, b: ");
  read_array(a, na);
  read_array(b, nb);
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

int* concat(const int* a, size_t na, const int* b, size_t nb)
{
  size_t n = na + nb;
  if (n == 0) {
    return NULL; // нечего выделять
  }

  int* res = malloc(n * sizeof(int));
  if (res == NULL) {
    return NULL; // память не дали — решает вызывающий
  }

  if (na > 0) {
    memcpy(res, a, na * sizeof(int));
  }
  if (nb > 0) {
    memcpy(res + na, b, nb * sizeof(int)); // хвост — со смещением на na элементов
  }

  return res;
}

int main()
{
  int a[MAX_N], b[MAX_N];
  size_t na, nb;

  read_input(a, &na, b, &nb);
  assert(na <= MAX_N && nb <= MAX_N); // read_input это гарантирует

  int* res = concat(a, na, b, nb);
  if (res == NULL && na + nb > 0) {
    fprintf(stderr, "Allocation failed!\n");
    return 1;
  }

  print_array(res, na + nb);

  free(res);
  res = NULL;

  return 0;
}
