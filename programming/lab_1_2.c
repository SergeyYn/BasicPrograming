#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Euler 2.72

double x = -((M_PI)/3), step = 7;
double min = -((M_PI)/3), max = 2*(M_PI);

double cos_sum()
{
    double cos_s = 9 + cos(x);
    return cos_s;
}

double tg_sum()
{
    double tg_s = (tan(x)*tan(x) + 4*x);
    return tg_s;
}

double e_count()
{
    double e_c = exp(cos(x)*log(Euler));
    return e_c;
}
void line0()
{
    int i=0;
    for(;i<=64;i++)
    {
        if(i==0)printf("%c",195);
        else if(i==64)printf("%c",180);
        else if(i%16==0)printf("%c",197);
        else printf("%c",196);
    }
}


int main()
{
    int det = 0;
    int counter = 1;
    int i;
    for(i=1;i<=65;i++)
    {
        if(i==1)printf("%c",218);
        else if(i==65)printf("%c \n",191);
        else printf("%c",196);
    }
    printf("%c  \t\t    Single Argument function   \t\t        %c\n",179,179);
    for(i=0;i<65;i++)
    {
        if(i==0)printf("%c",195);
        else if(i==64)printf("%c\n",180);
        else if(i%16==0)printf("%c",194);
        else printf("%c",196);
    }

    printf("%c X Argument:   %c   9-COS(X)    %c  TG^2(x)+4*X  %c   E^(COS(X))  %c\n",179,179,179,179,179);

    for(;x<=max;)
    {
        if(det==1)
        {
            printf("%c X = %2.5lf\t%c %2.5lf\t%c %2.5lf\t%c  %2.5lf\t%c\n",179,x,179,cos_sum(x),179,tg_sum(x),179,e_count(x),179);
            x = min + counter*((max - min)/step);
            det = -1;
            counter++;
        }
        else
        {
            line0(),det = 1,printf("\n");
        }
    }
    for(i=1;i<66;i++)
    {
        if(i==1)printf("%c",195);
        else if(i==65)printf("%c\n",180);
        else if(i%16==1)printf("%c",193);
        else printf("%c",196);
    }

    printf("%c\tSklav Yershykhin Serhii KV-74, L.r No2  \t\t%c\n",179,179);

    for(i=0;i<65;i++)
    {
        if(i==0)printf("%c",192);
        else if(i==64)printf("%c\n",217);
        else printf("%c",196);
    }
    return 0;
}

