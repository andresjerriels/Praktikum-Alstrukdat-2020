/*
NIM: 13519218
Nama: Andres Jerriel Sinabutar
Tanggal: 10 September 2020
Topik praktikum: ADT List (Implementasi Array)
Deskripsi: Program yang memeriksa apakah array tersebut merupakan Array Monotonik atau bukan. Array monotonik sendiri memiliki tiga jenis, yaitu Array Monotonik Tidak Membesar, Array Monotonik Tidak Mengecil, dan Array Monotonik Statik.
*/

#include "arraypos.h"
#include <stdio.h>

int main() {
    TabInt T, Tnotbesar, Tnotkecil;

    BacaIsi(&T);

    Tnotbesar = T;
    Tnotkecil = T;
    Sort(&Tnotkecil, true);
    Sort(&Tnotbesar, false);

    if (IsEQ(T, Tnotbesar) && !IsEQ(T, Tnotkecil)) {
        printf("Array monotonik tidak membesar\n");
    } else if (!IsEQ(T, Tnotbesar) && IsEQ(T, Tnotkecil)) {
        printf("Array monotonik tidak mengecil\n");
    } else if (IsEQ(T, Tnotbesar) && IsEQ(T, Tnotkecil)) {
        printf("Array monotonik statik\n");
    } else {
        printf("Array tidak monotonik\n");
    }

    return 0;
}