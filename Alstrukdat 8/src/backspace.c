/*
NIM: 13519218
Nama: Andres Jerriel Sinabutar
Tanggal: 22 Oktober 2020
Topik praktikum: Mesin Token dan ADT Stack
Deskripsi: Membuat program Backspace
*/

#include "stackt.h"
#include <stdio.h>

int main(){
    int N,M;
    Stack S1,S2;

    infotype x1,x2;
    boolean sama;
    
    CreateEmpty(&S1);
    CreateEmpty(&S2);
    
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; i++){
        scanf("%d", &x1);
        if (x1 != 0){
            Push(&S1, x1);
        }
        else{
            if (!IsEmpty(S1)){
                Pop(&S1, &x2);
            }
        }
    }
    
    for (int i = 0; i < M; i++){
        scanf("%d", &x1);
        if (x1 != 0){
            Push(&S2, x1);
        }
        else{
            if (!IsEmpty(S2)){
                Pop(&S2, &x2);
            }
        }
    }
    sama = true;
    
    while (sama && (!IsEmpty(S1) || !IsEmpty(S2))){
        Pop(&S1, &x1);
        Pop(&S2, &x2);
        
        if ((x1 != x2) || (IsEmpty(S1)&&!IsEmpty(S2)) || (IsEmpty(S2)&&!IsEmpty(S1))){
            sama = false;
        }
    }
    
    if (sama) {
        printf("Sama\n");
    }
    else {
        printf("Tidak sama\n");
    }
    return 0;
}
