/*
NIM: 13519218
Nama: Andres Jerriel Sinabutar
Tanggal: 24 September 2020
Topik praktikum: ADT Matriks
Deskripsi: Membuat implementasi ADT Matriks.
*/

#include <stdio.h>
#include "matriks.h"


/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
   NBrsEff(*M) = NB;
   NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
   return (i >= BrsMin) && (i <= BrsMax) && (j >= KolMin) && (j <= KolMax);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
   return BrsMin;
}
indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
   return KolMin;
}
indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
   return NBrsEff(M) - 1;
}
indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
   return NKolEff(M) - 1;
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
   return (i >= BrsMin) && (i <= GetLastIdxBrs(M)) && (j >= KolMin) && (j <= GetLastIdxKol(M));
}
ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
   return Elmt(M, i, i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
   *MHsl = MIn;
}

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
   MakeMATRIKS(NB, NK, M);

   indeks i, j;
   for (i=0;i<=GetLastIdxBrs(*M);i++){
      for (j=0;j<=GetLastIdxKol(*M);j++){
         scanf("%d", &Elmt(*M, i, j));
      }
   }
}
void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
   indeks i, j;
   for (i=0;i<=GetLastIdxBrs(M);i++){
      for (j=0;j<=GetLastIdxKol(M);j++){
         if ((i != GetLastIdxBrs(M)) && (j == GetLastIdxKol(M))){
            printf("%d\n", Elmt(M, i, GetLastIdxKol(M)));
         } else if((i == GetLastIdxBrs(M)) && (j == GetLastIdxKol(M))){
            printf("%d", Elmt(M, GetLastIdxBrs(M), GetLastIdxKol(M)));
         } else {
            printf("%d ", Elmt(M, i, j));
         }
      }
      
   }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{
   MATRIKS Mnew;
   CopyMATRIKS(M1, &Mnew);
   indeks i, j;

   for (i=0;i<=GetLastIdxBrs(M1);i++){
      for (j=0;j<=GetLastIdxKol(M1);j++){
         Elmt(Mnew, i, j) += Elmt(M2, i, j);
      }
   }

   return Mnew;
} 
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 
{
   MATRIKS Mnew;
   CopyMATRIKS(M1, &Mnew);
   indeks i, j;

   for (i=0;i<=GetLastIdxBrs(M1);i++){
      for (j=0;j<=GetLastIdxKol(M1);j++){
         Elmt(Mnew, i, j) -= Elmt(M2, i, j);
      }
   }

   return Mnew;
}
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
   MATRIKS Mnew;
   MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &Mnew);
   indeks i, j, x;

   for (i=0;i<=GetLastIdxBrs(Mnew);i++){
      for (j=0;j<=GetLastIdxKol(Mnew);j++){
         ElType tmp = 0;
         for (x=0;x<=GetLastIdxKol(M1);x++){
            tmp += (Elmt(M1, i, x) * Elmt(M2, x, j));
         }
         Elmt(Mnew, i, j) = tmp;
      }
   }

   return Mnew;
}
MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
   MATRIKS Mnew;
   MakeMATRIKS(NBrsEff(M), NKolEff(M), &Mnew);
   indeks i, j;

   for (i=0;i<=GetLastIdxBrs(M);i++){
      for (j=0;j<=GetLastIdxKol(M);j++){
         Elmt(Mnew, i, j) = Elmt(M, i, j) * X;
      }
   }

   return Mnew;
}
void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
   indeks i, j;

   for (i=0;i<=GetLastIdxBrs(*M);i++){
      for (j=0;j<=GetLastIdxKol(*M);j++){
         Elmt(*M, i, j) = Elmt(*M, i, j) * K;
      }
   }

}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
   boolean eq = true;
   
   if ((GetLastIdxBrs(M1) == GetLastIdxBrs(M2)) && (GetLastIdxKol(M1) == GetLastIdxKol(M2))){
      indeks i = 0;
      while ((i <= GetLastIdxBrs(M1)) && eq){
         indeks j = 0;
         while ((j <= GetLastIdxKol(M1)) && eq){
            if (Elmt(M1, i, j) != Elmt(M2, i, j)){
               eq = false;
            }
            j++;
         }
         i++;
      }
   } else
   {
      eq = false;
   }

   return eq;
}
boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
   boolean eq = true;
   
   if ((GetLastIdxBrs(M1) == GetLastIdxBrs(M2)) && (GetLastIdxKol(M1) == GetLastIdxKol(M2))){
      indeks i = 0;
      while ((i <= GetLastIdxBrs(M1)) && eq){
         indeks j = 0;
         while ((j <= GetLastIdxKol(M1)) && eq){
            if (Elmt(M1, i, j) != Elmt(M2, i, j)){
               eq = false;
            }
            j++;
         }
         i++;
      }
   } else
   {
      eq = false;
   }

   return !eq;
}
boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
   return ((NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M1) == NKolEff(M2)));
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
   return NBrsEff(M) * NKolEff(M);
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
   return NBrsEff(M) == NKolEff(M);
}
boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
   boolean simetri = true;

   if (IsBujurSangkar(M)) {
      indeks i = 0;
      while ((i <= GetLastIdxBrs(M)) && simetri){
         indeks j = 0;
         while ((j <= GetLastIdxKol(M)) && simetri){
            simetri = (Elmt(M, i, j) == Elmt(M, j, i));
            j++;
         }
         i++;
      }
   } else {
      simetri = false;
   }

   return simetri;
}
boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
{
   boolean satuan = true;
   
   if (IsBujurSangkar(M)) {
      indeks i = 0;
      while ((i <= GetLastIdxBrs(M)) && satuan){
         indeks j = 0;
         while ((j <= GetLastIdxKol(M)) && satuan){
            if (i == j){
               satuan = (Elmt(M, i, j) == 1);
            } else {
               satuan = (Elmt(M, i, j) == 0);
            }
            j++;
         }
         i++;
      }
   } else {
      satuan = false;
   }

   return satuan;
}
boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
{
   float cnt = 0;
   float percent = 0;
   indeks i, j;

   for (i=0;i<=GetLastIdxBrs(M);i++){
      for (j=0;j<=GetLastIdxKol(M);j++){
         if (Elmt(M, i, j) != 0){
            cnt += 1;
         }
      }
   }

   percent = (cnt / NBElmt(M));
   return (percent <= 0.05);
}
MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
   MATRIKS Mnew;
   CopyMATRIKS(M, &Mnew);
   indeks i, j;

   for (i=0;i<=GetLastIdxBrs(M);i++){
      for (j=0;j<=GetLastIdxKol(M);j++){
         Elmt(Mnew, i, j) = Elmt(M, i, j) * (-1);
      }
   }

   return Mnew;
}
float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{  
   int n = NBrsEff(M);

   if (n<=0) return 0;                                 // stop recursion
   if (n==1) return Elmt(M, 0, 0);                           // stop recursion
   if (n==2) return Elmt(M, 0, 0) * Elmt(M, 1, 1) - Elmt(M, 0, 1) * Elmt(M, 1, 0); // stop recursion
   int i, aj, bj, k, p, sign;
   MATRIKS b;
   MakeMATRIKS(n-1, n-1, &b);

   for (p=0,  sign=+1, k = 0;k<n;k++,sign=-sign) {
      for (i=1; i<n; i++) {
         for (aj=0,bj=0;aj<n;aj++) {
            if (aj!=k) {
               Elmt(b, i-1, bj) = Elmt(M, i, aj);
               ++bj;
            }
         }
      }
      p = p + (sign * Elmt(M, 0, k) * Determinan(b)); // here you had aj instead of k causing problems !!!
   }
   return p;
}
void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
   PKaliKons(M, -1);
}
void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
   MATRIKS Mnew;
   CopyMATRIKS(*M, &Mnew);
   indeks i, j;

   for (i=0;i<=GetLastIdxBrs(*M);i++){
      for (j=0;j<=GetLastIdxKol(*M);j++){
         Elmt(Mnew, i, j) = Elmt(*M, j, i);
      }
   }

   *M = Mnew;
}

/* Operasi berbasis baris dan per kolom */
float RataBrs (MATRIKS M, indeks i)
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
{
   indeks j;
   float sum = 0;
   for (j=0;j<=GetLastIdxKol(M);j++){
      sum += Elmt(M, i, j);
   }

   return sum / NKolEff(M);
}
float RataKol (MATRIKS M, indeks j)
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
{
   indeks i;
   float sum = 0;
   for (i=0;i<=GetLastIdxBrs(M);i++){
      sum += Elmt(M, i, j);
   }

   return sum / NBrsEff(M);
}
void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min)
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
{
   indeks j;
   *max = Elmt(M, i, 0);
   *min = Elmt(M, i, 0);
   for (j=1;j<=GetLastIdxKol(M);j++){
      if (Elmt(M, i, j) > *max){
         *max = Elmt(M, i, j);
      }
      if (Elmt(M, i, j) < *min){
         *min = Elmt(M, i, j);
      }
   }
}
void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min)
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
{
   indeks i;
   *max = Elmt(M, 0, j);
   *min = Elmt(M, 0, j);
   for (i=1;i<=GetLastIdxBrs(M);i++){
      if (Elmt(M, i, j) > *max){
         *max = Elmt(M, i, j);
      }
      if (Elmt(M, i, j) < *min){
         *min = Elmt(M, i, j);
      }
   }
}
int CountXBrs (MATRIKS M, indeks i, ElType X)
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
{
   indeks j;
   int cnt = 0;
   for (j=0;j<=GetLastIdxKol(M);j++){
      if (Elmt(M, i, j) == X){
         cnt += 1;
      }
   }
   return cnt;
}
int CountXKol (MATRIKS M, indeks j, ElType X)
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
{
   indeks i;
   int cnt = 0;
   for (i=0;i<=GetLastIdxBrs(M);i++){
      if (Elmt(M, i, j) == X){
         cnt += 1;
      }
   }
   return cnt;
}
