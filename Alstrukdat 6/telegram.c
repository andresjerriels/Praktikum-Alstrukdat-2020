/*
NIM: 13519218
Nama: Andres Jerriel Sinabutar
Tanggal: 1 Oktober 2020
Topik praktikum: Mesin Kata
Deskripsi: Membuat implementasi Mesin Token: Model Akuisisi Versi I
*/

#include "mesinkata.h"
#include <stdio.h>

boolean IsKataSama (Kata K1, Kata K2) {
    boolean sama = true;
    int i = 0;
    
    if (K1.Length == K2.Length){
        while ((i < K1.Length) && sama) {
            if (K1.TabKata[i] != K2.TabKata[i]) {
                sama = false;
            }
            i++;
        }
    } else {
        sama = false;
    }

    return sama;
} 

int main()
{
    int KataReg = 0, KataPanjang = 0;
    int i, idx, cntkata = 0;
    Kata CKoma, CTitik;

    CKoma.TabKata[0] = 'K';
    CKoma.TabKata[1] = 'O';
    CKoma.TabKata[2] = 'M';
    CKoma.TabKata[3] = 'A';
    CKoma.Length = 4;
    CTitik.TabKata[0] = 'T';
    CTitik.TabKata[1] = 'I';
    CTitik.TabKata[2] = 'T';
    CTitik.TabKata[3] = 'I';
    CTitik.TabKata[4] = 'K';
    CTitik.Length = 5;

    STARTKATA();

    while (!EndKata) {
        if (!IsKataSama(CKata, CKoma) && !IsKataSama(CKata, CTitik)){
            if (cntkata > 0) {
                printf(" ");
            }
            for (i=0;i<CKata.Length;i++){
                printf("%c", CKata.TabKata[i]);
            }

            if (CKata.Length >= 10) {
                KataPanjang++;
            } else {
                KataReg++;
            }
        } else {
            if (IsKataSama(CKata, CKoma)) {
                printf(",");
            } else if (IsKataSama(CKata, CTitik)) {
                printf(".");
            }
        }
        cntkata++;
        IgnoreBlank();
        ADVKATA();
    } 

    printf("\n");
    printf("%d\n", KataReg);
    printf("%d\n", KataPanjang);
    int total = (1000 * KataReg) + (1500 * KataPanjang);

    if (cntkata > 10) {
        total *= 0.9;
    }

    printf("%d\n", total);

    return 0;
}