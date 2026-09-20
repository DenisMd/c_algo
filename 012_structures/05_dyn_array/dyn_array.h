#ifndef DYN_ARRAY_H
#define DYN_ARRAY_H

#include <stdbool.h>
#include <stddef.h>

struct dyn_array;  // поля скрыты в dyn_array.c, снаружи - только указатель

struct dyn_array* dyn_array_create(void);  // NULL, если не хватило памяти
void dyn_array_destroy(struct dyn_array* arr);

size_t dyn_array_size(const struct dyn_array* arr);
size_t dyn_array_capacity(const struct dyn_array* arr);

int dyn_array_get(const struct dyn_array* arr, size_t index);  // index < size
bool dyn_array_set(struct dyn_array* arr, size_t index, int value);

bool dyn_array_push(struct dyn_array* arr, int value);
bool dyn_array_pop(struct dyn_array* arr, int* out);

#endif
