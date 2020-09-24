/* program yang membaca 3 buah integer berturut-berturut, 
misalnya A, B, C, dan menghasilkan bilangan yang terbesar di antara ketiganya.
by Andres
Aug 27, 2020 */

#include <stdio.h>

int max(int a, int b, int c)
{
    if ((a >= b) && (a >= c)){
        return a;
    } else if ((b >= a) && (b >= c)){
        return b;
    } else {
        return c;
    }
}

int main()
{
    int a, b, c, maksimum;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    maksimum = max(a,b,c);
    printf("%d\n", maksimum);
    return 0;
}
