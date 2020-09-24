#include <stdio.h>

int IsWithinRange(float X)
{
    if ((X >= 0.0) && (X <= 4.0)){
        return 0;
    } else {
        return 1;
    }
}

int main()
{
    float inpt, jml = 0.0, avg = 0.0;
    int cnt = 0, lulus = 0, tdklulus = 0;
    scanf("%f", &inpt);

    while (inpt != -999.0)
    {
        if (IsWithinRange(inpt) == 0) { 
            cnt += 1; 
            jml += inpt;    
            if (inpt >= 2.75) {
                lulus += 1;
            } else {
                tdklulus += 1;
            }
        }
        scanf("%f", &inpt);
    }

    if (cnt == 0) {
        printf("Tidak ada data\n");
    } else {
        avg = jml / cnt;
        printf("%d\n", cnt);
        printf("%d\n", lulus);
        printf("%d\n", tdklulus);
        printf("%.2f\n", avg);
    }

    return 0;
}