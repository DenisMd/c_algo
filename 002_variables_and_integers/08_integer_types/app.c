#include <stdio.h>
#include <limits.h>

int main()
{
    char char_max = CHAR_MAX;
    signed char signed_char_max = SCHAR_MAX;
    signed char signed_char_min = SCHAR_MIN;    
    unsigned char unsigned_char_max = UCHAR_MAX;
    short short_max = SHRT_MAX;
    short short_min = SHRT_MIN;
    unsigned short unsigned_short_max = USHRT_MAX;
    int int_max = INT_MAX;
    int int_min = INT_MIN;
    unsigned int unsigned_int_max = UINT_MAX;
    long long_max = LONG_MAX;
    long long_min = LONG_MIN;
    unsigned long unsigned_long_max = ULLONG_MAX;
    long long long_long_max = LLONG_MAX;
    long long long_long_min = LLONG_MIN;
    unsigned long long unsigned_long_long_max = ULLONG_MAX;

    printf("char: min = %d, max = %d\n", SCHAR_MIN, char_max);
    printf("signed char: min = %d, max = %d\n", signed_char_min, signed_char_max);
    printf("unsigned char: min = 0, max = %d\n", unsigned_char_max);
    printf("short: min = %d, max = %d\n", short_min, short_max);
    printf("unsigned short: min = 0, max = %d\n", unsigned_short_max);
    printf("int: min = %d, max = %d\n", int_min, int_max);
    printf("unsigned int: min = 0, max = %u\n", unsigned_int_max);
    printf("long: min = %ld, max = %ld\n", long_min, long_max);
    printf("unsigned long: min = 0, max = %lu\n", unsigned_long_max);
    printf("long long: min = %lld, max = %lld\n", long_long_min, long_long_max);
    printf("unsigned long long: min = 0, max = %llu\n", unsigned_long_long_max);


    printf("\n\n--------------------------------\n\n");

    printf("size of char - %ld bytes\n", sizeof(char));
    printf("size of signed char - %ld bytes\n", sizeof(signed char));
    printf("size of unsigned char - %ld bytes\n", sizeof(unsigned char));
    printf("size of short - %ld bytes\n", sizeof(short));
    printf("size of unsigned short - %ld bytes\n", sizeof(unsigned short));
    printf("size of int - %ld bytes\n", sizeof(int));
    printf("size of unsigned int - %ld bytes\n", sizeof(unsigned int));
    printf("size of long - %ld bytes\n", sizeof(long));
    printf("size of unsigned long - %ld bytes\n", sizeof(unsigned long));
    printf("size of long long - %ld bytes\n", sizeof(long long));
    printf("size of unsigned long long - %ld bytes\n", sizeof(unsigned long long));


    return 0;
}