/*
NIM: 13519218
Nama: Andres Jerriel Sinabutar
Tanggal: 8 Oktober 2020 
Topik praktikum: ADT Queue
Deskripsi: Membuat implementasi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik
*/


#include "prioqueuechar.h"
#include <stdlib.h>
#include <stdio.h>

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return (Tail(Q) == Nil && Head(Q) == Nil);
}
boolean IsFull (PrioQueueChar Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    boolean penuh = false;

    if (IsEmpty(Q)) {
        penuh = false;
    } else {
        if (Head(Q) > Tail(Q)) {
            penuh = (Head(Q) - Tail(Q)) == 1;
        } else if (Tail(Q) > Head(Q)) {
            penuh = (Head(Q) == 0) && (Tail(Q) == MaxEl(Q)-1);
        }
    }

    return penuh;
}
int NBElmt (PrioQueueChar Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    int total = 0;
    if (IsEmpty(Q)) {
        total = 0;
    } else {
        if (Head(Q) > Tail(Q)) {
            total = (MaxEl(Q) - Head(Q)) + (Tail(Q) + 1);
        } else if (Tail(Q) >= Head(Q)) {
            total = Tail(Q) - Head(Q) + 1;
        }
    }
    return total;
}

/* *** Kreator *** */
void MakeEmpty (PrioQueueChar * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    (*Q).T = (infotype*) malloc ((Max+1) * sizeof(infotype));
    
    if ((*Q).T != NULL){
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else{
        MaxEl(*Q) = 0;
    }
}
/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    MaxEl(*Q) = 0;
    free((*Q).T);
}
/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
{
    if (IsEmpty(*Q)){
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoTail(*Q)=X;

    }
    else{
        int countElmt = NBElmt(*Q);
        int idx = Tail(*Q);
        
        while ((Prio(X)<Prio(Elmt(*Q, idx))) && (countElmt > 0)){
            
            (*Q).T[(idx % MaxEl(*Q)) + 1] = (*Q).T[idx];
            
            idx-=1;
            countElmt-=1;
            
            if (idx==0){
                idx=MaxEl(*Q);
            }
        }
        
        (*Q).T[(idx % MaxEl(*Q))+1] = X;
        Tail(*Q) = (Tail(*Q) % MaxEl(*Q)) + 1;
    }
    
}

void Dequeue (PrioQueueChar * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    if (NBElmt(*Q)==1){
        Info(*X) = Info(InfoHead(*Q));
        Prio(*X) = Prio(InfoHead(*Q));
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else{
        Info(*X) = Info(InfoHead(*Q));
        Prio(*X) = Prio(InfoHead(*Q));
        if (Head(*Q) == MaxEl(*Q)-1) {
            Head(*Q) = Nil;
        } 
        Head(*Q)++;
    }
}
/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
{
    infotype CurrentElmt;
    while (!IsEmpty(Q)){
        Dequeue(&Q, &CurrentElmt);
        printf("%d %c\n", Prio(CurrentElmt), Info(CurrentElmt));
    }
    printf("#\n");
}
