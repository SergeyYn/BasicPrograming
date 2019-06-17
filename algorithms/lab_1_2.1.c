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
        double S=0;
        for(j=1;j<=i;j++)
        {
        S=S+(4.*j/3.-1);
        }

    P=P*((i+sqrt(i))/S);
    }
    printf("%0.7lf \n",P);

    return 0;
}
