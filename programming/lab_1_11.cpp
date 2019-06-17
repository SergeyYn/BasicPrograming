#include <iostream>
#include "Class_lab.h"

using namespace std;

int main()
{
    char name[20]="Yershykhin";

    int date,note;

    exam Yershykhin(name,13,95);

    exam *YRS;
    YRS = new exam(name, 10, 90);
    cout << YRS->getStudentName() << endl;
    delete YRS;

    exam Petrov = Yershykhin;
    cout << Petrov.getStudentName()<< endl;
    cout << Petrov.getDate()<< endl;
    cout << Petrov.getNote()<< endl;

    cout << "enter name of Petrov:" << endl;
	cin >> name;
	cout << "enter date of exam of Petrov:" << endl;
	cin >> date;
	cout << "enter note of Petrov:" << endl;
	cin >> note;
	Petrov.setAllParameters(name, date, note);
	Petrov.printEverything();

	exam students_list[5];
	int (exam::*pointer)();
	pointer = &exam::getDate;
	cout << (students_list[0].*pointer)() << endl;

	exam *Ivanov = new exam;
	cout << (Ivanov->*pointer)()<< endl;

    return 0;
}
