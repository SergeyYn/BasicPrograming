#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,m,i,j,temp1,temp2;
    printf("Insert size of array:");
    scanf("%d",&n);
    printf("Insert number of shifts:");
    scanf("%d",&m);
    printf("\n");
    FILE* file;
    file = fopen("file.dat","wb");
    for(i=0;i<n;i++)
    {
        fwrite(&i,sizeof(i),1,file);
        printf("%d ",i);
    }
    printf("\n");
    fclose(file);
    for(j=0;j<m;j++){
        file=fopen("file.dat","r+b");
        fseek(file,-sizeof(temp2),SEEK_END);
        fread(&temp2,sizeof(temp2),1,file);
        for(i=0;i<n-1;i++){
            fseek(file,(n-i-2)*sizeof(temp1),SEEK_SET);
            fread(&temp1,sizeof(temp1),1,file);
            fseek(file,(n-i-1)*sizeof(temp1),SEEK_SET);
            fwrite(&temp1,sizeof(temp1),1,file);
        }
        fseek(file,0,SEEK_SET);
        fwrite(&temp2,sizeof(temp2),1,file);
        fclose(file);
    }
    printf("\n\n");
    file=fopen("file.dat","rb");
    while(fread(&temp1,sizeof(temp1),1,file))
    {
        printf("%d ",temp1);
    }

    fclose(file);
    printf("\n\n");
    fclose(file);
    printf("\n\n");


    file = fopen("file.dat","rb");
    fseek(file,0,SEEK_END);
    fread(&temp1,sizeof(temp1),1,file);
    printf("%d",temp1);
    fclose(file);




    return 0;
}
