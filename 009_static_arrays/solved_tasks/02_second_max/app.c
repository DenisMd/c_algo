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

bool second_max(const int a[], size_t n, int* second)
{
  if (n < 2) {
    return false;
  }

  int first = a[0];  // текущий максимум
  int sec = 0;       // второй максимум (валиден только при have == true)
  bool have = false; // нашли ли уже второй максимум

  for (size_t i = 1; i < n; i++) {
    int x = a[i];
    if (x > first) {
      sec = first;   // старый максимум становится вторым
      have = true;
      first = x;
    } else if (x < first && (!have || x > sec)) {
      sec = x;
      have = true;
    }
    // x == first — дубликат максимума, второй максимум не трогаем
  }

  if (have) {
    *second = sec;
  }
  return have;
}

int main()
{
  int a[MAX_N];
  size_t n;

  read_input(a, &n);
  assert(n <= MAX_N);

  int second;
  if (second_max(a, n, &second)) {
    printf("%d\n", second);
  } else {
    printf("нет второго максимума\n");
  }

  return 0;
}
