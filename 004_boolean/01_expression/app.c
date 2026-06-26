#include <stdio.h>

int main()
{
    int user1_age = 23;
    int user2_age = 14;
    int is_access_granted_for_user1 = user1_age >= 18; // обратите внимание что логические переменные начинаются на is_*
    int is_access_granted_for_user2 = user2_age >= 18;
    int constant_true = 1;
    int constant_false = 0;

    printf("Access granted for user1: %d\n", is_access_granted_for_user1); // 1 - true
    printf("Access granted for user2: %d\n", is_access_granted_for_user2); // 0 - false

    return 0;
}