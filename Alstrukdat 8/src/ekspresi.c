/*
NIM: 13519218
Nama: Andres Jerriel Sinabutar
Tanggal: 6 Oktober 2020
Topik praktikum: ADT Stack
Deskripsi: Membuat driver Mesin Token dan ADT Stack 
*/

#include "stackt.h"
#include "mesintoken.h"
#include <math.h>
#include <stdio.h>

int Hitung(int x, int y, char op) {
    int result;
    if (op == '+') {
        result = x + y;
    } else if (op == '-') {
        result = x - y;
    } else if (op == '*') {
        result = x * y;
    } else if (op == '/') {
        result = x / y;
    } else if(op == '^') {
        result = pow(x,y);
    }

    return result;
}

int main() {
    Stack S1;
    int x, y;
    CreateEmpty(&S1);

    STARTTOKEN();

    if (EndToken) {
        printf("Ekspresi kosong\n");
    } else {
        while (!EndToken) {
            if (CToken.tkn != 'b') {
                Pop(&S1, &y);
                Pop(&S1, &x);
                Push(&S1, Hitung(x, y, CToken.tkn));
                printf("%d %c %d\n", x, CToken.tkn, y);
                printf("%d\n", Hitung(x, y, CToken.tkn));
            } else {
                Push(&S1, CToken.val);
                printf("%d\n", CToken.val);
            }
            ADVTOKEN();
        }
        printf("Hasil=%d\n", InfoTop(S1));
    }

    return 0;
}