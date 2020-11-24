/*
NIM: 13519218
Nama: Andres Jerriel Sinabutar
Tanggal: 19 November 2020
Topik praktikum: ADT list linier dengan representasi pointer
Deskripsi: Membuat implementasi ADT List linier secara rekursif 
*/

#include "listrek.h"
#include <stdlib.h>

int total = 0;
List L1 = Nil;

boolean Tambahan(List L, int NbElmt, int n){
	if (IsEmpty(L)) {
        return true;
    } else {
	    total++; 
	    Tambahan(Tail(L), NbElmt + 1, n);
	}
    
	if ((n + NbElmt - 1) == total) {
        L1 = L;
    }

	if ((n + NbElmt) == total) {
        Dealokasi(L);
        if (NbElmt == 0) {
            return false;
        }
    }

	if ((n + NbElmt + 1) == total) {
        SetNext(L, L1); 
    }
}

List delNFromEnd(List L, int n) {
	if (IsEmpty(L)) {
        return L;
    }
	if (!Tambahan(L, 0, n)) {
        return L1;
    }
    return L;
}