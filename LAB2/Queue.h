#ifndef LAB2VAR27_QUEUE_H
#define LAB2VAR27_QUEUE_H

#include "Sequence.h"
#include "ListSequence.h"
#include <iostream>

using namespace std;

template<typename T>
class Queue {
private:
    Sequence<T>* s;
public:
    Queue() {
        this->s = new ListSequence<T>();
    }

    void Append(const T item) {
        this->s->Append(item);
    }

    T Take() {
        T res = this->s->GetFirst();
        this->s->RemoveFirst();
        return res;
    }

    void Print() {
        this->s->Print();
    }

    int GetSize() const {
        return this->s->GetLength();
    }

    T& operator[](int i) const {
        return (*this->s)[i];
    }

    ~Queue() {
        delete this->s;
    }

    Queue<T>* Concat(const Queue<T>& other) const {
        Sequence<T>* res = this->s->Concat(*other.s);
        Queue<T>* q = new Queue<T>();
        q->s = res;
        return q;
    }

    Queue<T>* GetSubQueue(int start, int end) const {
        Sequence<T>* res = this->s->GetSubSequence(start, end);
        Queue<T>* q = new Queue<T>();
        q->s = res;
        return q;
    }

    friend ostream& operator<<(ostream& os, const Queue<T>& q) {
        for (int i = 0; i < q.GetSize(); ++i) {
            os << q[i] << " ";
        }
        return os;
    }
};

#endif