#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define m 7
#define n 4

int A[m][n];

void fill_rand(){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
         A[i][j]=rand();
        }
    }
}

void fill_0_to_n(){
    int i,j;
    int k = 0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
         A[i][j]=k;
         k++;
        }
    }
}

void fill_n_to_0(){
    int i,j;
    int k = m*n-1;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
         A[i][j]=k;
         k--;
        }
    }
}

void print_matrix(){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
        if(A[i][j]>9&&A[i][j]<99){
         printf("%d    ",A[i][j]);
         }
        else if(A[i][j]>99&&A[i][j]<999){
            printf("%d   ",A[i][j]);
         }
        else if(A[i][j]>999&&A[i][j]<9999){
            printf("%d  ",A[i][j]);
         }
         else if(A[i][j]>9999){
            printf("%d ",A[i][j]);
         }
         else{
         printf("%d     ",A[i][j]);
         }
        }
        printf("\n");
    }
}

void sort(){
    srand(time(NULL));
    int i,S, imin, min;
    for (S=m-2;S>0;S-=2){
        min = A[S][0];
        imin = S;
        for (i=S-2;i>0;i-=2){
            if(A[i][0]<min){
                min = A[i][0];
                imin=i;
            }
        }
        A[imin][0] = A[S][0];
        A[S][0] = min;
    }

}
int main()
{
    fill_0_to_n();
    print_matrix();
    printf("\n\n");

    sort();
    print_matrix();
    printf("\n\n");

    fill_n_to_0();
    print_matrix();
    printf("\n\n");

    sort();
    print_matrix();
    printf("\n\n");

    fill_rand();
    print_matrix();
    printf("\n\n");
    sort();
    print_matrix();
    return 0;
}
