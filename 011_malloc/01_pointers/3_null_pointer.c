#include <stdio.h>

int main()
{
  int* ptr = NULL;

  printf("ptr = %p\n", (void*)ptr);

  if (ptr == NULL) {  // так проверяют ВСЕГДА перед разыменованием
    printf("ptr пустой, читать по нему нельзя\n");
  }

  if (!ptr) {  // короткая запись того же самого
    printf("!ptr = то же условие\n\n");
  }

  int some_var = 42;
  ptr = &some_var;  // теперь указатель валидный

  if (ptr) {
    printf("*ptr = %d\n\n", *ptr);
  }

  ptr = NULL;  // хорошая привычка: обнулять указатель, когда он больше не нужен

  printf("сейчас будет разыменование NULL...\n");
  fflush(stdout);  // иначе вывод потеряется при падении

  // СЕГФОЛТ: обращение по адресу 0 запрещено ядром
  printf("*ptr = %d\n", *ptr);

  printf("эта строка не выполнится никогда\n");

  return 0;
}
