#include <stdio.h>
#include <stdlib.h>

const int n = 5;

void zapovnennya_A(int a[]){
    int i;
    printf("Entering vector A...\n\n");
    for (i=0;i<4*n;i++){
       a[i] = i+1;
    }
}
void zamina_A(int a[]){
    int i;
    int k;

    for (i=0; i<n/2; i++){
        k = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = k;
        }

    for (i=0; i<n; i++){
        k = a[3*n + i];
        a[3*n + i] = a[i];
        a[i] = k;
    }



    for (i=0; i<n/2; i++){
        k = a[i+n];
        a[i+n] = a[2*n - i - 1];
        a[2*n - i - 1] = k;
    }


    for (i=0; i<n/2; i++){
        k = a[i+2*n];
        a[i+2*n] = a[3*n - i - 1];
        a[3*n - i - 1] = k;
    }
}
void vyvedennya_A(int a[]){
    int i;
    for(i = 0 ; i < 4*n; i++){
            printf("%d", a[i]) ;
            printf("  ");
    }
    printf("\n\n");
}
int main()
{
    int a[4*n];
    zapovnennya_A(a);

    printf("Vector A:\n\n");
    vyvedennya_A(a);

    zamina_A(a);

    printf("Modified vector A:\n\n");
    vyvedennya_A(a);

    return 0;
}
