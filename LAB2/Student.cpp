#include "Student.h"

Student::Student() {
    this->fio = "";
    this->age = 0;
    this->grade = 0;
}

Student::Student(string fio, int age, int grade) {
    this->fio = fio;
    this->age = age;
    this->grade = grade;
}

std::ostream& operator<<(std::ostream& os, Student& c) {
    os << c.fio << ";" << c.age << ";" << c.grade;
    return os;
}

std::istream& operator>>(istream& is, Student& c) {
    is >> c.fio >> c.age >> c.grade;
    return is;
}