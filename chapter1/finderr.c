#include <stdio.h>

#define MAX_ERR 50

int brace, brack, paren;

int find_err(int c); 
void in_comment(void);
void in_quote(int c);

int main()
{
    int c;
    extern int brace, brack, paren;

    brace = brack = paren = 0;
    c = getchar();
    while(c != EOF) {
        if (c == '/') {
            if (getchar() == '*') {
                in_comment();
            } else {
                c = find_err(getchar());
            }
        } else if (c == '\'' || c == '"') {
            in_quote(c);
        } else {
            c = find_err(c);
        }
    }

    printf("brace: %d brack: %d paren: %d\n", brace, brack, paren);

    return 0;
}


int find_err(int c)
{
    extern int brace, brack, paren;

    do {
        switch (c) {
            case '(': {
                ++paren;
                break;
            }
            case ')': {
                --paren;
                break;
            }
            case '[': {
                ++brack;
                break;
            }
            case ']': {
                --brack;
                break;
            }
            case '{': {
                ++brace;
                break;
            }
            case '}': {
                --brace;
                break;
            }
            default: 
                break;
        }
    } while ((c = getchar()) != '/' && c != EOF);

    return c;
}

void in_comment(void)
{
    int c, d;

    c = getchar();
    d = getchar();
    while (c != '*' || d != '/') {
        c = d;
        d = getchar();
    }
}

void in_quote(int c)
{
    int d;

    while ((d = getchar()) != c) {
        if (d == '\\' && getchar() == c)
            ;
    }
}