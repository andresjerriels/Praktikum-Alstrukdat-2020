/*
NIM: 13519218
Nama: Andres Jerriel Sinabutar
Tanggal: 8 Oktober 2020 
Topik praktikum: ADT Queue
Deskripsi: Membuat implementasi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik
*/

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "prioqueuechar.h"

int main() {
    /*KAMUS*/
    int N;
    infotype Packet;
    PrioQueueChar Q;
    int i;
    int cPacket = 1;
    
    /*ALGORITMA*/
    scanf("%d", &N);
    MakeEmpty(&Q, 100);
    for(i = 0; i < N; i++){
        scanf("%d %c", &Prio(Packet), &Info(Packet));
        Enqueue(&Q, Packet);
        while(Prio(Elmt(Q, Head(Q)))==cPacket){
            Dequeue(&Q, &Packet);
            printf("%d %c\n", (i+1), Info(Packet));
            cPacket++;
        }
    }
    return 0;
    
}
