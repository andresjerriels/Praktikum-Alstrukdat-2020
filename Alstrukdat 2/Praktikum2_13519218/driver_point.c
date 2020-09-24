/*
NIM: 13519218
Nama: Andres Jerriel Sinabutar
Tanggal: 02 September 2020
Topik praktikum: ADT Sederhana
Deskripsi: Membuat driver ADT Point
*/

#include "point.h"
#include <stdio.h>

int main()
{
    POINT P;
    printf("Masukkan nilai Absis dan Ordinat titik P: ");
    BacaPOINT(&P);
    printf("\n");
    printf("Titik yang dibaca: ");
    TulisPOINT(P);
    printf("\n");

    if (IsOrigin(P)){
        printf("Titik P adalah titik origin.\n");
    }
    if (IsOnSbX(P)){
        printf("Titik P terletak pada sumbu X.\n");
    }
    if (IsOnSbY(P)){
        printf("Titik P terletak pada sumbu Y.\n");
    }
    int kuadran = Kuadran(P);
    printf("Titik P berada di kuadran %d.\n", kuadran);

    POINT nextX = NextX(P);
    printf("Titik di sebelah kanan titik P: \n");
    TulisPOINT(nextX);
    printf("\n");
    
    POINT nextY = NextY(P);
    printf("Titik di atas titik P: \n");
    TulisPOINT(nextY);
    printf("\n");

    float dx, dy;
    POINT Pnew;
    printf("Masukkan delta X: ");
    scanf("%f", &dx);
    printf("Masukkan delta Y: ");
    scanf("%f", &dy);
    Pnew = PlusDelta(P, dx, dy);
    printf("Titik P dijumlah delta X dan delta Y: \n");
    TulisPOINT(Pnew);
    printf("\n");

    POINT Px, Py;
    Px = MirrorOf(P, true);
    Py = MirrorOf(P, false);
    printf("Hasil cerminan sumbu X dari titik P:\n");
    TulisPOINT(Px);
    printf("\n");
    printf("Hasil cerminan sumbu Y dari titik P:\n");
    TulisPOINT(Py);
    printf("\n");

    printf("Jarak P ke (0,0) adalah %f", Jarak0(P));
    printf("\n");

    POINT P2;
    printf("Masukkan nilai Absis dan Ordinat titik P2: ");
    BacaPOINT(&P2);
    printf("\n");
    float panjang = Panjang(P, P2);
    printf("Panjang garis yang dibentuk P dan P2 adalah %f\n", panjang);

    float dX, dY;
    printf("Masukkan delta X: ");
    scanf("%f", &dX);
    printf("Masukkan delta Y: ");
    scanf("%f", &dY);
    Geser(&P, dX, dY);
    printf("Titik P digeser delta X dan delta Y:\n");
    TulisPOINT(P);
    printf("\n");

    GeserKeSbX(&P2);
    printf("Titik P2 digeser ke sumbu X: \n");
    TulisPOINT(P2);
    printf("\n");

    GeserKeSbY(&P);
    printf("Titik P2 digeser ke sumbu Y: \n");
    TulisPOINT(P2);
    printf("\n");

    Mirror(&P, true);
    printf("Hasil cerminan sumbu X dari titik P:\n");
    TulisPOINT(P);
    printf("\n");
    Mirror(&P, false);
    printf("Hasil cerminan sumbu Y dari titik P:\n");
    TulisPOINT(P);
    printf("\n");

    float sudut;
    scanf("Masukkan sudut putar: %f", &sudut);
    Putar(&P, sudut);
    printf("Hasil sudut P setelah diputar:\n");
    TulisPOINT(P);
    printf("\n");

    return 0;
}