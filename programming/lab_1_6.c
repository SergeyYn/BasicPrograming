#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


char* input_text(char *nabir){
    fgets(nabir, 255, stdin);
    return nabir;
}

char* change_words(char *nabir, int temp){
    int i=1;
    int ch;
    while(i<=temp-1){
        if(nabir[i-1]=='+'){
            do{
                ch=nabir[i];
                if(ch>=48&&ch<=57){
                    nabir[i]='-';
                    i++;
                }
                else{
                    i++;
                }
            }while(ch!=' ');
        }
        else{
            i++;
        }
    }
return nabir;
}

int main()
{
char nabir[255] = "";
system("COLOR f");
printf("Please input your text: ");
input_text(nabir);
printf("\nYour text is:\n\n");
printf("%s\n", nabir);
int temp = strlen(nabir);
printf("\nModified text (with all numbers after 1'st '+' replaced by '-' in each word) is:\n\n");
printf("%s\n", change_words(nabir, temp));

return 0;
}
