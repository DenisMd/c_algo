#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int rle(const int* a, size_t n, int** out_vals, int** out_runs, size_t* out_n)
{
  *out_vals = NULL;
  *out_runs = NULL;
  *out_n = 0;

  if (n == 0) {
    return 0; // пустой вход — не ошибка, просто нечего кодировать
  }

  size_t k = 1; // число серий: первый проход, чтобы malloc был сразу нужного размера
  for (size_t i = 1; i < n; i++) {
    if (a[i] != a[i - 1]) {
      k++;
    }
  }

  int* vals = malloc(k * sizeof(int));
  int* runs = malloc(k * sizeof(int));
  if (vals == NULL || runs == NULL) {
    free(vals); // упала вторая аллокация — первую нельзя терять; free(NULL) безопасен
    free(runs);
    return -1;
  }

  size_t j = 0;
  vals[0] = a[0];
  runs[0] = 1;
  for (size_t i = 1; i < n; i++) {
    if (a[i] == a[i - 1]) {
      runs[j]++;
    } else {
      j++;
      vals[j] = a[i];
      runs[j] = 1;
    }
  }
  assert(j + 1 == k); // серий ровно столько, сколько насчитал первый проход

  *out_vals = vals;
  *out_runs = runs;
  *out_n = k;
  return 0;
}

int* rle_decode(const int* vals, const int* runs, size_t n, size_t* out_n)
{
  *out_n = 0;

  if (n == 0) {
    return NULL; // нечего разворачивать
  }

  size_t total = 0;
  for (size_t i = 0; i < n; i++) {
    if (runs[i] <= 0) {
      return NULL; // битые данные: серия не может быть пустой или отрицательной
    }
    total += (size_t)runs[i];
  }

  int* a = malloc(total * sizeof(int));
  if (a == NULL) {
    return NULL; // память не дали — решает вызывающий
  }

  size_t p = 0;
  for (size_t i = 0; i < n; i++) {
    for (int r = 0; r < runs[i]; r++) {
      a[p++] = vals[i];
    }
  }
  assert(p == total); // заполнили ровно то, что выделили

  *out_n = total;
  return a;
}

int main()
{
  int a[MAX_N];
  size_t n;

  read_input(a, &n);
  assert(n <= MAX_N); // read_input это гарантирует

  int* vals;
  int* runs;
  size_t k;

  if (rle(a, n, &vals, &runs, &k) != 0) {
    fprintf(stderr, "Allocation failed!\n");
    return 1;
  }

  printf("%zu\n", k);
  print_array(vals, k);
  print_array(runs, k);

  size_t m;
  int* back = rle_decode(vals, runs, k, &m);
  if (back == NULL && k > 0) {
    fprintf(stderr, "Decode failed!\n");
    free(vals);
    free(runs);
    return 1;
  }
  // круг замкнулся: раскодированное совпадает с исходным
  assert(m == n && (n == 0 || memcmp(a, back, n * sizeof(int)) == 0));

  print_array(back, m);

  free(back);
  free(vals);
  free(runs);
  back = NULL;
  vals = NULL;
  runs = NULL;

  return 0;
}
