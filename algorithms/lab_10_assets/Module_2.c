#include "MErr.h"
#include <stdio.h>
#include <stdlib.h>
#include "Module_2.h"
#include "Module_3.h"

void Function_5(){
    fprintf(log,"\nFunction 5 started\n");
    MErr();
    fprintf(log,"\nType 5 is:%c\n", tg_5.e);
    fprintf(log,"\nFunction 5 finished\n");
}

void Function_2(){
    fprintf(log,"\nFunction 2 started\n");
    MErr();
    fprintf(log,"\nType 2 is:%c\n", tg_2.b);
    fprintf(log,"\nConst 2 is: %lf\n", Cg2);
    static int f = 0;
    if (f<2){
        Function_5();
        f++;
        Function_6();
    }
    f = 0;
    fprintf(log,"\nFunction 2 finished\n");
}
