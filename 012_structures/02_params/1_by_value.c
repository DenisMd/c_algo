#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct account {
  int id;
  int balance;
};

typedef struct {
  int MAX_ALLOWABLE_BALANCE;
  int MAX_TRANSACTION_AMOUNT;
} limits;

const limits GLOBAL_LIMITS = {INT_MAX, 5000};


bool deposit(struct account acc, int amount)
{
  if (amount > GLOBAL_LIMITS.MAX_TRANSACTION_AMOUNT) {
    return false;
  }
  if (GLOBAL_LIMITS.MAX_ALLOWABLE_BALANCE - acc.balance < amount) {
    return false;
  }
  acc.balance += amount;
  printf("deposit: &acc = %p, balance = %d\n", (void*)&acc, acc.balance);
  return true;
}

int main()
{
  struct account acc = {1001, 500};

  printf("main:    &acc = %p, balance = %d\n", (void*)&acc, acc.balance);
  if (deposit(acc, 300)) {  // в функцию уходит копия всех полей
    printf("main:    &acc = %p, balance = %d\n\n", (void*)&acc, acc.balance);
  } else {
    fprintf(stderr, "deposit unsuccess\n");
    return -1;
  }
  struct account backup = acc;  // присваивание тоже копирует
  acc.balance = 0;

  printf("acc    #%d: balance = %d\n", acc.id, acc.balance);
  printf("backup #%d: balance = %d\n", backup.id, backup.balance);

  return 0;
}
