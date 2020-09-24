#include <stdio.h>

int main()
{
    float ip, pot;
    int kategori;
    
    scanf("%f", &ip);
    scanf("%f", &pot);

    if (ip >= 3.5){
        kategori = 4;
    } else if (ip < 3.5){
        if (pot < 1.0){
            kategori = 1;
        } else if ((pot >= 1.0) && (pot < 5.0)){
            if (ip >= 2.0){
                kategori = 3;
            } else {
                kategori = 2;
            }
        } else {
            kategori = 0;
        }
    }

    printf("%d\n", kategori);

    return 0;
}