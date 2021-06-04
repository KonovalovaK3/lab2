#ifndef LAB2VAR27_STUDENT_H
#define LAB2VAR27_STUDENT_H

#include <string>
#include <iostream>

using namespace std;

class Student {
    string fio;
    int age;
    int grade;

public:
    Student();

    Student(string fio, int age, int grade);

    friend std::ostream& operator<<(ostream& os, Student& c);

    friend std::istream& operator>>(istream& is, Student& c);
};


#endif
