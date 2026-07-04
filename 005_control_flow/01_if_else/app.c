#include <stdio.h>

int main()
{
  int age;
  printf("Enter user's age: ");
  scanf("%d", &age);

  if (age < 0) {
    printf("Incorrect age\n");
  } else if (age < 13) {
    printf("Child\n");
  } else if (age < 18) {
    printf("Young\n");
  } else if (age < 40) {
    printf("Adult\n");
  } else {
    printf("Old man\n");
  }

  return 0;
}