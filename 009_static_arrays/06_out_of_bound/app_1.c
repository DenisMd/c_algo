#include <stdio.h>

#define ARR_SIZE 10

int main()
{
  int arr[ARR_SIZE];

  for(size_t i=0; i < ARR_SIZE; i++) {
    arr[i] = (int)i;
  }

  printf("== рядом с границей (UB, но без краха) ==\n");
  for(size_t i = ARR_SIZE; i < ARR_SIZE + 4; i++) {
    printf("arr[%zu] = %d  (за границей!)\n", i, arr[i]); // UB
  }
  fflush(stdout); // иначе буфер пропадёт при segfault ниже

  // --- далеко за границей: адрес не отображён в память процесса ---
  // тут ОС ловит обращение -> SIGSEGV (segfault). Крах — на самом деле
  // это ПОВЕЗЛО: баг заметен сразу, а не тихо портит данные.
  printf("== далеко за границей (сейчас будет segfault) ==\n");
  volatile int x = arr[10000000]; // ~40 МБ за концом массива
  printf("не дойдём сюда: %d\n", x);

  return 0;
}
