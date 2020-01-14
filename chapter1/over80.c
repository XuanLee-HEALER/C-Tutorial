#include <stdio.h>

#define MAXLINE 1000
#define LONGLINE 80

int getLine(char line[], int lim);

// 打印长度超过80的输入行
main()
{
    int len;
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > LONGLINE)
            printf("%d\t%s", len, line);
    }
        
    return 0;
}

int getLine(char line[], int lim)
{
    int c, i, j;

    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (j < lim - 2) {
            line[j] = c;
            ++j;
        }
    }

    if (c == '\n') {
        line[j] = c;
        ++j;
        ++i;
    }
        
    line[j] = '\0';
    return i;
}
