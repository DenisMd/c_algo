#include <stdio.h>

// gcc -g app.c
// macos - lldb
//     * brew install llvm
//     * xcode-select --install
int main()
{
    int a = 5;
    int b = 13;
    int c = a * b + 7;
    a = c - b * 2;
    int d = a + b * c;
    b = d / (a + 1);
    int e = b + c - a * 3;
    c = e % (b + 4);
    int f = a * b - c + d / 2;
    d = f + e - a * c;
    int result = a + b + c + d + e + f;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    printf("d = %d\n", d);
    printf("e = %d\n", e);
    printf("f = %d\n", f);
    printf("result = %d\n", result);

    return 0;
}