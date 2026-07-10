#include <stdio.h>
#include <stdlib.h>

void read_input(long long *number)
{
  printf("Enter card number: ");
  if (scanf("%lld", number) != 1) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
  if (*number <= 0) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
}

int luhn_check(long long number)
{
  int sum = 0;
  int position = 0;  // позиция цифры справа: 0, 1, 2, ...

  while (number > 0) {
    int digit = number % 10;

    if (position % 2 == 1) {  // каждая вторая цифра, начиная со второй справа
      digit *= 2;
      if (digit > 9) {
        digit -= 9;
      }
    }

    sum += digit;
    number /= 10;
    position++;
  }

  return sum % 10 == 0;
}

int main()
{
  long long number;

  read_input(&number);

  printf("%d\n", luhn_check(number));

  return 0;
}
