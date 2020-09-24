/*
NIM: 13519218
Nama: Andres Jerriel Sinabutar
Tanggal: 08 September 2020
Topik praktikum: ADT List (Implementasi Array)
Deskripsi: Membuat implementasi ADT array dengan representasi implisit, alokasi statik dengan elemen bilangan bulat positif.
*/

#include "arraypos.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
{
    IdxType i = IdxMin;
    while (i <= IdxMax){
        Elmt(*T, i) = ValUndef;
        i += 1;
    }
    
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
    int i = IdxMin;
    int Neff = 0;
    while (i <= IdxMax){
        if (Elmt(T, i) != ValUndef){
            Neff += 1;
        }
        i += 1;
    }
    return Neff;
}

/* *** Daya tampung container *** */
int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return IdxMax + 1;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    IdxType first = IdxMin;
    return first;
}

IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    IdxType last = NbElmt(T) - 1;
    return last;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return ((i >= IdxMin) && (i <= IdxMax));
}

boolean IsIdxEff (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return ((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return (NbElmt(T) == 0);
}

/* *** Test tabel penuh *** */
boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return (NbElmt(T) == MaxNbEl(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
    int n = 0;

    scanf("%d", &n);
    while ((n < 0) || (n > MaxNbEl(*T))){
         scanf("%d\n", &n);
    }

    if (n == 0){
        MakeEmpty(T);
    } else {
        MakeEmpty(T);
        IdxType i = IdxMin;
        while (i < n){
            ElType x = 0;
            scanf("%d", &x);
            Elmt(*T, i) = x;
            i += 1;
        }
    }
}

void TulisIsiTab (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
    IdxType i = GetFirstIdx(T);
    if (IsEmpty(T)){
        printf("[]");
    } else {
        printf("[");
        while (i < GetLastIdx(T)){
            printf("%d,", Elmt(T, i));
            i += 1;
        }
        printf("%d", Elmt(T, GetLastIdx(T)));
        printf("]");
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab (TabInt T1, TabInt T2, boolean plus)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
    TabInt Tnew = T1;
    IdxType i = GetFirstIdx(T1);
    if (plus){
        while (i <= GetLastIdx(T1)){
            Elmt(Tnew, i) = Elmt(T1, i) + Elmt(T2, i);
            i += 1;
        }
    } else {
        while (i <= GetLastIdx(T1)){
            Elmt(Tnew, i) = Elmt(T1, i) - Elmt(T2, i);
            i += 1;
        }
    }

    return Tnew;
}
/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
    boolean eq = true;

    if (NbElmt(T1) == NbElmt(T2)){
        IdxType i = GetFirstIdx(T1);

        while(i <= GetLastIdx(T1)){
            if (Elmt(T1, i) != Elmt(T2, i)){
                eq = false;
            }
            i += 1;
        }
    } else {
            eq = false;
        }
    
    return eq;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
    IdxType hasil = 0, i = IdxMin;
    boolean found = false;

    while ((!found) && (i <= GetLastIdx(T))){
        if (Elmt(T, i) == X){
            found = true;
        }
        i += 1;
    }

    if (found){
        hasil = i - 1;
    } else {
        hasil = IdxUndef;
    }

    return hasil;
}

boolean SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{
    IdxType i = IdxMin;
    boolean found = false;

    while ((!found) && (i <= GetLastIdx(T))){
        if (Elmt(T, i) == X){
            found = true;
        }
        i += 1;
    }

    return found;
}

/* ********** NILAI EKSTREM ********** */
void MaxMin (TabInt T, ElType * Max, ElType * Min)
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
    IdxType i = IdxMin + 1;
    ElType min, max;
    min = Elmt(T, IdxMin);
    max = Elmt(T, IdxMin);

    while (i <= GetLastIdx(T)){
        if (Elmt(T, i) <= min){
            min = Elmt(T, i);
        }
        if (Elmt(T, i) >= max){
            max = Elmt(T, i);
        }
        i += 1;
    }

    *Max = max;
    *Min = min;
}

/* ********** OPERASI LAIN ********** */
ElType SumTab (TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{
    IdxType i = IdxMin;
    ElType jumlah = 0;
    if (NbElmt(T) != 0){
        while (i <= GetLastIdx(T)){
            jumlah += Elmt(T,i);
            i += 1;
        }
    }

    return jumlah;
}

int CountX (TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{
    IdxType i = IdxMin;
    int cnt = 0;
    if (NbElmt(T) != 0){
        while (i <= GetLastIdx(T)){
            if (Elmt(T,i) == X){
                cnt += 1;
            }
        i += 1;
        }
    }

    return cnt;
}
boolean IsAllGenap (TabInt T)
/* Menghailkan true jika semua elemen T genap */
{
    IdxType i = IdxMin;
    boolean allgenap = true;
    while (i <= GetLastIdx(T)){
        if (Elmt(T, i) % 2 != 0){
            allgenap = false;
        }
        i += 1;
    }
    
    return allgenap;
}

/* ********** SORTING ********** */
void Sort (TabInt * T, boolean asc)
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
{
    if (asc){
        IdxType i, key, j; 
        for (i = IdxMin; i < NbElmt(*T); i++) { 
            key = Elmt(*T, i); 
            j = i - 1; 
  
        /* Move elements of arr[0..i-1], that are 
          greater than key, to one position ahead 
          of their current position */
            while (j >= 0 && Elmt(*T, j) > key) { 
                Elmt(*T, (j + 1)) = Elmt(*T, j); 
                j = j - 1; 
            } 
        Elmt(*T, (j + 1)) = key;
        }
    } else {
        IdxType i, key, j; 
        for (i = IdxMin; i < NbElmt(*T); i++) { 
            key = Elmt(*T, i); 
            j = i - 1; 
  
        /* Move elements of arr[0..i-1], that are 
          greater than key, to one position ahead 
          of their current position */
            while (j >= 0 && Elmt(*T, j) < key) { 
                Elmt(*T, (j + 1)) = Elmt(*T, j); 
                j = j - 1; 
            } 
        Elmt(*T, (j + 1)) = key;
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
    Elmt(*T, GetLastIdx(*T) + 1) = X;
}
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{   
    *X = Elmt(*T, GetLastIdx(*T));
    Elmt(*T, GetLastIdx(*T)) = ValUndef;
}
