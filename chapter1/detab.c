#include <stdio.h>

#define CURSOR 5

int detabRow(void);

//detab 输入一个tab会到达下一个tab终止位
main()
{
    while (detabRow() >= 1)
        ;

    return 0;
}

int detabRow(void)
{
    int c, pos, nb;

    pos = 1;
    nb = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            nb = CURSOR - ((pos - 1) % CURSOR);
            while (nb > 0) {
                putchar(' ');
                --nb;
                ++pos;
            }
        } else {
            if (c == '\n') {
                putchar('\n');
                return pos;
            }
            putchar(c);
            ++pos;
        }
    }

    return 0;
}