#include <stdio.h>

int main()
{
  int some_var = 42;
  int* ptr = &some_var;

  printf("some_var = %d\n", some_var);
  printf("ptr = &%p\n", ptr);
  printf("*ptr = %d\n", *ptr);
  printf("sizeof(ptr) = %zu bytes\n", sizeof(ptr));

  return 0;
}