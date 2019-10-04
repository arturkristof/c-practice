#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

/* Temperature conversion with function for conversion */

float convert_fahr_to_celsius(float fahr);

int main()
{
    float fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    {
        printf("%3.0f %6.1f\n", fahr, convert_fahr_to_celsius(fahr));
    }
}

float convert_fahr_to_celsius(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32);
}