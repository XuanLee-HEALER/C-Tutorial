#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    // signed(min-max) char short int long
    printf("the max value of char: %d, min value: %d\n", SCHAR_MAX, SCHAR_MIN);
    printf("the max value of short: %d, min value: %d\n", SHRT_MAX, SHRT_MIN);
    printf("the max value of int: %d, min value: %d\n", INT_MAX, INT_MIN);
    printf("the max value of long: %ld, min value: %ld\n", LONG_MAX, LONG_MIN);

    // unsigned(max) char short int long | min = 0
    printf("the min value of char: %d\n", UCHAR_MAX);
    printf("the min value of short: %d\n", USHRT_MAX);
    printf("the min value of int: %u\n", UINT_MAX);
    printf("the min value of long: %lu\n", ULONG_MAX);

    char s_char_max = (char) ((unsigned char) ~0 >> 1);
    short s_short_max = (short) ((unsigned short) ~0 >> 1);
    int s_int_max = (int) ((unsigned int) ~0 >> 1);
    long s_long_max = (long) ((unsigned long) ~0 >> 1);

    char s_char_min = - (char) ((unsigned char) ~0 >> 1);
    short s_short_min = - (short) ((unsigned short) ~0 >> 1);
    int s_int_min = - (int) ((unsigned int) ~0 >> 1);
    long s_long_min = - (long) ((unsigned long) ~0 >> 1);

    printf("the max value of char: %d, min value: %d\n", s_char_max, s_char_min);
    printf("the max value of short: %d, min value: %d\n", s_short_max, s_short_min);
    printf("the max value of int: %d, min value: %d\n", s_int_max, s_int_min);
    printf("the max value of long: %ld, min value: %ld\n", s_long_max, s_long_min);

    unsigned char us_char_max = (unsigned char) ~0;
    unsigned short us_short_max = (unsigned short) ~0 ;
    unsigned int us_int_max = (unsigned int) ~0;
    unsigned long us_long_max = (unsigned long) ~0;

    printf("the min value of char: %d\n", us_char_max);
    printf("the min value of short: %d\n", us_short_max);
    printf("the min value of int: %u\n", us_int_max);
    printf("the min value of long: %lu\n", us_long_max);

    return 0;
}