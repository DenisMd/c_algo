#include <stdio.h>

/*
Расчёт процентной ставки по кредиту
    Если сумма меньше 100 000 – ставка 10% (рейтинг не важен).
    Если сумма от 100 000 до 500 000 – ставка 8% (рейтинг тоже не важен).
    Если сумма более 500 000 – ставка зависит от кредитного рейтинга:
        отличный → 6%
        хороший → 7%
        плохой → 9%
*/

const int SUM_THRESHOLD_MEDIUM = 100000;
const int SUM_THRESHOLD_LARGE = 500000;
enum {
  RATING_EXCELLENT = 1,
  RATING_GOOD = 2,
  RATING_POOR = 3,
};
const int RATE_BELOW_MEDIUM_SUM = 10;
const int RATE_MEDIUM_SUM = 8;
const int RATE_EXCELLENT_RATING = 6;
const int RATE_GOOD_RATING = 7;
const int RATE_POOR_RATING = 9;

int main()
{
  float sum;
  int rating;  // 1 - отличный, 2 - хороший, 3 - плохой
  float rate;

  printf("Enter loan amount: ");
  if (scanf("%f", &sum) != 1) {
    fprintf(stderr, "Invalid input\n");
    return 1;
  }
  printf("Credit rating (1-excellent, 2-good, 3-poor): ");
  if (scanf("%d", &rating) != 1) {
    fprintf(stderr, "Invalid input\n");
    return 1;
  }

  if (sum <= 0) {
    fprintf(stderr, "Incorrect sum: %f\n", sum);
    return 2;
  }

  // Дерево решений
  if (sum < SUM_THRESHOLD_MEDIUM) {
    rate = RATE_BELOW_MEDIUM_SUM;
  } else if (sum < SUM_THRESHOLD_LARGE) {
    rate = RATE_MEDIUM_SUM;
  } else {
    // только для больших сумм проверяем рейтинг
    switch (rating) {
      case RATING_EXCELLENT:
        rate = RATE_EXCELLENT_RATING;
        break;
      case RATING_GOOD:
        rate = RATE_GOOD_RATING;
        break;
      default:
        rate = RATE_POOR_RATING;
        break;
    }
  }

  printf("Final interest rate: %.1f%%\n", rate);
  return 0;
}
