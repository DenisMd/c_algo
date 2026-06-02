#include <stdio.h>


int main()
{
    // Example 1
    int item_price = 13;
    int balance = 107;
    int remainder= balance % item_price;

    // Example 2 - last digit(s)
    int some_number = 5325341;
    int last_digit = some_number % 10;
    int two_last_digits = some_number % 100;

    // Example 3 - even/odd
    int n = 42;
    int is_even = 42 % 2; // 0 - even 1 - odd

    // Example 4 - distribution
    long long user_id = 421543534523ll;
    int clusters_size = 7;
    int chosen_cluster = user_id % clusters_size;


    return 0;
}