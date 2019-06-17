#include <stdio.h>
#include <stdlib.h>

unsigned short int *Matrix;


void InputMatrix(int a,int b){
    Matrix = (unsigned short int*)malloc(a*b*sizeof(unsigned short int));
    int i,j;
    int l=0;
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            Matrix[i*b+j]=l;
            l++;
        }
    }

}

void Swap(int a,int b){
    int i,j;
    unsigned short B;
    for(i=0;i<a;i++){
        for(j=0;j<(b-1)/2;j++){
            B=Matrix[i*b+j];
            Matrix[i*b+j]=Matrix[i*b+b-1-j];
            Matrix[i*b+b-1-j]=B;
        }
    }
}

void OutputMatrix(int a,int b){
    int i,j;
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            printf(" %d ",Matrix[i*b+j]);
        }
        printf("\n");
    }
}


int main()
{
    int M1=4;
    int N1=7;
    int M2=9;
    int N2=3;
    InputMatrix(M1,N1);
    OutputMatrix(M1,N1);
    printf("\n");
    Swap(M1,N1);
    OutputMatrix(M1,N1);
    free(Matrix);

    printf("\n\n");

    InputMatrix(M2,N2);
    OutputMatrix(M2,N2);
    printf("\n");
    Swap(M2,N2);
    OutputMatrix(M2,N2);
    free(Matrix);

    return 0;
}
