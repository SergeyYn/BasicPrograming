#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double recursion_down(int i, int n,double mult, double sum){
    if(i<=n){
        return recursion_down(++i,n,2*cos(mult)+i,sum+mult);
    }
    else{
        return sum;
    }
}

double mult_up = 1;

double recursion_up(int i, double sum){
    if(i<=1){
        return 1;
    }
    else{
        sum = recursion_up(i-1,0);
        mult_up = 2*cos(mult_up)+(i-1);
        sum = sum+mult_up;
        return sum;
            }
}

double recursion_down_n_up(int i ,int n , double mult ){

    if(i>n){
        return 0;
    }
    else{
      return mult+recursion_down_n_up(++i,n,2*cos(mult)+i);
    }
}


int main()
{
    int n;
    double mult = 1;
    double sum = 0;
    printf("Insert N:");
    scanf("%d", &n);
    int i;
    for(i=1;i<=n;i++){
        printf("mult|i = %lf|%d    ",mult,i);
        sum = sum+mult;
        mult = 2*cos(mult)+i;
    }
    printf("\n\n");
    printf("Recursion_Down sum=%lf\n\n\n",recursion_down(1,n,1,0));
    printf("Recursion_Up sum=%lf\n\n\n",recursion_up(n,0));
    printf("Recursion_Down'n'Up sum=%lf\n\n\n",recursion_down_n_up(1,n,1));
    printf("Cycle sum=%lf\n\n\n",sum);

    return 0;
}
