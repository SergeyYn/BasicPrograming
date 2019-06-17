#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define m 4
#define n 5


double A[m][n];
double X;
int Ri=-1,Rj=-1;
void input (){
    int i,j;
    srand(time(0));
    for (i=0;i<m;i++)
    {
        if (i==0)
            A[i][0]=rand()%95-30;
        else
            A[i][0]=A[i-1][n-1]-rand()%3;
        for (j=1;j<n;j++)
            A[i][j]=A[i][j-1]-rand()%3;
    }
}

void output (){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
        printf("%.3lf ",A[i][j]);
        }
        printf("\n");
    }
}

void search_1_row(){//в першому рядку
    int i,j,L,R;
    L=0;R=n-1;
     while(L<R){
        j=(L+R)/2;
        if(A[0][j] > X){
            L=j+1;
        }
        else{
            R=j;
        }
     }

     if(A[0][R]==X){
        Rj=R;
     }
return 0;
}

void search_last_collumn(){//в останньому стовпчику
    int i,L,R;
     L=0;R=m-1;
     while(L<R){
        i=(L+R)/2;
        if(A[i][n-1] > X){
            L=i+1;
        }
        else{
            R=i;
        }
     }

     if(A[R][n-1]==X){
        Ri=R;
     }

return 0;
}


int main()
{
    printf("Inputting matrix...\n\n");
    input();
    printf("Your matrix is:\n");
    output();
    printf("\n\n");
    printf("Please input X: ");
    scanf("%lf",&X);
    X=round(X*1000)/1000;

    printf("\nAnalysing matrix...\n\n");
    search_1_row();
    search_last_collumn();

    if(Rj>-1){
        printf("In first row element X = %.3lf is on position [0][%d].\n",X,Rj);
    }
    else{
        printf("In first row element X = %.3lf doesn't exist.\n",X);
    }
    if(Ri>-1){
        printf("In last collumn element X = %.3lf is on position [%d][%d].\n",X,Ri,n-1);
    }
    else{
        printf("In last collumn element X = %.3lf doesn't exist.\n",X);
    }


    return 0;
}
