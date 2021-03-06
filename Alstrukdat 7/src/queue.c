/*
NIM: 13519218
Nama: Andres Jerriel Sinabutar
Tanggal: 6 Oktober 2020
Topik praktikum: ADT Queue
Deskripsi: Membuat implementasi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik
*/

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>


/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return (Head(Q) == Nil && Tail(Q) == Nil);
}

boolean IsFull (Queue Q)
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

int NBElmt (Queue Q)
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
void MakeEmpty (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    (*Q).T = (infotype *) malloc (Max * sizeof(infotype));
    if ((*Q).T != NULL){
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
        MaxEl(*Q) = Max;
    } else {
        MaxEl(*Q) = 0;
    }
}

/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    MaxEl(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Enqueue (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
    if (IsEmpty(*Q)) {
        Head(*Q) = 0;
    } else {
        if (Tail(*Q) == MaxEl(*Q)-1) {
            Tail(*Q) = -1;
        } 
    }

    Tail(*Q)++;
    InfoTail(*Q) = X;
}

void Dequeue (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
{
    *X = InfoHead(*Q);

    if (Head(*Q) == Tail(*Q)) {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        if (Head(*Q) == MaxEl(*Q)-1) {
            Head(*Q) = -1;
        } 
        Head(*Q)++;
    }
}
