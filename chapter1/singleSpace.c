#include <stdio.h>

#define NONSPACE 'a'

// 输入复制到输出，将其中连续的多个空格用一个空格代替
main()
{
    int c, prev;

    prev = NONSPACE;

    for (; (c = getchar()) != EOF;) {
        if (c != ' ') {
            if (prev == ' ') {
                putchar(' ');
                prev = c;
            }
            putchar(c);
        } else {
            prev = c;
        }  
    }
}