#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

// malloc отдаёт адреса, а не память: физическая страница выдаётся только при
// первом обращении к ней - это и есть page fault (minor, без похода на диск)
//
//   gcc -Wall -Wextra -std=c17 -o pf page_fault.c
//   ./pf
//
// снаружи те же цифры видно так:
//   /usr/bin/time -v ./pf          # строки "Minor (reclaiming a frame) page faults"
//   ps -o min_flt,maj_flt -p $(pgrep -n pf)   # для живого процесса
//   perf stat -e page-faults ./pf  # если стоит perf
//   cat /proc/self/stat            # поля 10 (minflt) и 12 (majflt)

#define MB (1024 * 1024)
#define SIZE (256 * MB)

long minor_faults(void)
{
  struct rusage u;
  getrusage(RUSAGE_SELF, &u);
  return u.ru_minflt;
}

int main()
{
  long page = sysconf(_SC_PAGESIZE);

  printf("page size = %ld bytes\n", page);
  printf("start:            %ld minor faults\n", minor_faults());

  char *p = malloc(SIZE);

  if(p == NULL) {
    return 1;
  }

  printf("after malloc:     %ld minor faults  <- памяти ещё нет, только обещание\n", minor_faults());

  for(size_t i=0; i < SIZE; i += page) { // трогаем по байту на страницу
    p[i] = 1;
  }

  printf("after touching:   %ld minor faults  <- +%d страниц\n", minor_faults(), SIZE / 4096);

  for(size_t i=0; i < SIZE; i += page) { // второй проход - страницы уже наши
    p[i] = 2;
  }

  printf("touching again:   %ld minor faults  <- новых нет\n", minor_faults());

  free(p);

  return 0;
}
