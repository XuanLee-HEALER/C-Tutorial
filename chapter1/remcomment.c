#include <stdio.h>

void rcomment(int p);
void in_comment(void);
void echo_quote(int q);

main()
{
    int c;

    while ((c = getchar()) != EOF) {
        rcomment(c);
    }

    return 0;
}

void rcomment(int p)
{
    int np;

    if (p == '/') {
        if ((np = getchar()) == '*') {
            in_comment();
        } else if (np == '/') {
            putchar(p);
            rcomment(np);
        } else {
            putchar(p);
            putchar(np);
        }
    } else if (p == '\'' || p == '"') {
        echo_quote(p);
    } else {
        putchar(p);
    }
}

void in_comment(void)
{
    int c, d;

    c = getchar();
    d = getchar();
    while (c != '*' && d != '/') {
        c = d;
        d = getchar();
    }
}

void echo_quote(int q)
{
    int c;

    putchar(q);

    while ((c = getchar()) != q) {
        putchar(c);

        if (c == '\\')
            putchar(getchar());
    }

    putchar(c);
}