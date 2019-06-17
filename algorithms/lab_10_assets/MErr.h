#pragma once
#include <stdio.h>
#include <stdlib.h>

struct type_1{
    char a;
};
struct type_2{
    char b;
};
struct type_3{
    char c;
};
struct type_4{
    char d;
};
struct type_5{
    char e;
};
extern const int Cg1;
extern const double Cg2 ;
extern const char  Cg3;
extern int Vg1;
extern double Vg2;
extern double Vg3;
extern int Vg4;
extern struct type_1 tg_1;
extern struct type_2 tg_2;
extern struct type_3 tg_3;
extern struct type_4 tg_4;
extern struct type_5 tg_5;
extern FILE *log;
void MErr();
