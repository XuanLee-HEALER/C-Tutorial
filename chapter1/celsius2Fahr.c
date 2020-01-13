#include <stdio.h>

main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0.0;
    upper = 300.0;
    step = 20.0;

    celsius = lower;
    printf("Celsius to Fahrenheit\n\n");
    while (celsius <= upper) {
        // fahr = celsius / (5.0 / 9.0) + 32.0;
        fahr = (9.0 * celsius) / 5.0 + 32.0;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius += step;
    }
}