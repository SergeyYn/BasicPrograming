#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>

void gotoxy(int x,int y)
{
    HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {x,y};
    SetConsoleCursorPosition(StdOut, coord);
}

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

int main()
{
    system("COLOR b");
    printf(" Welcome to the application!  Press any key to start!\n");
    getch();
    hidecursor();
    int m=80,n=24,i,j,a=0;
    while ((1+a<n-a)&&(1+a<m-a))
    {
        for (i=1+a;i<=m-a-1;i++)
        {
            gotoxy(i,n-a);
            usleep(8000);
            printf("*");
        }

        for (i=n-a;i>=1+a;i--)
        {
            gotoxy(m-a,i);
            usleep(18000);
            printf("*");
        }
        for (i=m-a-1;i>=1+a;i--)
        {
            gotoxy(i,1+a);
            usleep(8000);
            printf("*");
        }
        for (i=1+a;i<=n-a-1;i++)
        {
            gotoxy(1+a,i);
            usleep(18000);
            printf("*");
        }
    a++;
    }


    gotoxy(1,n+1);
    getch();

    return 0;

}
