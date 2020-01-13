#include <stdio.h>

#define NON ' '

main()
{
    int c, lastC;

    lastC = NON;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t' && c != '\n') {
            lastC = c;        
            putchar(c);
        } else {
            if (lastC != NON) {
                putchar('\n');
                lastC = NON;
            }
        }
    }
}