#include "Complex.h"

Complex::Complex() {
    this->re = 0;
    this->im = 0;
}

Complex::Complex(double re, double im) {
    this->re = re;
    this->im = im;
}

std::ostream& operator<<(ostream& os, const Complex& c) {
    os << "(" << c.re << ";" << c.im << ")";
    return os;
}

std::istream& operator>>(istream& is, Complex& c) {
    is >> c.re >> c.im;
    return is;
}
