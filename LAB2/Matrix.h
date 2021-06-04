#ifndef LAB2VAR27_MATRIX_H
#define LAB2VAR27_MATRIX_H

#include "ArraySequence.h"
#include <iostream>

using namespace std;

template<typename T>
class Matrix {
private:
    ArraySequence<ArraySequence<T>> matr;

public:
    Matrix(int rows, int cols) {
        if (rows <= 0 || cols <= 0)
            throw out_of_range("Incorrect size");
        for (int i = 0; i < rows; i++) {
            ArraySequence<T> row;
            for (int j = 0; j < cols; j++) {
                row.Append(T());
            }
            this->matr.Append(row);
        }
    }

    friend ostream& operator<<(ostream& o, const Matrix<T>& matri) {
        for (int i = 0; i < matri.matr.GetLength(); i++) {
            for (int j = 0; j < matri.matr[i].GetLength(); j++) {
                o << matri.matr[i][j] << " ";
            }
            o << std::endl;
        }
        return o;
    }

    friend istream& operator>>(istream& is, Matrix<T>& matri) {
        for (int i = 0; i < matri.matr.GetLength(); i++) {
            for (int j = 0; j < matri.matr[i].GetLength(); j++) {
                is >> matri.matr[i][j];
            }
        }
        return is;
    }

    int GetRows() const {
        return this->matr.GetLength();
    }

    int GetCols() const {
        return this->matr[0].GetLength();
    }

    Matrix<T> operator+(const Matrix<T>& other) const {
        if (this->GetRows() != other.GetRows() || this->GetCols() != other.GetCols())
            throw out_of_range("Incorrect size");
        Matrix<T> newMatr(this->GetRows(), this->GetCols());
        for (int i = 0; i < this->GetRows(); ++i) {
            for (int j = 0; j < this->GetCols(); ++j) {
                newMatr.matr[i][j] = this->matr[i][j] + other.matr[i][j];
            }
        }
        return newMatr;
    }

    Matrix<T> operator*(const T& val) const {
        Matrix<T> newMatr(this->GetRows(), this->GetCols());
        for (int i = 0; i < this->GetRows(); ++i) {
            for (int j = 0; j < this->GetCols(); ++j) {
                newMatr.matr[i][j] = this->matr[i][j] * val;
            }
        }
        return newMatr;
    }

    friend Matrix<T> operator*(const T& val, const Matrix<T>& m) {
        return m * val;
    }
};

#endif