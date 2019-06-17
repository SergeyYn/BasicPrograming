#include "Class_lab.h"
#include <iostream>
#include <cstring>
using namespace std;

exam::exam(char*NAME, int DATE, int NOTE){
    strcpy(student_name, NAME);
    date = DATE;
    note = NOTE;
    cout<< "\nConstructor with parameters for object " << this << endl;
}

exam::exam(){
	char s[] = "Empty";
	strcpy(student_name,s);
	date = 0;
	note = 0;
	cout << "\nConstructor without parameters for object " << this << endl;
}

exam::exam(const exam& Example){
    strcpy(this->student_name,Example.student_name);
	this->date = Example.date;
	this->note = Example.note;
	cout << "\nConstructor of copying for object " << this << endl;

}
exam::~exam(){
	cout << "\nDestructor for object " << this << endl;
}

char* exam::getStudentName(){
	return student_name;
}

int exam::getDate(){
	return date;
}

int exam::getNote(){
	return note;
}

void exam::setAllParameters(char* Name, int Date, int Note){
	strcpy(student_name, Name);
	date = Date;
	note = Note;
}

void exam::setStudentName(char *Name){
	strcpy(student_name, Name);
}

void exam::setDate(int Date){
	date = Date;
}

void exam::setNote(int Note){
	note = Note;
}
void exam::printEverything(){
	cout << "\nStudent's name: " << student_name << "\nDate of exam: " << date << "\nNote: " << note << endl;
}




