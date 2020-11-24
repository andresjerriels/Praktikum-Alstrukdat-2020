/*
NIM: 13519218
Nama: Andres Jerriel Sinabutar
Tanggal: 5 November 2020
Topik praktikum: ADT List Berkait
Deskripsi: Membuat implementasi ADT list berkait dengan representasi fisik pointer
*/

#include "boolean.h"
#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
    return First(L) == Nil;
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
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

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    boolean found = false;
    address P1 = First(L);

    while (!found && P1 != Nil) {
        if (Info(P1) == X) {
            found = true;
        } else {
            P1 = Next(P1);
        }
    }

    return P1;
}

boolean FSearch (List L, address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
    boolean found = false;
    address P1 = First(L);

    if (!IsEmpty(L)) {
        while (!found && P1 != Nil) {
            if (P1 == P) {
                found = true;
            } else {
                P1 = Next(P1);
            }
        }
    }

    return found;
}

address SearchPrec (List L, infotype X)
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
    boolean found = false;
    address P1 = First(L);

    if (!IsEmpty(L)) { 
        if (Info(P1) != X) {
            while (!found && Next(P1) != Nil) {
                if (Info(Next(P1)) == X) {
                    found = true;
                } else {
                    P1 = Next(P1);
                }
            }
        }
    }

    if (found) {
        return P1;
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

    if (P != Nil) {
        InsertFirst(L, P);
    }
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P = Alokasi(X);

    if (P != Nil) {
        InsertLast(L, P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address P;
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address P;
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;   
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    Next(P) = Nil;

    if (IsEmpty(*L)) {
        First(*L) = P;
    } else {
        address P1 = First(*L);

        while (Next(P1) != Nil) {
            P1 = Next(P1);
        }

        Next(P1) = P;
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    First(*L) = Next(*P);
    
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address P1 = Search(*L, X);

    if (P1 != Nil) {
        if (Info(First(*L)) == X) {
            DelFirst(L, &P1);
        } else {
            address P = First(*L);
            while (Next(P) != P1) {
                P = Next(P);
            }
            DelAfter(L, &P1, P);
        }
        Dealokasi(&P1);
    }
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    if (Next(First(*L)) == Nil) {
        DelFirst(L, P);
    } else {
        address P1 = First(*L);
        while (Next(Next(P1)) != Nil) {
            P1 = Next(P1);
        }
        *P = Next(P1);
        Next(P1) = Nil;
    }
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    if (*Pdel != Nil) {
        Next(Prec) = Next(*Pdel);
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
    if (IsEmpty(L)){
        printf("[]");
    } else {
        address P = First(L);
        printf("[");
        while (P != Nil) {
            printf("%d", Info(P));
            if (Next(P) != Nil) {
                printf(",");
            }
            P = Next(P);
        }
        printf("]");
    }
}

int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int cnt = 0;

    if (!IsEmpty(L)) {
        address P = First(L);

        while (P != Nil) {
            cnt += 1;
            P = Next(P);
        }        
    }

    return cnt;
}
/*** Prekondisi untuk Min: List tidak kosong ***/
infotype Min (List L)
/* Mengirimkan nilai Info(P) yang minimum */
{
    address P = First(L);
    infotype min = Info(P);

    while (P != Nil) {
        if (Info(P) < min) {
            min = Info(P);
        }
        P = Next(P);
    }

    return min;
}

address AdrMin (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
{
    address P = First(L);
    address Pmin = First(L);

    while (P != Nil) {
        if (Info(P) < Info(Pmin)) {
            Pmin = P;
        }
        P = Next(P);
    }

    return Pmin;
}

/*** Prekondisi untuk Max: List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
    address P = First(L);
    infotype max = Info(P);

    while (P != Nil) {
        if (Info(P) > max) {
            max = Info(P);
        }
        P = Next(P);
    }

    return max;
}

address AdrMax (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
{
    address P = First(L);
    address Pmax = First(L);

    while (P != Nil) {
        if (Info(P) > Info(Pmax)) {
            Pmax = P;
        }
        P = Next(P);
    }

    return Pmax;
}

float Average (List L)
/* Mengirimkan nilai rata-rata info(P) */
{
    infotype sum = 0;
    float avg = 0;

    if (!IsEmpty(L)) {
        address P = First(L);
        while (P != Nil) {
            sum += Info(P);
            P = Next(P);
        }        
        avg = sum / NbElmt(L);
    }

    return avg;
}

/****************** PROSES TERHADAP LIST ******************/
void DelAll (List *L)
/* Delete semua elemen list dan alamat elemen di-dealokasi */
{
    infotype X;
    while (!IsEmpty(*L)) {
        DelVFirst(L, &X);
    }
}

void InversList (List *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
    List L1;
    CreateEmpty(&L1);
    address P = First(*L);

    while (P != Nil){
        InsertFirst(&L1, P);
        P = Next(P);
    }

    CopyList(&L1, L);
}

List FInversList (List L)
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
    List L1;
    address P;
    infotype X;
    boolean gagal = false;
    CreateEmpty(&L1);

    while (!IsEmpty(L) && !gagal){
        DelVFirst(&L, &X);
        P = Alokasi(X);
        if (P != Nil) {
            InsertFirst(&L1, P);
        } else {
            DelAll(&L1);
            gagal = true;
        }
    }

    return L1;
}

void CopyList (List *L1, List *L2)
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
{
    First(*L2) = First(*L1);
}

List FCopyList (List L)
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
    List L1;
    CreateEmpty(&L1);
    boolean gagal = false;
    address P = First(L);
    address Pnew;
    infotype X;

    while (P != Nil && !gagal) {
        X = Info(P);
        Pnew = Alokasi(X);
        if (Pnew != Nil) {
            InsertLast(&L1, Pnew);
            P = Next(P);
        } else {
            DelAll(&L1);
            gagal = true;
        }
    }

    return L1;
}

void CpAlokList (List Lin, List *Lout)
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */
{
    CreateEmpty(Lout);
    *Lout = FCopyList(Lin);
}

void Konkat (List L1, List L2, List * L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang "baru" */
/* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */
{
	address L3temp ;
	if (IsEmpty(L1)) {
        CpAlokList(L2, L3);
    } else {
        CpAlokList(L1, L3);
        L3temp = First(*L3);
        while (Next(L3temp) != Nil) {
            L3temp = Next(L3temp);
        }
        Next(L3temp) = First(L2);
    }
}

void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    CreateEmpty(L3);
    if (!IsEmpty(*L1)) {
        address P1 = First(*L1);
        while (Next(P1) != Nil) {
            P1 = Next(P1);
        }
        Next(P1) = First(*L2);
        First(*L3) = First(*L1);
    } else {
        First(*L3) = First(*L2);
    }
    
    CreateEmpty(L1);
    CreateEmpty(L2);
}

void PecahList (List *L1, List *L2, List L)
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */
{
    int i;
    address(P);

    CpAlokList(L, L1);
    CpAlokList(L, L2);
	int cntL1 = NbElmt(L)/2;
	int cntL2= NbElmt(L)-cntL1;
	for (i=1; i<=cntL2; i++) {
        DelLast(L1, &P);
    }
    for (i=1; i<=cntL1; i++) {
        DelFirst(L2, &P);
    }
}
