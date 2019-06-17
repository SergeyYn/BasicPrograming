#include <stdio.h>
#include <stdlib.h>
#include "MErr.h"
#include "Module_1.h"
#include "Module_2.h"
#include "Module_3.h"

struct type_1 tg_1 = {'1'};
struct type_2 tg_2 = {'2'};
struct type_3 tg_3 = {'3'};
struct type_4 tg_4 = {'4'};
struct type_5 tg_5 = {'5'};
const int Cg1 = 10;
const double Cg2 = 20.2;
const char Cg3 = 'a';
int Vg1 = 1;
double Vg2 = 2.2;
double Vg3 = 3.3;
int Vg4 = 4;
FILE *log;

int main()
{
    log = fopen("log.txt","w");
    fprintf(log,"\nMain started\n");
    MErr();
    Function_1();
    Function_2();
    Function_3();
    fprintf(log,"\nMain finished\n");
    fclose(log);
    return 0;
}
