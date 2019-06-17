#include "MErr.h"
#include <stdio.h>
#include <stdlib.h>
#include "Module_3.h"
#include "Module_2.h"

void Function_7(){
    fprintf(log,"\nFunction 7 started\n");
    MErr();
    fprintf(log,"\nVar 1 and 3 are: %d , %lf\n", Vg1,Vg3);
    fprintf(log,"\nFunction 7 finished\n");
}
void Function_8(){
    fprintf(log,"\nFunction 8 started\n");
    MErr();
    fprintf(log,"\nVar 2 and 4 are: %lf , %d\n", Vg2,Vg4);
    fprintf(log,"\nFunction 8 finished\n");
}

void Function_6(){
    fprintf(log,"\nFunction 6 started\n");
    MErr();
    static int flag = 0;
    if (flag<2){
        flag++;
        Function_2();
    }
    flag=0;
    fprintf(log,"\nConst 1 and 3 are: %d, %c\n",Cg1, Cg3);
    fprintf(log,"\nFunction 6 finished\n");
}


void Function_3(){
    fprintf(log,"\nFunction 3 started\n");
    MErr();
    fprintf(log,"\nType 3 is:%c\n", tg_3.c);
    Function_6();
    Function_7();
    Function_8();
    fprintf(log,"\nFunction 3 finished\n");
}
