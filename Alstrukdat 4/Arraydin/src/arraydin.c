/*
NIM: 13519218
Nama: Andres Jerriel Sinabutar
Tanggal: 15 September 2020
Topik praktikum: ADT List (Implementasi Array)
Deskripsi: Membuat implementasi ADT array dengan representasi eksplisit dan alokasi dinamik.
*/

#include "arraydin.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel)
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */
{
    TI(*T) = (ElType*) malloc(maxel * sizeof(ElType));
    Neff(*T) = 0;
    MaxEl(*T) = maxel;
}

void Dealokasi(TabInt *T)
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
{
    free(TI(*T));
    Neff(*T) = 0;
    MaxEl(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
    return Neff(T);
}

/* *** Daya tampung container *** */
int MaxElement(TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return MaxEl(T);
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return IdxMin;
}
IdxType GetLastIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return Neff(T) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return ((i >= IdxMin) && (i < MaxEl(T)));
}
boolean IsIdxEff(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return ((i >= IdxMin) && (i <= (Neff(T) - 1)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return (Neff(T) == 0);
}
/* *** Test tabel penuh *** */
boolean IsFull(TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return (Neff(T) == MaxEl(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T)
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
    ElType x;
    int n;
    IdxType i;
    scanf("%d", &n);
    while ((n < 0) || (n > MaxElement(*T))){
        scanf("%d", &n);
    }
    if (n > 0){
        for (i=0;i<n;i++){
            scanf("%d", &x);
            Elmt(*T, i) = x;
        } 
    } else {
        MakeEmpty(T, MaxEl(*T));
    }
    Neff(*T) = n;
}

void TulisIsiTab(TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
    IdxType i;
    if (IsEmpty(T)){
        printf("[]");
    } else {
        printf("[");
        for(i=0;i<GetLastIdx(T);i++){
            printf("%d,", Elmt(T, i));
        }
        printf("%d", Elmt(T, GetLastIdx(T)));
        printf("]");
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus)
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
    TabInt Tnew;
    MakeEmpty(&Tnew, MaxElement(T1));

    Neff(Tnew) = Neff(T1);
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
boolean IsEQ(TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
{
    boolean eq = true;

    if (Neff(T1) == Neff(T2)){
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
IdxType Search1(TabInt T, ElType X)
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

boolean SearchB(TabInt T, ElType X)
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
void MaxMin(TabInt T, ElType *Max, ElType *Min)
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
void CopyTab(TabInt Tin, TabInt *Tout)
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
{
    MakeEmpty(Tout, MaxElement(Tin));
    Neff(*Tout) = Neff(Tin);
    IdxType i;
    for (i = GetFirstIdx(Tin); i<= GetLastIdx(Tin); i++){
        Elmt(*Tout, i) = Elmt(Tin, i);
    }
}

ElType SumTab(TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{
    IdxType i = IdxMin;
    ElType jumlah = 0;
    if (!IsEmpty(T)){
        while (i <= GetLastIdx(T)){
            jumlah += Elmt(T,i);
            i += 1;
        }
    }

    return jumlah;
}

int CountX(TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{
    IdxType i = IdxMin;
    int cnt = 0;
    if (!IsEmpty(T)){
        while (i <= GetLastIdx(T)){
            if (Elmt(T,i) == X){
                cnt += 1;
            }
        i += 1;
        }
    }

    return cnt;
}

boolean IsAllGenap(TabInt T)
/* Menghailkan true jika semua elemen T genap. T boleh kosong */
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
void Sort(TabInt *T, boolean asc)
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
void AddAsLastEl(TabInt *T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
    Elmt(*T, (GetLastIdx(*T) + 1)) = X;
    Neff(*T) = Neff(*T) + 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{   
    *X = Elmt(*T, GetLastIdx(*T));
    Neff(*T)--;
}


/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num){
	/* Proses : Menambahkan max element sebanyak num */
	/* I.S. Tabel sudah terdefinisi */
	/* F.S. Ukuran tabel bertambah sebanyak num */

	// int* tmparray;
	// int i ;
	// tmparray = (int *) malloc ((MaxEl(*T)+num) * sizeof(int));
	// for (i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++){
	// 	tmparray[i] = Elmt(*T,i);
	// }
	// free(TI(*T));
	// TI(*T) = tmparray;
	// MaxEl(*T) = MaxEl(*T) + num ;
	// free(tmparray);
	TabInt tmpArray;
    IdxType i;

	CopyTab(*T, &tmpArray);
    Dealokasi(T);
    MakeEmpty(T, MaxElement(tmpArray)+num);
    
    for (i=GetFirstIdx(tmpArray); i<= GetLastIdx(tmpArray); i++){
        Elmt(*T,i) = Elmt(tmpArray, i);
    }
    
    Neff(*T) = Neff(tmpArray);
}


void ShrinkTab(TabInt *T, int num){
	/* Proses : Mengurangi max element sebanyak num */
	/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
	/* F.S. Ukuran tabel berkurang sebanyak num. */

	// int* tmparray;
	// int i ;
	// tmparray = (int *) malloc ((MaxEl(*T)-num) * sizeof(int));
	// for (i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++){
	// 	tmparray[i] = Elmt(*T,i);
	// }
	// free(TI(*T));
	// TI(*T) = tmparray;
	// MaxEl(*T) = MaxEl(*T) - num ;
	// free(tmparray);

	TabInt tmpArray;
    IdxType i;
    
    CopyTab(*T, &tmpArray);
    Dealokasi(T);
    MakeEmpty(T, MaxElement(tmpArray)-num);
    
    
    for (i=GetFirstIdx(tmpArray); i<= MaxElement(tmpArray)-num-1; i++){
        Elmt(*T,i) = Elmt(tmpArray, i);
    }
    
    Neff(*T) = Neff(tmpArray);
    
    if (MaxEl(*T) < Neff(*T)){
        Neff(*T) = MaxEl(*T);
    }
    Dealokasi(&tmpArray);
    
}


void CompactTab(TabInt *T){
	/* Proses : Mengurangi max element sehingga Neff = MaxEl */
	/* I.S. Tabel tidak kosong */
	/* F.S. Ukuran MaxEl = Neff */

	// int* tmparray;
	// int i, sel ;
	// sel = MaxEl(*T)-Neff(*T);
	// tmparray = (int *) malloc ((MaxEl(*T)-sel) * sizeof(int));
	// for (i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++){
	// 	tmparray[i] = Elmt(*T,i);
	// }
	// free(TI(*T));
	// TI(*T) = tmparray;
	// MaxEl(*T) = MaxEl(*T) - sel ;
	// free(tmparray);

	MaxEl(*T) = Neff(*T);

}
