#include <stdio.h>

#define MAXCOL 10
#define TABSIZE 4

char line[MAXCOL];

int exptab(int pos);
int findblk(int pos);
int newpos(int pos);
void printl(int pos);

main()
{
    int c, pos;

    pos = 0;
    while ((c = getchar()) != EOF) {
        line[pos] = c;
        if (c == '\t') {
            pos = exptab(pos);
        } else if (c == '\n') {
            printl(pos);
            pos = 0;
        } else if (++pos >= MAXCOL) {
            pos = findblk(pos);
            printl(pos);
            pos = newpos(pos);
        }
    }

    return 0;
}

int exptab(int pos)
{
    line[pos] = ' ';

    for (++pos; pos < MAXCOL && pos % TABSIZE != 0; ++pos) {
        line[pos] = ' ';
    }

    if (pos >= MAXCOL) {
        printl(pos);
        return 0;
    } else {
        return pos;
    }
}

int findblk(int pos)
{
    int i;

    for (i = pos; i > 0; --i) {
        if (line[i] == ' ') {
            break;
        }
    }

    if (i == 0) {
        return pos;
    } else {
        return i + 1;
    }
}

int newpos(int pos)
{
    if (pos <= 0 || pos >= MAXCOL) {
        return 0;
    }

    int i, j;

    i = 0;
    for (j = pos; j < MAXCOL; ++j, ++i) {
        line[i] = line[j];
    }
    return i;
}

void printl(int pos)
{
    for (int i = 0; i < pos; ++i) {
        putchar(line[i]);
    }

    if (pos > 0) {
        putchar('\n');
    }
}