#include <stdlib.h>
#include <stdio.h>
#include <math.h>


double a = 2.0,b = 3.0;

double function_Xi(int i,double h);

double function__F_xi(int i,int N,double h, double (*function_Xi)(int,double));

double function_Xi(int i, double h){
    return(a+i*h);
}
double function__F_xi(int i,int N,double h, double (*function_Xi)(int, double)){
    return(sin(1.0/(function_Xi(i,h)*log(function_Xi(i,h))*log(function_Xi(i,h)))));
}

int main(){
    int N = NULL,i;
    double result = 0.0;
    double (*p_function_Xi)(int,double) = function_Xi;
    while((N%2!=0)||(N<=0)){
        printf("Please enter positive number that is divisible by 2:\n");
        scanf("%d",&N);
    }
    double h = (b-a)/N;
    result = result + function__F_xi(0,N,h,p_function_Xi);
    for(i = 1;i<N;i++){
        result = result + ((i%2==1)?(4*function__F_xi(i,N,h,p_function_Xi)):(2*function__F_xi(i,N,h,p_function_Xi)));
    }

    result = result + function__F_xi(N,N,h,p_function_Xi);
    result = result*h/3.0;
    printf("\nResult_N: %lf",result);
    double delta;
    double result_2;
    do{
        N=N*2;
        h = (b-a)/N;
        result_2 = 0.0;
        result_2 = result_2 + function__F_xi(0,N,h,p_function_Xi);
        for(i = 1;i<N;i++){
            result_2 = result_2 + ((i%2==1)?(4*function__F_xi(i,N,h,p_function_Xi)):(2*function__F_xi(i,N,h,p_function_Xi)));
        }
        result_2 = result_2 + function__F_xi(N,N,h,p_function_Xi);
        result_2 = result_2*h/3.0;
        delta = fabs(result-result_2)/16.0;
        result = result_2;
    }while(delta>0.0000001);

    printf("\nResult : %lf",result);

    return 0;
}
