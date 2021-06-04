#include "Teacher.h"


Teacher::Teacher() {
    this->fio = "";
    this->experience = 0;
    this->salary = 0;
}

Teacher::Teacher(string fio, double salary, int experience) {
    this->fio = fio;
    this->salary = salary;
    this->experience = experience;
}

ostream& operator<<(ostream& os, const Teacher& p) {
    os << p.fio << ";" << p.experience << ";" << p.salary;
    return os;
}

istream& operator>>(istream& is, Teacher& p) {
    is >> p.fio >> p.experience >> p.salary;
    return is;
}
