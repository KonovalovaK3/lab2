#ifndef LAB2VAR27_TEACHER_H
#define LAB2VAR27_TEACHER_H

#include <string>
#include <iostream>

using namespace std;

class Teacher {
    string fio;
    double salary;
    int experience;

public:
    Teacher();

    Teacher(string fio, double salary, int experience);

    friend ostream& operator<<(ostream& os, const Teacher& p);

    friend istream& operator>>(istream& os, Teacher& p);
};

#endif
