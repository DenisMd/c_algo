#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

struct account {
  int id;
  int balance;
};

typedef struct {
  int MAX_ALLOWABLE_BALANCE;
  int MAX_TRANSACTION_AMOUNT;
} limits;

const limits GLOBAL_LIMITS = {INT_MAX, 5000};

bool deposit(struct account* acc, int amount)
{
  if (acc == NULL) {  // по значению NULL прийти не может, по указателю - может
    return false;
  }
  if (amount > GLOBAL_LIMITS.MAX_TRANSACTION_AMOUNT) {
    return false;
  }
  if (GLOBAL_LIMITS.MAX_ALLOWABLE_BALANCE - acc->balance < amount) {
    return false;
  }
  acc->balance += amount;  // то же, что (*acc).balance += amount
  // *acc.balance += amount;  // ошибка: . сильнее *, это *(acc.balance)

  printf("deposit: acc   = %p, balance = %d\n", (void*)acc, acc->balance);
  return true;
}

bool transfer(struct account* from, struct account* to, int amount)
{
  if (from == NULL || to == NULL) {
    return false;
  }
  if (amount > GLOBAL_LIMITS.MAX_TRANSACTION_AMOUNT) {
    return false;
  }
  if (from->balance < amount) {
    return false;
  }
  if (GLOBAL_LIMITS.MAX_ALLOWABLE_BALANCE - to->balance < amount) {
    return false;
  }

  from->balance -= amount;
  to->balance += amount;

  return true;
}

int main()
{
  struct account card = {1001, 500};
  struct account savings = {1002, 0};

  printf("main:    &card = %p, balance = %d\n", (void*)&card, card.balance);
  if (deposit(&card, 300)) {
    printf("main:    &card = %p, balance = %d\n\n", (void*)&card, card.balance);
  } else {
    fprintf(stderr, "deposit unsuccess\n");
    return -1;
  }

  if (!deposit(NULL, 300)) {
    printf("deposit(NULL): false\n\n");
  }

  for (int i = 0; i < 2; i++) {
    if (transfer(&card, &savings, 600)) {
      printf("transfer 600: ok\n");
    } else {
      printf("transfer 600: rejected\n");
    }
  }

  printf("\naccount #%d: balance = %d\n", card.id, card.balance);
  printf("account #%d: balance = %d\n", savings.id, savings.balance);

  return 0;
}
