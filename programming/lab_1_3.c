#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int m;
int n;
int i;
int j;
double mat[10][10] ;
double vecX[10];


double enterMatrix (int i, int j){
return (2.5*i +8.75*j - j - 3.);
}

void enterVectorX(){

    for(i = 0 ; i < m ; i++){
        double max = mat[i][0];
        double min = mat[i][0];

        for(j = 0 ; j < n; j++){
            if(mat[i][j]> max){
                max = mat[i][j];
            }
            else if(mat[i][j]<min){
                min = mat[i][j];
            }
        }
        vecX[i] = fabs(max - min) ;
    }
}

double functionMaxVec (){
    double maxVec = vecX[0];
    for(i = 1 ; i < m ; i++){
            if(fabs(vecX[i]) > maxVec){
                maxVec = vecX[i];
            }
        }
        return maxVec;
}

int main()
{

    printf("Enter the number of rows:") ;
    scanf("%d", &m) ;
    printf("\nEnter the number of collumns:") ;
    scanf("%d", &n) ;


    printf("\n\nEntering the matrix ...\n");

    for(i = 0 ; i < m ; i++){
        for(j = 0 ; j < n ; j++){
            mat[i][j] = enterMatrix(i,j) ;
        }
    }



    printf("\n\nThe elements in the matrix are: \n\n") ;
    for(i = 0 ; i < m ; i++){
        for(j = 0 ; j < n ; j++){
            printf("%0.3lf", mat[i][j]) ;
            printf("\t");
        }
        printf("\n");
    }

    printf("\n\nEntering the vector ...\n") ;

    enterVectorX();

    printf("\n\nThe elements in the vector X are: \n\n") ;
    for(i = 0 ; i < m ; i++){
        printf("%0.3lf", vecX [i]);
        printf("\t");
        }
    printf("\n");
    printf("\n\nExecuting the function ...\n\n");

    double maxVec = functionMaxVec();

    printf("\n\nFunction 'Max |Xi|' = %0.3lf \n\n", maxVec) ;


    return 0;
}

