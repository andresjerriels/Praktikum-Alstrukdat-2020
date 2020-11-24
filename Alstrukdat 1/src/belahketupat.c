#include <stdio.h>

void GambarBelahKetupat(int number)
{
    int i, k, count = 1;

    count = (number - 1) / 2;
    for (k = 1; k <= (number + 1) / 2; k++)
    {
        for (i = 1; i <= count; i++)
            printf(" ");
        count --;
        for (i = 1; i <= 2 * k - 1; i++)
            printf("*");
        printf("\n");
    }
    count = 1;
    for (k = ((number - 1) / 2); k >= 1 ; k--)
    {
        for (i = count; i >= 1; i--)
             printf(" ");
        count++;
        for (i = 2 * k - 1; i >= 1 ; i--)
            printf("*");
        printf("\n");
    }
    
}
int IsValid(int n)
{
    if ((n > 0) && (n % 2 == 1)){
        return 0;
    } else {
        return 1;
    }
}
int main()
{
    int n;
    scanf("%d", &n);

    if (IsValid(n) == 0){
        GambarBelahKetupat(n);
    } else{
        printf("Masukan tidak valid\n");
    }

return 0; 
}