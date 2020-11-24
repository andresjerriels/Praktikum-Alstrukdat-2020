/*
NIM: 13519218
Nama: Andres Jerriel Sinabutar
Tanggal: 11 November 2020
Topik praktikum: ADT List Berkait
Deskripsi: Membuat implementasi ADT List Sirkuler dengan elemen terakhir menunjuk pada elemen pertama
*/

#include "listsirkuler.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address P = (address) malloc(sizeof(ElmtList));

    if (P != NULL) {
        Info(P) = X;
        Next(P) = Nil;
        return P;
    } else {
        return Nil;
    }
}

void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    boolean found = false;
    address P = First(L);
    
    if (!IsEmpty(L)) {
        while (!found && Next(P) != First(L)) {
            if (Info(P) == X) {
                found = true;
            } else {
                P = Next(P);
            }
        }

        if (!found) {
            if (Info(P) == X) {
                found = true;
            }
        }
    }

    if (found) {
        return P;
    } else {
        return Nil;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address P = Alokasi(X);

    if (P != NULL){
        if (IsEmpty(*L)) {
            First(*L) = P;
            Next(First(*L)) = First(*L);
        } else {
            address last = First(*L);
            while (Next(last) != First(*L)) {
                last = Next(last);
            }

            Next(last) = P;
            Next(P) = First(*L);
            First(*L) = P;
        }
    }
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P = Alokasi(X);

    if (P != NULL) {
        if (IsEmpty(*L)) {
            First(*L) = P;
            Next(First(*L)) = First(*L);
        } else {
            address last = First(*L);
            while (Next(last) != First(*L)) {
                last = Next(last);
            }

            Next(last) = P;
            Next(P) = First(*L);
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    *X = Info(First(*L));
    address first = First(*L);

    if (Next(First(*L)) == First(*L)) {
        First(*L) = Nil;
    } else {
        address last = First(*L);
        while (Next(last) != First(*L)) {
            last = Next(last);
        }
        DelAfter(L, &first, last);
    }

    Dealokasi(first);
}

void DelVLast (List *L, infotype * X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{

    if (Next(First(*L)) == First(*L)) {
        *X = Info(First(*L));
        First(*L) = Nil;
        Dealokasi(First(*L));
    } else {
        address blast = First(*L);
        while (Next(Next(blast)) != First(*L)) {
            blast = Next(blast);
        }
        *X = Info(Next(blast));
        address P;

        DelAfter(L, &P, blast);
        Dealokasi(P);
    }
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    InsertLast(L, P);
    First(*L) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if (IsEmpty(*L)) {
        First(*L) = P;
        Next(First(*L)) = First(*L);
    } else {
        address last = First(*L);
        while (Next(last) != First(*L)) {
            last = Next(last);
        }

        InsertAfter(L, P, last);
    }
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);

    if (Next(First(*L)) == First(*L)) {
        First(*L) = Nil;
    } else {
        address last = First(*L);
        while (Next(last) != First(*L)) {
            last = Next(last);
        }
        DelAfter(L, P, last);
    }
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
    if (Next(First(*L)) == First(*L)) {
        *P = First(*L);
        First(*L) = Nil;
    } else {
        address blast = First(*L);
        while (Next(Next(blast)) != First(*L)) {
            blast = Next(blast);
        }
        DelAfter(L, P, blast);
    }
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    if (Next(Prec) == First(*L)) {
        First(*L) = Next(First(*L));
    } 
    
    if (Next(First(*L)) == First(*L)) {
        *Pdel = First(*L);
        First(*L) = Nil;
    } else {
        *Pdel = Next(Prec);
        Next(Prec) = Next(Next(Prec));
    }
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address P = Search(*L, X);

    if (P != NULL) {
        if (Next(First(*L)) == First(*L)) {
            First(*L) = Nil;
        } else {
            address beforeP = First(*L);
            while (Next(beforeP) != P) {
                beforeP = Next(beforeP);
            }

            DelAfter(L, &P, beforeP);
        }
        Dealokasi(P);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    if (IsEmpty(L)) {
        printf("[]");
    } else {
        address P = First(L);

        printf("[");
        while (Next(P) != First(L)) {
            printf("%d,", Info(P));
            P = Next(P);
        }

        printf("%d]", Info(P));
    }
}