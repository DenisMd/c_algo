#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ПРОГРАММА ЕСТ ПАМЯТЬ, ПОКА ЕЁ НЕ УБЬЮТ
//
// лучше запускать в cgroup с лимитом, иначе oom-killer выберет жертву сам
// и прилететь может не этому процессу:
//   gcc -Wall -Wextra -std=c17 -o oom oom.c
//   systemd-run --user --scope -p MemoryMax=512M -p MemorySwapMax=0 ./oom
//   dmesg | tail   # тут будет запись об убийстве

#define CHUNK (16 * 1024 * 1024) // 16 MB за раз

int main()
{
  size_t total = 0;

  printf("feeding the oom-killer, Ctrl+C to stop\n\n");

  for(;;) {
    char *p = malloc(CHUNK);

    if(p == NULL) { // сюда попадём при ulimit -v, а без лимита процесс просто убьют
      fprintf(stderr, "malloc returned NULL after %zu MB\n", total / (1024*1024));
      return 1;
    }

    memset(p, 1, CHUNK); // без записи страницы физически не выдаются: ядро обещает память, но не даёт

    total += CHUNK;
    printf("leaked %zu MB\n", total / (1024*1024));
    fflush(stdout);

    // free(p) здесь нет - в этом вся суть
  }
}
