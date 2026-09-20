#include "dyn_array.h"

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

// static: эти имена не видны из других .c файлов
static const size_t INITIAL_CAPACITY = 4;
static const size_t GROWTH_FACTOR = 2;

struct dyn_array {
  int* data;
  size_t size;
  size_t capacity;
};

struct dyn_array* dyn_array_create(void)
{
  struct dyn_array* arr = malloc(sizeof(struct dyn_array));

  if (arr == NULL) {
    return NULL;
  }

  arr->data = NULL;
  arr->size = 0;
  arr->capacity = 0;

  return arr;
}

void dyn_array_destroy(struct dyn_array* arr)
{
  if (arr == NULL) {
    return;
  }

  free(arr->data);
  free(arr);
}

size_t dyn_array_size(const struct dyn_array* arr)
{
  if (arr == NULL) {
    return 0;
  }

  return arr->size;
}

size_t dyn_array_capacity(const struct dyn_array* arr)
{
  if (arr == NULL) {
    return 0;
  }

  return arr->capacity;
}

int dyn_array_get(const struct dyn_array* arr, size_t index)
{
  assert(arr != NULL && index < arr->size);
  return arr->data[index];
}

bool dyn_array_set(struct dyn_array* arr, size_t index, int value)
{
  if (arr == NULL || index >= arr->size) {
    return false;
  }

  arr->data[index] = value;
  return true;
}

static bool grow(struct dyn_array* arr)
{
  if (arr == NULL) {
    return false;
  }

  if (arr->capacity > SIZE_MAX / GROWTH_FACTOR / sizeof(int)) {
    return false;  // иначе размер блока в байтах не влезет в size_t
  }

  size_t new_capacity =
      arr->capacity == 0 ? INITIAL_CAPACITY : arr->capacity * GROWTH_FACTOR;
  int* tmp = realloc(arr->data, new_capacity * sizeof(int));

  if (tmp == NULL) {
    return false;  // старый блок цел, массив не испорчен
  }

  arr->data = tmp;
  arr->capacity = new_capacity;

  return true;
}

bool dyn_array_push(struct dyn_array* arr, int value)
{
  if (arr == NULL) {
    return false;
  }

  if (arr->size == arr->capacity && !grow(arr)) {
    return false;
  }

  arr->data[arr->size] = value;
  arr->size++;

  return true;
}

bool dyn_array_pop(struct dyn_array* arr, int* out)
{
  if (arr == NULL || out == NULL || arr->size == 0) {
    return false;
  }

  arr->size--;
  *out = arr->data[arr->size];

  return true;
}
