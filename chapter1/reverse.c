#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int lim);
void reverse(char line[], int len);

// 编写函数reverse(s)，将s中字符顺序反转过来，每次颠倒一个输入行中的字符顺序
main()
{
    int l;
    char line[MAXLINE];

    while ((l = getLine(line, MAXLINE)) > 0) {
        reverse(line, l);
        printf("%s", line);
    }
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

void reverse(char line[], int len)
{
    int prev, last, tmp;

    for (prev = 0, last = len - 2; prev < last; ++prev, --last) {
        tmp = line[prev];
        line[prev] = line[last];
        line[last] = tmp;
    }
}