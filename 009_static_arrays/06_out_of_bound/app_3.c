#include <stdio.h>

// Точка 3: самая частая причина выхода за границу — цикл с "<=".

#define ARR_SIZE 10

int main()
{
  int arr[ARR_SIZE];

  // БАГ: "<=" делает лишнюю итерацию и пишет arr[ARR_SIZE] за границу
  for(size_t i=0; i <= ARR_SIZE; i++) { // <-- здесь ошибка
    arr[i] = (int)(i * i);              // на i==ARR_SIZE это UB
  }
  
  for(size_t i=0; i < ARR_SIZE; i++) {
    printf("arr[%zu] = %d\n", i, arr[i]);
  }
  fflush(stdout); // печать успеет выйти до возможного "stack smashing detected"

  // На дистрибутивах с -fstack-protector по умолчанию запись arr[ARR_SIZE]
  // портит стековый canary, и при выходе из main процесс упадёт с
  // "*** stack smashing detected ***". Это и есть пойманный off-by-one.
  return 0;
}
