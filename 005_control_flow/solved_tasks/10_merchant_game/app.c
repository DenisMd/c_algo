#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  const int max_day = 30;
  const int max_cargo = 50;

  int city = 1;
  int gold = 100;
  int cargo = 0;
  int day = 1;
  int debt = 0;
  int choice;
  int running = 1;

  printf("=== Торговец между городами ===\n");
  printf("Цель: максимизировать золото за %d ходов.\n", max_day);

  while (running) {
    int c;
    int buy_price;
    int sell_price;
    int best_city = 1;
    int best_sell = 0;

    if (debt > 0) {
      int interest = debt / 10;
      if (interest < 1) {
        interest = 1;
      }
      if (gold >= interest) {
        gold -= interest;
        printf("Проценты по долгу: -%d золота.\n", interest);
      } else {
        printf("\nНе хватает золота на проценты по долгу. Игра окончена.\n");
        running = 0;
        break;
      }
    }

    printf("\n=== День %d | Город %d | Золото: %d | Товар: %d | Долг: %d ===\n",
           day, city, gold, cargo, debt);
    printf("Цены сегодня:\n");

    best_city = 1;
    best_sell = 0;
    for (c = 1; c <= 4; c++) {
      buy_price = 10 + c * 3 + (day % 5) * c;
      sell_price = buy_price - 3;
      if (sell_price > best_sell) {
        best_sell = sell_price;
        best_city = c;
      }
    }

    for (c = 1; c <= 4; c++) {
      buy_price = 10 + c * 3 + (day % 5) * c;
      sell_price = buy_price - 3;

      printf("  Город %d: покупка %d, продажа %d", c, buy_price, sell_price);
      if (c == city) {
        printf("  <- вы здесь");
      }
      if (c == best_city && c != city) {
        printf("  <- выгодно везти!");
      }
      printf("\n");
    }

    if (day >= max_day) {
      printf("\n30 ходов истекли.\n");
      break;
    }

    printf("\n[1] Купить  [2] Продать  [3] Переехать  [4] Взять кредит  [0] Выход\n");
    printf("Ход: ");

    if (scanf("%d", &choice) != 1) {
      fprintf(stderr, "Incorrect input!\n");
      return 1;
    }

    switch (choice) {
      case 1: {
        int qty;
        int cost;
        buy_price = 10 + city * 3 + (day % 5) * city;
        printf("Сколько купить? (цена %d): ", buy_price);
        if (scanf("%d", &qty) != 1 || qty <= 0) {
          fprintf(stderr, "Incorrect input!\n");
          return 1;
        }
        cost = buy_price * qty;
        if (qty + cargo > max_cargo) {
          printf("Не хватает места в трюме (макс. %d).\n", max_cargo);
          break;
        }
        if (gold < cost) {
          printf("Не хватает золота (нужно %d).\n", cost);
          break;
        }
        gold -= cost;
        cargo += qty;
        printf("Куплено %d ед. за %d золота.\n", qty, cost);
        day++;
        break;
      }
      case 2: {
        int qty;
        int income;
        sell_price = 10 + city * 3 + (day % 5) * city - 3;
        printf("Сколько продать? (цена %d): ", sell_price);
        if (scanf("%d", &qty) != 1 || qty <= 0) {
          fprintf(stderr, "Incorrect input!\n");
          return 1;
        }
        if (qty > cargo) {
          printf("В трюме только %d ед.\n", cargo);
          break;
        }
        income = sell_price * qty;
        cargo -= qty;
        gold += income;
        printf("Продано %d ед. за %d золота.\n", qty, income);
        day++;
        break;
      }
      case 3: {
        int dest;
        int travel_cost;
        printf("В какой город (1-4)? ");
        if (scanf("%d", &dest) != 1) {
          fprintf(stderr, "Incorrect input!\n");
          return 1;
        }
        if (dest < 1 || dest > 4) {
          printf("Нет такого города.\n");
          break;
        }
        if (dest == city) {
          printf("Вы уже в этом городе.\n");
          break;
        }
        travel_cost = 2 * abs(dest - city);
        if (gold < travel_cost) {
          printf("Не хватает золота на дорогу (нужно %d).\n", travel_cost);
          break;
        }
        gold -= travel_cost;
        city = dest;
        printf("Прибыли в город %d. Дорога стоила %d золота.\n", city,
               travel_cost);
        day++;
        break;
      }
      case 4:
        if (debt > 0) {
          printf("Сначала погасите текущий долг.\n");
          break;
        }
        gold += 100;
        debt += 110;
        printf("Взят кредит: +100 золота, долг 110.\n");
        day++;
        break;
      case 0:
        printf("Досрочный выход.\n");
        running = 0;
        break;
      default:
        printf("Неизвестная команда.\n");
        break;
    }
  }

  printf("\nИтог: золото %d, долг %d, чистый капитал %d\n", gold, debt,
         gold - debt);

  return 0;
}
