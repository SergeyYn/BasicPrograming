#include <stdio.h>
#include <stdlib.h>


typedef struct elem_t{
    double inf;
    struct elem_t *link;
}list;

list *BegQ=NULL, *EndQ=NULL;
void add_elem(int value){
    list *p = (list*)malloc(sizeof(list));
    p->inf = value;
    p->link = NULL;
    if(EndQ==NULL){
        BegQ=p;
    }
    else{
        EndQ->link=p;
    }
    EndQ=p;
}

void printlist(){
    list *p = BegQ;
    while(p!=NULL){
        printf("%lf  ", p->inf);
        p = p->link;
    }
}

void bubblesort(list *ptr){
    list * p = NULL;
    int flag = 1;
    if (ptr!= NULL){
        while(flag==1){
            flag=0;
            while (ptr->link != NULL){
                p = ptr->link;
                do{
                    if (p->inf > ptr->inf){
                        double tmp = p->inf;
                        p->inf = ptr->inf;
                        ptr->inf = tmp;
                        flag = 1;
                    }
                    p = p->link;
                }while (p != NULL);
                ptr = ptr->link;
            }
        }
    }
}

void destroy_list(){
    list *p;
    p = BegQ;
    BegQ = p->link;
    if(BegQ==NULL){
        EndQ==NULL;
    }
    free(p);
}

int main()
{
    int n,i;
    double value;
    printf("Input N:");
    scanf("%d",&n);
    for(i = 1; i<=n; i++){
        value = rand()%n;
        add_elem(value);
    }
    printf("\nDefault List\n\n");
    printlist();
    bubblesort(BegQ);
    printf("\n\nSorted List\n\n");
    printlist();
    printf("\n\n");
    if(BegQ!=NULL){
        for(i=0;i<n;i++){
            destroy_list();
        }
    }
    return 0;
}
