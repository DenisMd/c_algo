#include <stdio.h>

enum {
  JANUARY = 1,
  FEBRUARY = 2,
  MARCH = 3,
  APRIL = 4,
  MAY = 5,
  JUNE = 6,
  JULY = 7,
  AUGUST = 8,
  SEPTEMBER = 9,
  OCTOBER = 10,
  NOVEMBER = 11,
  DECEMBER = 12,
};

int main()
{
  int month;
  printf("Enter month number (1–12): ");
  if (scanf("%d", &month) != 1) {
    fprintf(stderr, "Incorrect input!\n");
    return 1;
  }

  switch (month) {
    case DECEMBER:
    case JANUARY:
    case FEBRUARY:
      printf("Winter\n");
      break;
    case MARCH:
    case APRIL:
    case MAY:
      printf("Spring\n");
      break;
    case JUNE:
    case JULY:
    case AUGUST:
      printf("Summer\n");
      break;
    case SEPTEMBER:
    case OCTOBER:
    case NOVEMBER:
      printf("Autumn\n");
      break;
    default:
      fprintf(stderr, "Invalid month number.\n");
      return 2;
  }

  return 0;
}