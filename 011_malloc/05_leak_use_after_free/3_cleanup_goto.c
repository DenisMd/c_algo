#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// k наибольших РАЗНЫХ чисел массива: два буфера и несколько путей выхода
//
//   gcc -Wall -Wextra -std=c17 -fsanitize=address -g -o cleanup cleanup_goto.c
//   ./cleanup

void sort_desc(int *arr, size_t n) // выбором, по убыванию
{
  for(size_t i=0; i < n; i++) {
    size_t max = i;

    for(size_t j=i+1; j < n; j++) {
      if(arr[j] > arr[max]) {
        max = j;
      }
    }

    int tmp = arr[i];
    arr[i] = arr[max];
    arr[max] = tmp;
  }
}

// ПЛОХО: на каждом return надо помнить весь список ресурсов
bool top_k_bad(const int *arr, size_t n, size_t k, int **out)
{
  if(n == 0 || k == 0 || k > n) {
    return false;
  }

  int *copy = malloc(n * sizeof(int)); // сортировать чужой массив нельзя, работаем с копией

  if(copy == NULL) {
    return false;
  }

  memcpy(copy, arr, n * sizeof(int));
  sort_desc(copy, n);

  int *res = malloc(k * sizeof(int));

  if(res == NULL) {
    free(copy);
    return false;
  }

  size_t found = 0;

  for(size_t i=0; i < n && found < k; i++) {
    if(i == 0 || copy[i] != copy[i-1]) {
      res[found++] = copy[i];
    }
  }

  if(found < k) {
    free(res);
    return false; // <-- ЗАБЫЛИ free(copy): утечка на этом пути
  }

  *out = res;

  free(copy);
  return true;
}

// ХОРОШО: как в ядре linux - один выход, метки по имени того, что откатывают,
// освобождение в обратном порядке захвата
bool top_k(const int *arr, size_t n, size_t k, int **out)
{
  bool ok = false;
  int *copy = NULL;
  int *res = NULL;

  if(n == 0 || k == 0 || k > n) {
    goto out;
  }

  copy = malloc(n * sizeof(int));

  if(copy == NULL) {
    goto out;
  }

  memcpy(copy, arr, n * sizeof(int));
  sort_desc(copy, n);

  res = malloc(k * sizeof(int));

  if(res == NULL) {
    goto out_free_copy;
  }

  size_t found = 0;

  for(size_t i=0; i < n && found < k; i++) {
    if(i == 0 || copy[i] != copy[i-1]) {
      res[found++] = copy[i];
    }
  }

  if(found < k) { // разных чисел не хватило
    goto out_free_res;
  }

  *out = res;
  res = NULL; // отдали наружу - теперь это забота вызывающего
  ok = true;

out_free_res:
  free(res); // free(NULL) безопасен, поэтому обнуления выше достаточно
out_free_copy:
  free(copy);
out:
  return ok;
}

void report(const char *tag, bool ok, const int *res, size_t k)
{
  printf("%s: ", tag);

  if(!ok) {
    printf("failed\n");
    return;
  }

  for(size_t i=0; i < k; i++) {
    printf("%d ", res[i]);
  }

  printf("\n");
}

int main()
{
  int arr[] = {7, 7, 7, 3, 9, 9, 1};
  size_t n = sizeof(arr) / sizeof(arr[0]);
  int *res = NULL;
  bool ok;

  ok = top_k_bad(arr, n, 3, &res);
  report("bad  k=3", ok, res, 3);
  free(res);
  res = NULL;

  ok = top_k_bad(arr, n, 5, &res); // разных чисел всего 4
  report("bad  k=5", ok, res, 5);  // <- на этом пути утечка

  printf("\n");

  ok = top_k(arr, n, 3, &res);
  report("good k=3", ok, res, 3);
  free(res);
  res = NULL;

  ok = top_k(arr, n, 5, &res);
  report("good k=5", ok, res, 5);

  return 0;
}
