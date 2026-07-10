#include <stdio.h>


void foo() {
  foo();
}

// ulimit -a
int main() {
  foo();
  return 0;
}