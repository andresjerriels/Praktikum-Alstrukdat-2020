/*
NIM: 13519218
Nama: Andres Jerriel Sinabutar
Tanggal: 02 September 2020
Topik praktikum: ADT Sederhana
Deskripsi: Membuat implementasi ADT Jam
*/

#include <stdio.h>
#include "jam.h"
#include "boolean.h"

/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJAMValid (int H, int M, int S)
/* Mengirim true jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{
    return (((H <= 23) && (H >= 0)) && ((M >= 0) && (M <= 59)) && ((S >= 0) && (S <= 59)));
}

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS)
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
{
    JAM J;
    Hour(J) = HH;
    Minute(J) = MM;
    Second(J) = SS;
    return J;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J)
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh:
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */
{
    int h, m, s;
    scanf("%d %d %d", &h, &m, &s);
    while (!IsJAMValid(h, m, s))
    {
        printf("Jam tidak valid\n");
        scanf("%d %d %d", &h, &m, &s);
    }
    *J = MakeJAM(h, m, s);
}

void TulisJAM (JAM J)
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.
   Jika jam / menit / detik hanya satu digit, tuliskan satu digit tanpa 0 di depannya. */
{
    printf("%d:%d:%d", Hour(J), Minute(J), Second(J));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToDetik (JAM J)
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{
    long detik;
    detik = (3600 * Hour(J)) + (60 * Minute(J)) + Second(J);
    if (detik >= 86400){
        return detik - 86400;
    } else{
        return detik;
    }
}

JAM DetikToJAM (long N)
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
{
    long N1;
    int jam, menit, detik, sisa;
    if (N >= 86400){
        N1 = N % 86400;
        jam = N1 / 3600;
        sisa = N1 % 3600;
        menit = sisa / 60;
        detik = sisa % 60;
    } else if (N < 0){
        N += 86400;
        jam = N / 3600;
        sisa = N % 3600;
        menit = sisa / 60;
        detik = sisa % 60;
    } else
    {
        jam = N / 3600;
        sisa = N % 3600;
        menit = sisa / 60;
        detik = sisa % 60;
    }
    
    return MakeJAM(jam, menit, detik);
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1=J2, false jika tidak */
{
    return ((Hour(J1) == Hour(J2)) && (Minute(J1) == Minute(J2)) && (Second(J1) == Second(J2)));
}
boolean JNEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1 tidak sama dengan J2 */
{
    return ((Hour(J1) != Hour(J2)) || (Minute(J1) != Minute(J2)) || (Second(J1) != Second(J2)));
}
boolean JLT (JAM J1, JAM J2)
/* Mengirimkan true jika J1<J2, false jika tidak */
{
    long detik1, detik2;
    detik1 = JAMToDetik(J1);
    detik2 = JAMToDetik(J2);
    return (detik1 < detik2);
}

boolean JGT (JAM J1, JAM J2)
/* Mengirimkan true jika J1>J2, false jika tidak */
{
    long detik1, detik2;
    detik1 = JAMToDetik(J1);
    detik2 = JAMToDetik(J2);
    return (detik1 > detik2);
}
/* *** Operator aritmatika JAM *** */
JAM NextDetik (JAM J)
/* Mengirim 1 detik setelah J dalam bentuk JAM */
{
    long detik;
    detik = JAMToDetik(J);
    return DetikToJAM(detik + 1);
}
JAM NextNDetik (JAM J, int N)
/* Mengirim N detik setelah J dalam bentuk JAM */
{
    long detik;
    detik = JAMToDetik(J);
    return DetikToJAM(detik + N);
}
JAM PrevDetik (JAM J)
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
{
    long detik;
    detik = JAMToDetik(J);
    return DetikToJAM(detik - 1);
}
JAM PrevNDetik (JAM J, int N)
/* Mengirim N detik sebelum J dalam bentuk JAM */
/* *** Kelompok Operator Aritmetika *** */
{
    long detik;
    detik = JAMToDetik(J);
    return DetikToJAM(detik - N);
}
long Durasi (JAM JAw, JAM JAkh)
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
{
    long detikAw, detikAkh;
    detikAw = JAMToDetik(JAw);
    detikAkh = JAMToDetik(JAkh);
    if (detikAw > detikAkh){
        return detikAkh - detikAw + 86400;
    } else {
        return detikAkh - detikAw;
    }
}
