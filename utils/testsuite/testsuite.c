#include "testsuite.h"

#include <stdio.h>
#include <stdlib.h>

// ---- Реализация мини-библиотеки тестов ----

// ANSI escape-последовательности: терминал понимает их как "смени цвет".
// \033 (он же \x1B) — символ ESC, [32m — зелёный, [31m — красный, [0m — сброс.
#define GREEN "\033[32m"
#define RED   "\033[31m"
#define DIM   "\033[2m"
#define RESET "\033[0m"

#define MARK_PASS GREEN "✔" RESET  // ✔ зелёная галочка
#define MARK_FAIL RED   "✘" RESET  // ✘ красный крест

// static = видно только внутри этого файла. Общее состояние прогона.
static int passed = 0;
static int failed = 0;
static ts_mode mode = TS_CONTINUE;

void ts_set_mode(ts_mode m)
{
  mode = m;
}

void ts_begin(const char *suite_name)
{
  // Счётчики НЕ сбрасываем: ts_summary() подводит итог по всему прогону.
  printf("\n== %s ==\n", suite_name);
}

// Общий "хвост" для всех проверок: посчитать, напечатать, может быть — упасть.
static void report(bool ok, const char *expr, const char *file, int line,
                   const char *detail)
{
  if (ok) {
    passed++;
    printf("  %s %s\n", MARK_PASS, expr);
    return;
  }

  failed++;
  printf("  %s %s\n", MARK_FAIL, expr);
  if (detail != NULL) {
    printf("      %s\n", detail);
  }
  printf("      " DIM "%s:%d" RESET "\n", file, line);

  if (mode == TS_FAIL_FAST) {
    printf("\n" RED "остановка: режим TS_FAIL_FAST" RESET "\n");
    exit(1);
  }
}

void ts_check(bool ok, const char *expr, const char *file, int line)
{
  report(ok, expr, file, line, ok ? NULL : "ожидалось: истина, получили: ложь");
}

void ts_check_int(long long actual, long long expected, const char *expr,
                  const char *file, int line)
{
  bool ok = (actual == expected);

  // Буфер под текст вида "ожидалось: 4, получили: 3".
  // snprintf не даст выйти за границы буфера, в отличие от sprintf.
  char detail[128];
  if (!ok) {
    snprintf(detail, sizeof(detail), "ожидалось: %lld, получили: %lld",
             expected, actual);
  }

  report(ok, expr, file, line, ok ? NULL : detail);
}

int ts_summary(void)
{
  int total = passed + failed;
  printf("\n  итого: %d из %d\n", passed, total);

  if (failed == 0) {
    printf("  %s все тесты прошли\n\n", MARK_PASS);
    return 0;
  }

  printf("  %s провалено: %d\n\n", MARK_FAIL, failed);
  return 1;
}
