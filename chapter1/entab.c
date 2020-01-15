#include <stdio.h>

#define TERMINAL 5

// 将空格串替换为最少数量的制表符和空格，要保持单词之间的间隔不变
// 有制表符终止位
main()
{
    int c, pos, nb, nt;

    nb = nt = 0;
    pos = 1;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (pos % TERMINAL == 0) {
                nb = 0;
                ++nt;
            } else {
                ++nb;
            }
            ++pos;
        } else {
            for (; nt > 0; --nt)
                putchar('\t');
            if (c == '\t') {
                if (nb > 0) {
                    putchar('\t');
                    nb = 0;
                }
            } else {
                for (; nb > 0; --nb)
                    putchar(' ');
                putchar(c);
            }
            if (c == '\t')
                pos = pos + (TERMINAL - ((pos - 1) % TERMINAL));
            else if (c == '\n')
                pos = 1;
            else
                ++pos;
        }
    }

    return 0;
}