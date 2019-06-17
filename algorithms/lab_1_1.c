#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float X;
    float y;
    printf("Please insert X \n");
    scanf("%f" ,&X);

    if(X>-13&&X<=-3||X>14)
    {
        y = -4*X*X*X + 3*X - 7 ;
        printf("F(X) = -4(X^3) + 3X -7 = %f \n",y);
    }
    else
    {
        if(X>=2&&X<=7)
        {
            y = X*X*X + 14 ;
            printf("F(X) = X^3 + 14 = %f \n",y);
        }
        else
        {
            printf("Function is not assigned for this value of X \n");
        }
    }

    return 0;
}
