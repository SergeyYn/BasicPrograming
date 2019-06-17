#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct student{
    char name[20];
    char surname[20];
    int day;
    int month;
    int year;
    int SDA;
    int Programming;
    int Mathanalysis;
    int Lin_algebra;
};
void input_students(const int n, struct student *students){
int i;
FILE *file;
file=fopen("vvid.txt","r");
for(i=0; i<=n-1; i++)
    {
        fscanf(file,"%s",&students[i].name);
        fscanf(file,"%s",&students[i].surname);
        fscanf(file,"%d",&students[i].day);
        fscanf(file,"%d",&students[i].month);
        fscanf(file,"%d",&students[i].year);
        fscanf(file,"%d",&students[i].Mathanalysis);
        fscanf(file,"%d",&students[i].Lin_algebra);
        fscanf(file,"%d",&students[i].SDA);
        fscanf(file,"%d",&students[i].Programming);
    }
fclose(file);
}
void notes_swap(const int n,int i, int j, struct student *students){
int temp;
temp=students[i].Programming;
students[i].Programming = students[j].Programming;
students[j].Programming = temp;
temp=students[i].SDA;
students[i].SDA = students[j].SDA;
students[j].SDA = temp;
temp=students[i].Lin_algebra;
students[i].Lin_algebra = students[j].Lin_algebra;
students[j].Lin_algebra = temp;
temp=students[i].Mathanalysis;
students[i].Mathanalysis = students[j].Mathanalysis;
students[j].Mathanalysis = temp;
}
void names_swap(const int n,int i, int j, struct student *students){
char temp_c[20];
strncpy(temp_c, students[j].name, 20);
strncpy(students[j].name, students[i].name, 20);
strncpy(students[i].name, temp_c, 20);
strncpy(temp_c, students[j].surname, 20);
strncpy(students[j].surname, students[i].surname, 20);
strncpy(students[i].surname, temp_c, 20);
}
void students_list(const int n, struct student *students){
int i, j, temp;
for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
        if(students[i].year > students[j].year){
            temp=students[i].year;
            students[i].year = students[j].year;
            students[j].year = temp;
            temp=students[i].month;
            students[i].month = students[j].month;
            students[j].month = temp;
            names_swap(n, i, j, students);
            notes_swap(n, i, j, students);
        }
        else if(students[i].year == students[j].year){
                if(students[i].month > students[j].month){
                    temp=students[i].month;
                    students[i].month = students[j].month;
                    students[j].month = temp;
                    temp=students[i].day;
                    students[i].day = students[j].day;
                    students[j].day = temp;
                    names_swap(n, i, j, students);
                    notes_swap(n, i, j,students);
                }
                else if(students[i].month == students[j].month){
                        if(students[i].day > students[j].day){
                            temp=students[i].day;
                            students[i].day = students[j].day;
                            students[j].day = temp;
                            names_swap(n, i, j, students);
                            notes_swap(n,i, j, students);
                        }
                }
        }

    }
}
}
void output_students(const int n, struct student *students){
int i;
printf(" __________________________________________________________________________\n");
printf("|ФИО                            |Дата рождения   |Оценки                   |\n");
printf("|_______________________________|________________|_________________________|\n");
printf("|Фамилия        |Имя            |Дeнь|Мeсяц| Год |Матанализ|Линал|СДА|Прога|\n");
printf("|_______________|_______________|____|_____|_____|_________|_____|___|_____|\n");
for(i=0; i<=n-1; i++)
    {
    printf("|%15s",students[i].name);
    printf("|%15s",students[i].surname);
    printf("|%4d",students[i].day);
    printf("|%5d",students[i].month);
    printf("|%5d",students[i].year);
    printf("|%9d",students[i].Mathanalysis);
    printf("|%5d",students[i].Lin_algebra);
    printf("|%3d",students[i].SDA);
    printf("|%5d|\n",students[i].Programming);
    }
printf("|_______________|_______________|____|_____|_____|_________|_____|___|_____|\n");

}
int main(){

    setlocale(LC_CTYPE,"Russian");
    const int n = 5;
    struct student students[n];
    input_students(n,students);
    printf("Изначальная таблица:\n");
    output_students(n,students);
    printf("\nИзмененная таблица(отсортированная по возрасту):\n");
    students_list(n, students);
    output_students(n,students);
    return 0;
}
