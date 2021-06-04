#ifndef LAB2VAR27_COMPLEX_H
#define LAB2VAR27_COMPLEX_H

#include <iostream>

using namespace std;

class Complex {
    double re;
    double im;

public:
    Complex();

    Complex(double re, double im);

    Complex operator+(const Complex& other) {
        return Complex(this->re + other.re, this->im + other.im);
    }

    Complex operator*(const Complex& other) {
        return Complex(this->re * other.re - this->im * other.im, this->re * other.im + this->im * other.re);
    }

    friend std::ostream& operator<<(ostream& os, const Complex& c);

    friend std::istream& operator>>(istream& is, Complex& c);
};


#endif
