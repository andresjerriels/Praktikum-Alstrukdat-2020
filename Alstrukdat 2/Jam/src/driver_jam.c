/*
NIM: 13519218
Nama: Andres Jerriel Sinabutar
Tanggal: 02 September 2020
Topik praktikum: ADT Sederhana
Deskripsi: Membuat driver ADT Jam
*/
#include <stdio.h>
#include "jam.h"

int main(){
    JAM J;
    printf("Masukkan Jam J:\n");
    BacaJAM(&J);

    printf("Jam yang dibaca:\n");
    TulisJAM(J);
    printf("\n");

    JAM J2;
    printf("Masukkan Jam J2:\n");
    BacaJAM(&J2);

    printf("Jam yang dibaca:\n");
    TulisJAM(J2);
    printf("\n");

    long detik;
    detik = JAMToDetik(J);
    printf("Jumlah detik J dari pukul 0:0:0 adalah %ld\n", detik);

    long detik1;
    printf("Masukkan nilai detik yang ingin dikonversi: ");
    scanf("%ld", &detik1);
    printf("Hasil konversi: ");
    TulisJAM(DetikToJAM(detik1));
    printf("\n");

    if (JEQ(J, J2)){
        printf("J sama dengan J2\n");
    }

    if (JNEQ(J, J2)){
        printf("J tidak sama dengan J2\n");
    }

    if (JLT(J, J2)){
        printf("J < J2\n");
    }

    if (JGT(J, J2)){
        printf("J > J2\n");
    }

    JAM Jnew;
    Jnew = NextDetik(J);
    printf("1 detik setelah J adalah ");
    TulisJAM(Jnew);
    printf("\n");

    int N;
    printf("Masukkan N: ");
    scanf("%d", &N);
    Jnew = NextNDetik(J, N);
    printf("N detik setelah J adalah ");
    TulisJAM(Jnew);
    printf("\n");

    Jnew = PrevDetik(J);
    printf("1 detik sebelum J adalah ");
    TulisJAM(Jnew);
    printf("\n");

    printf("Masukkan N: ");
    scanf("%d", &N);
    Jnew = PrevNDetik(J, N);
    printf("N detik sebelum J adalah ");
    TulisJAM(Jnew);
    printf("\n");

    long durasi;
    durasi = Durasi(J2, J);
    printf("Selisih antara J2 dan J adalah %ld\n", durasi);

    return 0;

}