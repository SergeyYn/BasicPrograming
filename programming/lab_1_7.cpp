#include <string.h>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

using namespace std;

HANDLE hConsole;    //HANDLE hStdout
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);  // получение дескриптора устройства стандартного вывода
void gotoxy(int X, int Y)
{
    COORD coord = { X, Y };
    SetConsoleCursorPosition(hStdOut, coord);  //функция премещения курсора по Х и У
}
void SetColor(int text, int background)
{
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text)); //задаём атрибуты для шрифта и цвета символов в консоли
}
short regim;
void frame (int x1, int y1, int x2, int y2) //maluje ramku
{
    int i;
    gotoxy(x1,y1);
    cout << '\311';
    for (i=(x1+1); i<=(x2-1); i++) cout <<'\315';
    cout << '\273';
    for (i=(y1+1); i<=(y2-1); i++)
    {
        gotoxy(x1,i);
        cout << '\272';
        gotoxy(x2,i);
        cout << '\272';
    }
    gotoxy(x1, y2);
    cout << '\310';
    for (i=(x1+1); i<=(x2-1);i++) cout << '\315';
    cout << '\274';
 } //frame
void zastavka ()
{
    system ("cls");
    frame (10,5,70,18);
    gotoxy(30,8);  cout << "Laboratorna robota #7"<< endl;
    gotoxy(33, 10); cout << "z programuvannja"<< endl;
    gotoxy(35, 12); cout << "variant 21" << endl;
    gotoxy(35, 17); cout << "Kyiv 2017"<< endl;
    _getch();
    system ("cls");
} // zastavka

void help_box ()
{
 system ("cls");
 frame (10,5,70,18);
 gotoxy(20,8);  cout << "To move letter use arrows"<< endl;
 gotoxy(20, 10); cout << "To resize letter press + and -"<< endl;
 gotoxy(20, 12); cout << "To change line color press 1 - 9" << endl;
 gotoxy(20, 14); cout << "To change  background color press TAB then 1 - 9 "<< endl;
 _getch();
system ("cls");
} //help_box

 void graphicin2d()
 {
    int x, y, bsize, linecolor, bgcolor, width;
    linecolor = 12;
    bgcolor = 11;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    x = 40; y = 40; bsize = 100; width = 30;
    setcolor(linecolor);
    setbkcolor(BLACK);
    cleardevice();
    line(x,y,x,y+bsize);
    arc(x+width,y+bsize,175,275,width);
    line(x+width,y+bsize+width,x+bsize+width,y+bsize+width);
    line(x+bsize+width,y+bsize+width,x+bsize+width,y+2*bsize+width);
    line(x+bsize+width,y+2*bsize+width,x+bsize+2*width,y+2*bsize+width);
    line(x+bsize+2*width,y+2*bsize+width,x+bsize+2*width,y);
    line(x+bsize+2*width,y,x+bsize+width,y);
    line(x+bsize+width,y,x+bsize+width,y+bsize);
    line(x+bsize+width,y+bsize,x+2*width,y+bsize);
    arc(x+2*width,y+bsize-width,175,275,width);
    line(x+width,y+bsize-width, x+width,y);
    line(x+width,y,x,y);
    setfillstyle(SOLID_FILL,bgcolor);
    floodfill(x+1,y+1,linecolor);
    delay(50);
    char ch;
    while (ch != 27)
    {
        ch = _getch();
        switch (ch)
        {
            case 80 : y=y+5;break;
            case 72 : y=y-5;break;
            case 77 : x=x+5;break;
            case 75 : x=x-5;break;
            case '+' : width=width+10;bsize=bsize+10;break;
            case '-' : if (width-10>=30) {width=width-10;bsize=bsize-10;} else delay(50);break;
            case 9 : ch = _getch();
                        switch (ch)
                        {
                            case '1' : linecolor = RED; break;
                            case '2' : linecolor = YELLOW; break;
                            case '3' : linecolor = GREEN; break;
                            case '4' : linecolor = BLUE; break;
                            case '5' : linecolor = WHITE; break;
                            case '6' : linecolor = BROWN; break;
                            case '7' : linecolor = CYAN; break;
                            case '8' : linecolor = MAGENTA; break;
                            case '9' : linecolor = LIGHTBLUE; break;
                        }
                            case '1' : bgcolor = RED; break;
                            case '2' : bgcolor = YELLOW; break;
                            case '3' : bgcolor = GREEN; break;
                            case '4' : bgcolor = BLUE; break;
 case '5' : bgcolor = WHITE; break;
                            case '6' : bgcolor = BROWN; break;
                            case '7' : bgcolor = CYAN; break;
                            case '8' : bgcolor = MAGENTA; break;
                            case '9' : bgcolor = LIGHTBLUE; break;
        }
    delay(50);
    cleardevice();
    setcolor(linecolor);
    line(x,y,x,y+bsize);
    arc(x+width,y+bsize,175,275,width);
    line(x+width,y+bsize+width,x+bsize+width,y+bsize+width);
    line(x+bsize+width,y+bsize+width,x+bsize+width,y+2*bsize+width);
    line(x+bsize+width,y+2*bsize+width,x+bsize+2*width,y+2*bsize+width);
    line(x+bsize+2*width,y+2*bsize+width,x+bsize+2*width,y);
    line(x+bsize+2*width,y,x+bsize+width,y);
    line(x+bsize+width,y,x+bsize+width,y+bsize);
    line(x+bsize+width,y+bsize,x+2*width,y+bsize);
    arc(x+2*width,y+bsize-width,175,275,width);
    line(x+width,y+bsize-width, x+width,y);
    line(x+width,y,x,y);
    setfillstyle(SOLID_FILL,bgcolor);
    floodfill(x+1,y+1,linecolor);
    }
    closegraph();
 } // 2 d graphica

  void graphicin3d()
 {
    int x, y, bsize, linecolor, bgcolor, width;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    linecolor = 9;
    bgcolor = 7;
    x = 40; y = 40; bsize = 100; width = 30;
    setcolor(linecolor);
    setbkcolor(BLACK);
    cleardevice();
    line(x+bsize+3*width,y+2*bsize,x+bsize+3*width,y-width);
    line(x+bsize+3*width,y-width,x+bsize+2*width,y-width);
    line(x+bsize+width,y+bsize-width,x+3*width,y+bsize-width);
    arc(x+3*width,y+bsize-2*width,175,275,width);
    line(x+2*width,y+bsize-2*width, x+width+width,y-width);
    line(x+2*width,y-width,x+width,y-width);
    line(x,y,x+width,y-width);
    line(x+bsize+2*width,y+2*bsize+width,x+bsize+3*width,y+2*bsize);
    line(x+width+bsize,y,x+2*width+bsize,y-width);
    line(x+width,y,x+2*width,y-width);
    line(x+2*width+bsize,y,x+3*width+bsize,y-width);
    line(x,y,x,y+bsize);
    arc(x+width,y+bsize,175,275,width);
    line(x+width,y+bsize+width,x+bsize+width,y+bsize+width);
    line(x+bsize+width,y+bsize+width,x+bsize+width,y+2*bsize+width);
    line(x+bsize+width,y+2*bsize+width,x+bsize+2*width,y+2*bsize+width);
    line(x+bsize+2*width,y+2*bsize+width,x+bsize+2*width,y);
    line(x+bsize+2*width,y,x+bsize+width,y);
    line(x+bsize+width,y,x+bsize+width,y+bsize);
    line(x+bsize+width,y+bsize,x+2*width,y+bsize);
    arc(x+2*width,y+bsize-width,170,280,width);
    line(x+width,y+bsize-width, x+width,y);
    line(x+width,y,x,y);
    setfillstyle(SOLID_FILL,bgcolor);
    floodfill(x+1,y+1,linecolor);
    floodfill(x+width+1,y,linecolor);
    floodfill(x+2*width+bsize+1,y,linecolor);
    //floodfill(x+width,y-1,linecolor);
    //floodfill(x+2*width+bsize,y-1,linecolor);
    delay(50);
    char ch;
    while (ch != 27)
    {
        ch = _getch();
        switch (ch)
        {
            case 80 : y=y+5;break;
            case 72 : y=y-5;break;
            case 77 : x=x+5;break;
            case 75 : x=x-5;break;
            case '+' : width=width+10;bsize=bsize+10;break;
            case '-' : if (width-10>=30) {width=width-10;bsize=bsize-10;} else delay(50);break;
            case 9 : ch = _getch();
                        switch (ch)
                        {
                            case '1' : linecolor = RED; break;
                            case '2' : linecolor = YELLOW; break;
                            case '3' : linecolor = GREEN; break;
                            case '4' : linecolor = BLUE; break;
                            case '5' : linecolor = WHITE; break;
                            case '6' : linecolor = BROWN; break;
                            case '7' : linecolor = CYAN; break;
                            case '8' : linecolor = MAGENTA; break;
                            case '9' : linecolor = LIGHTBLUE; break;
                        }
                            case '1' : bgcolor = RED; break;
                            case '2' : bgcolor = YELLOW; break;
                            case '3' : bgcolor = GREEN; break;
 case '4' : bgcolor = BLUE; break;
                            case '5' : bgcolor = WHITE; break;
                            case '6' : bgcolor = BROWN; break;
                            case '7' : bgcolor = CYAN; break;
                            case '8' : bgcolor = MAGENTA; break;
                            case '9' : bgcolor = LIGHTBLUE; break;
        }
    delay(50);
    setcolor(linecolor);
    cleardevice();
    line(x+bsize+3*width,y+2*bsize,x+bsize+3*width,y-width);
    line(x+bsize+3*width,y-width,x+bsize+2*width,y-width);
    line(x+bsize+width,y+bsize-width,x+3*width,y+bsize-width);
    arc(x+3*width,y+bsize-2*width,175,275,width);
    line(x+2*width,y+bsize-2*width, x+width+width,y-width);
    line(x+2*width,y-width,x+width,y-width);
    line(x,y,x+width,y-width);
    line(x+bsize+2*width,y+2*bsize+width,x+bsize+3*width,y+2*bsize);
    line(x+width+bsize,y,x+2*width+bsize,y-width);
    line(x+width,y,x+2*width,y-width);
    line(x+2*width+bsize,y,x+3*width+bsize,y-width);
    line(x,y,x,y+bsize);
    arc(x+width,y+bsize,175,275,width);
    line(x+width,y+bsize+width,x+bsize+width,y+bsize+width);
    line(x+bsize+width,y+bsize+width,x+bsize+width,y+2*bsize+width);
    line(x+bsize+width,y+2*bsize+width,x+bsize+2*width,y+2*bsize+width);
    line(x+bsize+2*width,y+2*bsize+width,x+bsize+2*width,y);
    line(x+bsize+2*width,y,x+bsize+width,y);
    line(x+bsize+width,y,x+bsize+width,y+bsize);
    line(x+bsize+width,y+bsize,x+2*width,y+bsize);
    arc(x+2*width,y+bsize-width,170,280,width);
    line(x+width,y+bsize-width, x+width,y);
    line(x+width,y,x,y);
    setfillstyle(SOLID_FILL,bgcolor);
    floodfill(x+1,y+1,linecolor);
    floodfill(x+width+1,y,linecolor);
    floodfill(x+2*width+bsize+1,y,linecolor);
    //floodfill(x+width,y-1,linecolor);
    //floodfill(x+2*width+bsize,y-1,linecolor);
    delay(50);
    }
    closegraph();
 }// 3d graphica

int vert_menu (int k1, int k2, int kp)
{
    const int kilk=4; // Є?«мЄ?бвм Їг­Є?вў ¬Ґ­о
    typedef   char punkt[17] ;
    punkt m [kilk]={"1. 2D  ", "2. 3D ", "3. HELP BOX ", "4. Exit"};
    short   i, t;
    char ch;
    int flag; // bool
    flag=1;// true
    t=strlen (m[0]);
    for (i=1; i<kp; i++)
        if (strlen(m[i])>t) t=strlen (m[i]);
            frame (k1-1,k2 ,k1+t, k2+kp+1);
        for (i=0; i<kp;i++)
        {
            if (i==0) SetColor(0,7);
            else SetColor(7,0);
            gotoxy (k1,k2+i+1);
        cout <<(m[i]);
        }// for
    gotoxy(15,12);
    SetColor(7,0);
    cout << "Use arrow to navigate "<< endl;
    SetColor(7,0);
    i=0;
    ch=_getch();
    while (flag!=0)
    {
        if (ch=='\15') {flag=0; return i;}
        if (ch==80)
        {
            gotoxy(k1, k2+i+1);  SetColor(7,0);
            cout << m[i];
            i++;
            if (i==kp)
                {i=0;
                SetColor(7,0);
                gotoxy (k1,k2+i+1); SetColor(0,7);
                cout << m[i];
                        }// if
            gotoxy(k1, k2+i+1); SetColor(0,7);
            cout << m[i]; SetColor(7,0);
        }
        if ( ch==72)
        {
            gotoxy(k1,k2+i+1); SetColor(7,0);
            cout << m[i];
            i--;
            if (i<0)
            {
                i=kp-1;
                SetColor(7,0);
                gotoxy (k1,k2+i+1); SetColor(0,7);
                cout << m[i];
            }
                gotoxy(k1, k2+i+1);  SetColor(0,7);
                cout << m[i];    SetColor(7,0);
    } // case 110
        ch=_getch();
    }// while
    return i;
}// vert menu

 int main ()
{
    system ("cls");
    zastavka();
    while (1)
    {
        system ("cls");
        gotoxy(35,4); cout << "MAIN MENU";
        regim=vert_menu(32,5,4);
        switch (regim)
        {
            case 0: graphicin2d(); break;
            case 1: graphicin3d(); break;
            case 2: help_box(); break;
            case 3: { system ("cls");
            return 0; }
        } //switch
    } // while;
    return 0;
} // main
