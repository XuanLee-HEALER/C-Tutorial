#include <stdio.h>

#define MAXLINE 50

int getLine(char line[], int lim);
void copy(char to[], char from[]);

// 打印任意长度的输入行，尽可能多打印文本
main()
{
    int len;
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0)
        printf("%d\t%s", len, line);

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

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}