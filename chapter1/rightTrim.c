#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int lim);

// 删除每个输入行行尾的空格及制表符，删除完全是空格的行
main()
{
    int l;
    char line[MAXLINE];

    while ((l = getLine(line, MAXLINE)) >= 0)
        if (l != 0)
            printf("%d\t%s", l, line);

    return 0;
}

int getLine(char line[], int lim)
{
    int c, space, length;

    space = length = 0;
    for (int i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        if (c == ' ')
            ++space;
        ++length;
        line[i] = c;
    }

    if (c == '\n') {
        if (space == length)
            length = 0;
        else {
            int j;

            for (j = length - 1; j >= 0 && (line[j] == ' ' || line[j] == '\t'); --j)
                ;
            line[j + 1] = '\n';
            line[j + 2] = '\0';
            length = j + 2;
        }
    }

    return length;
}