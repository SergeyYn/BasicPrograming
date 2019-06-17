#include "MErr.h"
#include "Module_1.h"
#include <stdio.h>
#include <stdlib.h>

void Function_4(){
    fprintf(log,"\nFunction 4 started\n");
    MErr();
    fprintf(log,"\nType 4 is:%c\n", tg_4.d);
    fprintf(log,"\nFunction 4 finished\n");
}

void Function_1(){
    fprintf(log,"\nFunction 1 started\n");
    MErr();
    fprintf(log,"\nType 1 is:%c\n", tg_1.a);
    Function_4();
    fprintf(log,"\nFunction 1 finished\n");
}
