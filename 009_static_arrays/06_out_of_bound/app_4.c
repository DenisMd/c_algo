#include <stdio.h>
#include <stdlib.h>

void win(void) {
    printf(">>> Достигли win() через выход за границу массива!\n");
    exit(0);
}

void vulnerable(void) {
    long buf[2];                       // валидны только buf[0], buf[1]

    // Вычислим, какой индекс "за границей" попадает в адрес возврата
    void **ret = (void **)__builtin_frame_address(0) + 1;
    long idx = ret - (void **)buf;

    printf("Массив buf[2], а адрес возврата лежит в buf[%ld]\n", idx);
    buf[idx] = (long)win;              // out-of-bounds запись → перехват
}

int main(void) {
    vulnerable();
    printf("Обратно в main — не увидим\n");
    return 0;
}