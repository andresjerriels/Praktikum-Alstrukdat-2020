
/* Converting temperature
by Andres
Aug 26, 2020 
Asumsi input user benar.
*/


#include <stdio.h>

float ctor(float x)
{
    return (x * 4 / 5);
}

float ctof(float x)
{
    return (x * 9 / 5) + 32;
}

float ctok(float x)
{
    return x + 273.15;
}

int main()
{
    float inpt, result; 
    char jenis;

    /* Input temperature in celsius */
    scanf("%f", &inpt);
    scanf(" %c", &jenis);
    /* celsius to fahrenheit conversion formula */
    if (jenis == 'R'){
        result = ctor(inpt);
    } else if (jenis == 'K') {
        result = ctok(inpt);
    } else {
        result = ctof(inpt);
    }

    printf("%.2f\n", result);
    return 0;
}