#include <stdio.h>
#include <ctype.h>

#define ALL_CHAR 128
#define MAX_STAR 20

// 打印字符出现频度的水平直方图
main()
{
    int c;
    long allChar;
    int cQty[ALL_CHAR];

    allChar = 0;
    for (int i = 0; i < ALL_CHAR; ++i)
        cQty[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c < ALL_CHAR) {
            ++allChar;
            ++cQty[c];
        }
    }

    for (int i = 0; i < ALL_CHAR; ++i) {
        if (isprint(i))
            printf("%5d - %5c - %3d |", i, i, cQty[i]);
        else
            printf("%5d -       - %3d |", i, cQty[i]);
        
        int star;

        if ((star = cQty[i] * MAX_STAR / allChar) <= 0)
            star = 1;
        
        while (star >= 0) {
            putchar('*');
            --star;
        }
            
        putchar('\n');
    }
}