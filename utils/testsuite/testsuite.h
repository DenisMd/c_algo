#ifndef TESTSUITE_H
#define TESTSUITE_H

// ---- Мини-библиотека для тестов ----
// Интерфейс: что умеет модуль. Реализация — в testsuite.c.
//
// Как пользоваться:
//   ts_begin("gcd");                     // заголовок набора тестов
//   TS_ASSERT_INT(gcd(12, 8), 4);        // проверка: ожидаем 4
//   return ts_summary();                 // итог + код возврата для make/CI

#include <stdbool.h>

// Режим работы при провале теста.
typedef enum {
  TS_CONTINUE = 0,  // напечатать ошибку и идти дальше (по умолчанию)
  TS_FAIL_FAST = 1  // сразу завершить программу на первом провале
} ts_mode;

void ts_set_mode(ts_mode mode);  // переключить поведение при провале
void ts_begin(const char *suite_name);

// Не вызывайте напрямую — для этого есть макросы ниже.
// file/line нужны, чтобы в сообщении была видна строка с провалившимся тестом.
void ts_check(bool ok, const char *expr, const char *file, int line);
void ts_check_int(long long actual, long long expected, const char *expr,
                  const char *file, int line);

// Итог: сколько прошло/упало. Возвращает 0 если всё зелёное, иначе 1.
int ts_summary(void);

// __FILE__ и __LINE__ подставляет препроцессор в месте вызова макроса,
// #expr превращает само выражение в строку — так в отчёте видно, что проверяли.
#define TS_ASSERT(expr) ts_check((expr), #expr, __FILE__, __LINE__)
#define TS_ASSERT_INT(actual, expected) \
  ts_check_int((actual), (expected), #actual, __FILE__, __LINE__)

#endif
