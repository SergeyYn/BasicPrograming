#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14
#define e 2.72


float DefineA(float x, float y){
if(x==y)
{
    printf("A doesn't exist \n");
}
else
{
    if(y == -1)
    {
    printf("A doesn't exist \n");
    }
    else
    {
        if(y==5)
        {
           printf("A doesn't exist \n");
        }
        else
        {
           printf("A= %f\n", (exp((x+1)*log(y))/cbrt(abs(y-2)-3) + (x + y/2)/2*abs(x-y)));
        }
    }
}
return 0;
}


float DefineB(float x, float z)
{
    if(sin(z)==0)
    {
        printf("B doesn't exist \n");
    }
    else
    {
        printf("B= %f\n", exp((1/sin(z))*log(x+1)));
    }
return 0;
}



int main()
{
    float x, y, z;
    printf("Insert X, Y, Z \n");
    scanf("%f%f%f", &x, &y, &z);
    DefineA(x,y);
    DefineB(x,z);
    return 0;
}
