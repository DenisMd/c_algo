#include <assert.h>
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

void reverse(int a[], size_t n)
{
  for (size_t i = 0; i < n / 2; i++) {
    int tmp = a[i];
    a[i] = a[n - 1 - i];
    a[n - 1 - i] = tmp;
  }
}

int main()
{
  int a[MAX_N];
  size_t n;

  read_input(a, &n);
  assert(n <= MAX_N); // read_input гарантирует это — не вышли за буфер a[MAX_N]

  reverse(a, n);

  print_array(a, n);

  return 0;
}
