#include <stdio.h>

// 制表符用/b 反斜杠用\\ 回退符在终端无法接收，打印同其它不可见字符相同

main()
{
    int c;

    while((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        } else {
            putchar(c);
        }
    }
}