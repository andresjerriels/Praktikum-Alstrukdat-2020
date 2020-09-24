/*
NIM: 13519218
Nama: Andres Jerriel Sinabutar
Tanggal: 17 September 2020
Topik praktikum: ADT List (Implementasi Array)
Deskripsi: Membuat driver ADT array dengan representasi eksplisit dan alokasi dinamik.
*/

#include "arraydin.h"
#include <stdio.h>

int main()
{
    TabInt T;
    int maxel, Q, i;

    scanf("%d", &maxel);
    MakeEmpty(&T, maxel);

    BacaIsi(&T);

    scanf("%d", &Q);

    for (i=0;i<Q;i++){
        int op;
        scanf("%d", &op);
        if (op == 1){
            int num;
            scanf("%d", &num);
            if (!IsFull(T)){
                AddAsLastEl(&T, num);

                printf("%d ", MaxEl(T));
                TulisIsiTab(T);
                printf("\n");
            } else {
                printf("array sudah penuh\n");
            }
        } else if (op == 2) {
            int num;
            scanf("%d", &num);
            GrowTab(&T, num);

            printf("%d ", MaxEl(T));
            TulisIsiTab(T);
            printf("\n");
        } else if (op == 3) {
            int num;
            scanf("%d", &num);
            if (MaxEl(T) >= num){
                ShrinkTab(&T, num);
                printf("%d ", MaxEl(T));
                TulisIsiTab(T);
                printf("\n");
            } else {
                printf("array terlalu kecil\n");
            }
        } else {
            CompactTab(&T);

            printf("%d ", MaxEl(T));
            TulisIsiTab(T);
            printf("\n");
        }
    }

    Dealokasi(&T);

    return 0;
}