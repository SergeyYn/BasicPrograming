#ifndef CLASS_LAB_H_INCLUDED
#define CLASS_LAB_H_INCLUDED

const int name_length = 50;
class exam{
    private:
        char student_name[name_length];
        int date;
        int note;

    public:
        exam();
        exam(char*,int,int);
        exam(const exam&);
        ~exam();
        char* getStudentName();
        int getDate();
        int getNote();
        void setAllParameters(char*, int, int);
        void setStudentName(char*);
        void setDate(int);
        void setNote(int);
        void printEverything();
};

#endif // CLASS_LAB_H_INCLUDED
