#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 20

float fahr2Celsius(float fahr);

main()
{
    printf("Fahr to Celsius\n");

    for (int i = LOWER; i <= UPPER; i += STEP)
        printf("%3d\t%6.1f\n", i, fahr2Celsius(i));

    return 0;
}

float fahr2Celsius(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32);
}