#include <iostream>
#include "Queue.h"
#include "Complex.h"
#include "Student.h"
#include "Teacher.h"
#include "Matrix.h"

using namespace std;

template<typename T>
void inputQueue(Queue<T>& q) {
    int n;
    cout << "Count elements" << endl;
    cin >> n;
    cout << "Input queue" << endl;
    for (int i = 0; i < n; ++i) {
        T t;
        cin >> t;
        q.Append(t);
    }
}

template<typename T>
void QueueMenu(const Queue<T>& q) {
    cout << q << endl;
    cout << "1 - Concat" << endl;
    cout << "2 - Sub Queue" << endl;
    int c;
    cin >> c;
    switch (c) {
        case 1: {
            Queue<T> q2;
            inputQueue(q2);
            Queue<T>* q3 = q.Concat(q2);
            cout << "Result:" << endl;
            cout << *q3 << endl;
            delete q3;
            break;
        }
        case 2: {
            int s, e;
            cout << "Input start index" << endl;
            cin >> s;
            cout << "Input end index" << endl;
            cin >> e;
            Queue<T>* q3 = q.GetSubQueue(s, e);
            cout << *q3 << endl;
            delete q3;
            break;
        }
        default: {
            cout << "Error!" << endl;
            break;
        }
    }
}

template<typename T>
void MatrixMenu(const Matrix<T>& m) {
    cout << m << endl;
    cout << " 1 - Addition" << endl;
    cout << " 2 - Multiplication " << endl;
    int c;
    cin >> c;
    switch (c) {
        case 1: {
            int row, col;
            cout << "Input the number of rows" << endl;
            cin >> row;
            try {
                cout << "Input the number of cols" << endl;
                cin >> col;
                Matrix<T> m2(row, col);
                cout << "Input the second matrix" << endl;
                cin >> m2;
                Matrix<T> res = m + m2;
                cout << res << endl;
            }
            catch (exception& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 2: {
            T alpha;
            cout << "Input the coefficient alpha" << endl;
            cin >> alpha;
            Matrix<T> m3 = m * alpha;
            cout << m3 << endl;
            break;
        }
        default: {
            cout << "Error!" << endl;
            break;
        }
    }
}

int main() {
    while (true) {
        cout << "0 - Exit" << endl;
        cout << "1 - Queue" << endl;
        cout << "2 - Matrix" << endl;
        int k;
        cin >> k;
        if (k == 1) {
            cout << "1 - Complex" << endl;
            cout << "2 - Student" << endl;
            cout << "3 - Teacher" << endl;
            int c;
            cin >> c;
            switch (c) {
                case 1: {
                    Queue<Complex> q;
                    inputQueue(q);
                    QueueMenu(q);
                    break;
                }
                case 2: {
                    Queue<Student> q;
                    inputQueue(q);
                    QueueMenu(q);
                    break;
                }
                case 3: {
                    Queue<Teacher> q;
                    inputQueue(q);
                    QueueMenu(q);
                    break;
                }
                default: {
                    cout << "Error!" << endl;
                    break;
                }
            }
        } else if (k == 2) {
            cout << "1 - Integer" << endl;
            cout << "2 - Float" << endl;
            cout << "3 - Complex" << endl;
            int t;
            cin >> t;
            try {
                if (t == 1) {
                    cout << "Input rows and cols" << endl;
                    int rows, cols;
                    cin >> rows >> cols;
                    Matrix<int> m(rows, cols);
                    cout << "Input matrix" << endl;
                    cin >> m;
                    MatrixMenu(m);
                } else if (t == 2) {
                    cout << "Input rows and cols" << endl;
                    int rows, cols;
                    cin >> rows >> cols;
                    Matrix<float> m(rows, cols);
                    cout << "Input matrix" << endl;
                    cin >> m;
                    MatrixMenu(m);
                } else if (t == 3) {
                    cout << "Input rows and cols" << endl;
                    int rows, cols;
                    cin >> rows >> cols;
                    Matrix<Complex> m(rows, cols);
                    cout << "Input matrix" << endl;
                    cin >> m;
                    MatrixMenu(m);
                } else {
                    cout << "Error!" << endl;
                }
            } catch (exception& e) {
                cout << e.what() << endl;
            }
        } else if (k == 0) {
            return 0;
        } else {
            cout << "Error! Try again!" << endl;
        }
    }
}
