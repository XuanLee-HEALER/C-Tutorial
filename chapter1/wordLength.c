#include <stdio.h>

#define UPPER_LENGTH 10
#define IN 0
#define OUT 1

// 统计单词长度，绘制直方图
main()
{
    int c, state;
    int nDigit[UPPER_LENGTH];
    long cLen;

    for (int i = 0; i < UPPER_LENGTH; ++i)
        nDigit[i] = 0;

    state = OUT;
    cLen = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;

            if (cLen > 0) {
                if ((10 - cLen) < 0)
                    ++nDigit[UPPER_LENGTH - 1];
                else
                    ++nDigit[cLen - 1];
            }

            cLen = 0;
        } else if (state == IN)
            ++cLen;
        else {
            state = IN;
            ++cLen;
        }
    }

    for (int i = 0; i < UPPER_LENGTH; ++i) {
        if (i == UPPER_LENGTH - 1)
            printf("%d+|", UPPER_LENGTH);
        else
            printf("%3d|", i + 1);
        
        for (int j = 0; j < nDigit[i]; ++j)
            putchar('*');

        putchar('\n');
    }

    printf("=========================================\n");

    int max;

    max = -1;
    for (int i = 0; i < UPPER_LENGTH; ++i) {
        if (nDigit[i] > max)
            max = nDigit[i];
    }

    for (int i = 0; i < max; ++i) {
        for (int j = 0; j < UPPER_LENGTH; ++j) {
            if (nDigit[j] >= max - i)
                printf("%4c", '*');
            else
                printf("    ");
        }
        putchar('\n');
    }

    for (int i = 0; i < UPPER_LENGTH * 4; ++i) {
        putchar('-');
    }
    putchar('\n');

    for (int i = 0; i < UPPER_LENGTH; ++i) {
        if (i == UPPER_LENGTH - 1)
            printf(" %d+", UPPER_LENGTH);
        else
            printf("%4d", i + 1);
    }
    putchar('\n');
}