/*
NIM: 13519218
Nama: Andres Jerriel Sinabutar
Tanggal: 24 September 2020
Topik praktikum: ADT Matriks
Deskripsi: Sebuah program yang digunakan untuk mengelola data nilai mahasiswa pada beberapa mata kuliah 
di suatu kelas dengan memanfaatkan ADT Matriks yang sudah dimodifikasi sesuai soal no. 1. 
Program menerima banyaknya mahasiswa dalam kelas, misalnya n; diikuti banyaknya mata kuliah yang diambil, 
misalnya m. Diasumsikan n > 0 dan m > 0. Selanjutnya dilakukan pengisian nilai mata kuliah per mahasiswa. 
Diasumsikan masukan nilai benar yaitu berada dalam rentang 0..100.
*/

#include "matriks.h"
#include <stdio.h>

void TulisNilaiX (MATRIKS M, indeks j, ElType X){
    int jml = CountXKol(M, j, X);
    indeks i;
    printf("[");
    if (jml != 0){
        for (i=0;i<=GetLastIdxBrs(M);i++){
            if ((jml != 1) && Elmt(M, i, j) == X){
                printf("%d,", i);
                jml -= 1;
            } else if ((jml == 1) && (Elmt(M, i, j) == X)){
                printf("%d", i);
                jml -= 1;
            }
        }
    }
    printf("]");
}

void TulisStatistikMhs(MATRIKS M, indeks i){
    ElType max, min;
    MaxMinBrs(M, i, &max, &min);
    float avg = RataBrs(M, i);
    printf("[%d] %.2f %d %d", i, avg, max, min);
    printf("\n");
}

void TulisStatistikMK(MATRIKS M, indeks j){
    ElType max, min;
    MaxMinKol(M, j, &max, &min);
    float avg = RataKol(M, j);
    int nmax = CountXKol(M, j, max);
    int nmin = CountXKol(M, j, min);
    printf("[%d] %.2f ", j, avg);
    printf("[%d %d ", max, nmax);
    TulisNilaiX(M, j, max);
    printf("] ");
    printf("[%d %d ", min, nmin);
    TulisNilaiX(M, j, min);
    printf("]");
    printf("\n");
}

int main(){
    MATRIKS M;
    indeks mhs, mk;

    scanf("%d", &mhs);
    scanf("%d", &mk);

    BacaMATRIKS(&M, mhs, mk);

    printf("STATISTIK PER MAHASISWA\n");
    indeks i;
    for (i=0;i<mhs;i++){
        TulisStatistikMhs(M, i);
    }

    printf("STATISTIK PER MATA KULIAH\n");
    indeks j;
    for (j=0;j<mk;j++){
        TulisStatistikMK(M, j);
    }
}
