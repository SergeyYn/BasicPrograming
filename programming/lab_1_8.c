#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void input_file_F(int n){
int i,k;
double p,a;
FILE * f;
f=fopen("f.dat","wb");
for(i=1;i<=n;i++){
    p=1;
    a=0;
    for(k=1;k<=i;k++){
        a=pow(2,k+1)-log(k);
        p=p*a;
    }
    fwrite(&p,sizeof(p),1,f);
}
fclose(f);
}

void input_file_G(){
double a;
FILE * f;
f=fopen("f.dat","rb");
FILE * g;
g=fopen("g.dat","wb");
while(fread(&a,sizeof(a),1,f)){
    while(a<=1000){
    fread(&a,sizeof(a),1,f);
    fwrite(&a,sizeof(a),1,g);
    }
}
fclose(f);
fclose(g);
}

int main()
{
    printf("Please input N:");
    int n;
    scanf("%d",&n);
    double x;
    input_file_F(n);
    FILE *f;
    f=fopen("f.dat","rb");
    while(fread(&x,sizeof(x),1,f)){
        printf("%lf  ",x);
    }
    fclose(f);
    printf("\n\n\nFile G is:\n");
    input_file_G();
    FILE *g;
    g=fopen("g.dat","rb");
    while(fread(&x,sizeof(x),1,g)){
        printf("%lf  ",x);
    }
    fclose(g);
    printf("\n\n");
    return 0;
}
