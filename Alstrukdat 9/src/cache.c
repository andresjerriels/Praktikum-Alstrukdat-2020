/*
NIM: 13519218
Nama: Andres Jerriel Sinabutar
Tanggal: 5 November 2020
Topik praktikum: ADT List Berkait
Deskripsi: Membuat driver ADT list berkait dengan representasi fisik pointer
*/

#include "boolean.h"
#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    int N, Q;
    scanf("%d", &N);
    scanf("%d", &Q);

    List L;
    CreateEmpty(&L);
    InsVFirst(&L, 1);
    address P = First(L);
    for (int i = 2; i <= N; i++) {
        InsVLast(&L, i);
    }

    int x = 1;
    int y;
    while (x <= Q) {
        scanf("%d", &y);
        address P1 = First(L);
        boolean found = false;
        
        while (P1 != Nil) {
            if (Info(P1) == y) {
                found = true;
            }
            P1 = Next(P1);
        }

        int a;
        if (found) {
            DelP(&L,y);
            InsVFirst(&L, y); 
            printf("hit ");
            PrintInfo(L);
            printf("\n");
        } else {
            DelVLast(&L, &a);
            InsVFirst(&L,y);
            printf("miss ");
            PrintInfo(L);
            printf("\n");
        }
        x++;
    }

    return 0;
}
