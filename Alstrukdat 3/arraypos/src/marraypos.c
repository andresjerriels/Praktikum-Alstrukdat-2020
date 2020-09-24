/*
NIM: 13519218
Nama: Andres Jerriel Sinabutar
Tanggal: 10 September 2020
Topik praktikum: ADT List (Implementasi Array)
Deskripsi: 
Sebuah program yang digunakan untuk membaca sebuah TabInt, misalnya T, dengan ukuran efektif N (N dibaca dari keyboard), lalu membaca elemen-elemen T dari keyboard. N harus bernilai 0 <= N <= MaxNbEl(T).
Kemudian program menuliskan ulang isi T dalam format: [e1,e2,...,en].
Selanjutnya, program menerima masukan sebuah nilai integer, misalnya X dan menampilkan beberapa hal sebagai berikut secara berturut-turut:
- Jika X ada di array, tuliskan di indeks ke-berapa X muncul pertama kali. Jika X tidak ada di array, tuliskan “X tidak ada”.
- Apakah X adalah nilai maksimum, nilai minimum, atau nilai tengah (median) dari deret nilai dalam array (lihat contoh interaksi di bawah), jika X ada di array.
*/

#include "arraypos.h"
#include <stdio.h>

ElType Median(TabInt T) {
    Sort(&T, true);

    int Neff, hasil; 
    Neff = NbElmt(T);

    if ((Neff % 2) == 0){
        hasil = Neff / 2;
    } else {
        hasil = (Neff / 2) + 1;
    }

    return Elmt(T, hasil - 1);
}

int main() {
    TabInt T;

    BacaIsi(&T);

    TulisIsiTab(T);
    printf("\n");

    ElType X;
    scanf("%d", &X);

    if (SearchB(T, X)){
        printf("%d\n", Search1(T, X));

        ElType max, min, median;
        MaxMin(T, &max, &min);

        median = Median(T);

        if (X == max){
            printf("maksimum\n");
        }
        if (X == min){
            printf("minimum\n");
        }
        if (X == median){
            printf("median\n");
        }
    } else {
        printf("%d tidak ada\n", X);
    }

    return 0;
}