#include <stdio.h>
#include <stdlib.h>

const int n = 4;

void zapovnennya_A(int a[]){
    int i;
    printf("Entering vector A...\n\n");
    for (i=0;i<4*n;i++){
       a[i] = i+1;
    }
}
void zamina_A(int a[], int b[] ){
    int i;

    for (i=0; i<n; i++){
        b[i] = a[i];
    }
    for (i=0; i<n; i++){
        a[n - i - 1] = b[i];
    }



    for (i=0; i<n; i++){
        b[i] = a[3*n + i];
        a[3*n + i] = a[i];
    }
    for (i=0; i<n; i++){
        a[i] = b[i];
    }



    for (i=0; i<n; i++){
        b[i] = a[i+n];
    }
    for (i=0; i<n; i++){
        a[2*n - i - 1] = b[i];
    }



    for (i=0; i<n; i++){
        b[i] = a[i+2*n];
    }
    for (i=0; i<n; i++){
        a[3*n - i - 1] = b[i];
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
    int b[n];
    zapovnennya_A(a);

    printf("Vector A:\n\n");
    vyvedennya_A(a);

    zamina_A(a, b);

    printf("Modified vector A:\n\n");
    vyvedennya_A(a);

    return 0;
}
