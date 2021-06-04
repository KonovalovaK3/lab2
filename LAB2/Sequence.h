#ifndef LAB2VAR27_SEQUENCE_H
#define LAB2VAR27_SEQUENCE_H

template<typename T>
class Sequence {

public:
    //Decomposition
    virtual T& GetFirst() = 0;

    virtual T& GetLast() = 0;

    virtual T& operator[](int index) const = 0;

    virtual Sequence<T>* GetSubSequence(int start_index, int end_index) = 0;

    virtual int GetLength() const = 0;

    //Operations
    virtual void Append(const T& item) = 0;

    virtual void Prepend(const T& item) = 0;

    virtual void InsertAt(const T& item, int index) = 0;

    virtual Sequence<T>* Concat(const Sequence<T>& Sequence) = 0;

    virtual void RemoveFirst() = 0;

    virtual void RemoveLast() = 0;

    virtual void Remove(int index) = 0;

    virtual void Print() = 0;

};


#endif