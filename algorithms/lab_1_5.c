#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int m = 7;
    const int n = 8;
    double a[m][n];
    int i,j;
    int k = 1;
    int imin = 0;
    int jmin = 0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            a[i][j] = rand()% 200;
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%0.3lf", a[i][j]);
            printf("\t\t");
        }
        printf("\n");
    }

    double min = a[0][0];
    for(j=0;j<n;j++){
        for(i=0;i<m;i++){
                if(a[i][j]<min){
                   min = a[i][j];
                   imin = i;
                   jmin = j;
                }
        }
    }
    printf("Minimal element is %0.3lf on position %d  %d", min, imin, jmin);
}
