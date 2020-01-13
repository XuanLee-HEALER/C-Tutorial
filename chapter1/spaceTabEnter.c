#include <stdio.h>

main()
{
    int c;
    long spaceQty, tabQty, enterQty;

    spaceQty = tabQty = enterQty = 0;
    for(; (c = getchar()) != EOF;) {
        switch (c) {
            case ' ':
                ++spaceQty;
                break;
            case '\t':
                ++tabQty;
                break;
            case '\n':
                ++enterQty;
                break;
            default:
                break;
        };
    }

    printf("Space: %ld\n", spaceQty);
    printf("Tab: %ld\n", tabQty);
    printf("Enter: %ld\n", enterQty);
}