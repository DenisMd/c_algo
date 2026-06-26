#include <stdio.h>
#include <stdbool.h>

int main()
{
    int user1_age = 23;
    int user2_age = 14;
    bool is_access_granted_for_user1 = user1_age >= 18; // обратите внимание что логические переменные начинаются на is_*
    bool is_access_granted_for_user2 = user2_age >= 18;
    bool constant_true = true;
    bool constant_false = false;

    printf("sizeof(bool) %ld bytes\n", sizeof(bool));

    printf("Access granted for user1: %d\n", is_access_granted_for_user1); // 1 - true
    printf("Access granted for user2: %d\n", is_access_granted_for_user2); // 0 - false

    return 0;
}