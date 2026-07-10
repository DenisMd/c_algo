#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(5, 3);
    int result2 = add(10, 20) + 5 + add(add(1,1), 3);
    printf("The sum is: %d\n", result);
    printf("The second sum is: %d\n", result2);
    return 0;
}