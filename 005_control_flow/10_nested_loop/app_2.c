#include <stdio.h>

int main() {
    int num, div, is_prime;

    printf("Prime numbers from 2 to 100:\n");
    
    // Внешний цикл: перебираем кандидатов в простые
    for (num = 2; num <= 100; num++) {
        is_prime = 1;  // предполагаем, что число простое

        for (div = 2; div < num; div++) {
            if (num % div == 0) { // найден делитель
                is_prime = 0;
                break;
            }
        }

        // Если после полной проверки флаг остался истинным – число простое
        if (is_prime) {
            printf("%d ", num);
        }
    }
    printf("\n");

    return 0;
}