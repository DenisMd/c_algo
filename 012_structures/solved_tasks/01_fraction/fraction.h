#ifndef FRACTION_H
#define FRACTION_H

struct fraction {
  int num;
  int den;
};

struct fraction fraction_reduce(struct fraction f);
struct fraction fraction_add(struct fraction a, struct fraction b);
struct fraction fraction_mul(struct fraction a, struct fraction b);
void fraction_print(struct fraction f);  // без перевода строки

#endif
