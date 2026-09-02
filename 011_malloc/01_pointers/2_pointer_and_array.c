#include <stdio.h>

#define ARR_SIZE 5

void print_arr(const int* ptr, size_t n)
{
  printf("внутри функции sizeof = %zu bytes\n", sizeof(ptr));  // 8, а не 20!

  // ТУТ очень тонкий момент с ptr+n - можно посмотреть на 1 элемент за
  // пределами
  for (const int* element = ptr; element != ptr + n; element++) {
    printf("arr[%td] = %d\n", element - ptr, *element);  // разность даёт индекс
  }
}

int main()
{
  int arr[ARR_SIZE] = {10, 20, 30, 40, 50};
  int* ptr = arr;  // имя массива = адрес его первого элемента, &arr[0] писать
                   // не обязательно

  printf("arr     = %p\n", arr);
  printf("&arr[0] = %p\n", &arr[0]);
  printf("ptr     = %p\n\n", ptr);

  printf("arr[2]     = %d\n", arr[2]);
  // это одно и то же: arr[i] == *(arr+i)
  printf("*(arr + 2) = %d\n", *(arr + 2));
  printf("ptr[2]     = %d\n", ptr[2]);
  printf("*(ptr + 2) = %d\n\n", *(ptr + 2));

  // арифметика указателей считает в ЭЛЕМЕНТАХ, а не в байтах
  printf("ptr     = %p\n", ptr);
  printf("ptr + 1 = %p (сдвиг на %zu bytes)\n\n", (ptr + 1), sizeof(int));

  // разность двух указателей на один массив = сколько ЭЛЕМЕНТОВ между ними
  int* first = &arr[0];
  int* last = &arr[ARR_SIZE - 1];

  // тип ptrdiff_t, печатается через %td
  printf("last - first = %td элементов\n", last - first);
  printf("в байтах     = %zu bytes\n\n", (size_t)(last - first) * sizeof(int));

  // на элемент "за концом" указывать можно, разыменовывать нельзя
  printf("длина массива через указатели = %td\n\n", (arr + ARR_SIZE) - arr);

  printf("sizeof(arr) = %zu bytes\n", sizeof(arr));  // 5 * 4 = 20
  // размер самого указателя
  printf("sizeof(ptr) = %zu bytes\n\n", sizeof(ptr));

  print_arr(arr, ARR_SIZE);  // длину приходится передавать отдельно

  return 0;
}
