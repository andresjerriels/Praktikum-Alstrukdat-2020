/*
NIM: 13519218
Nama: Andres Jerriel Sinabutar
Tanggal: 03 September 2020
Topik praktikum: ADT Sederhana
Deskripsi: Menuliskan jam mulai pembicaraan yang paling awal yang ada dalam record dan jam selesai paling akhir yang ada dalam record. Pembacaan data dimulai dengan banyaknya pasangan data yang akan dibaca yaitu N.
*/

#include <stdio.h>
#include "jam.h"

int main()
{
    int i, n;
    JAM J1, J2, min, max;
    long durasi;

    i = 1;
    min = MakeJAM(23, 59, 59);
    max = MakeJAM(0, 0, 0);
    scanf("%d", &n);
    do {
        printf("[%d]\n", i);
        BacaJAM(&J1);
        BacaJAM(&J2);
        if (JGT(J1, J2)){
            if (JLT(J2, min)){
                min = J2;
            }
            if (JGT(J1, max))
            {
                max = J1;
            }
            durasi = Durasi(J2, J1);
        } else {
            if (JLT(J1, min)){
                min = J1;
            }
            if (JGT(J2, max))
            {
                max = J2;
            }
            durasi = Durasi(J1, J2);
        }
        printf("%ld\n", durasi);
        i++;
    } while (i <= n);

    TulisJAM(min);
    printf("\n");
    TulisJAM(max);
    printf("\n");

    return 0;
    
}