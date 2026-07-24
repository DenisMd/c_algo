#include <stdio.h>

// (a/b)*b + a%b == a
void mod_print(int a, int b)
{
  printf("%d div %d = %d\n",a,b,a/b);
  printf("%d mod %d = %d\n\n",a,b,a%b);
}

int main()
{
  mod_print(5,3);
  mod_print(-5,3);
  mod_print(5,-3);
  mod_print(-5,-3);
  mod_print(3,5);
  mod_print(0,3);
  return 0;
}