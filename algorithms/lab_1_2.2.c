#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    double P=1;
    int n;
    double i;
    double j;
    printf("Please insert N \n");
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        P=P*(i+sqrt(i))/(4./3.*(((1+i)*i)/2.)-i);
    }

    printf("%0.7lf \n",P);

    return 0;
}
