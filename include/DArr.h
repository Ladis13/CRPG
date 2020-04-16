#ifndef DARR_H
#define DARR_H

template <typename T>
class DArr {
private:
    unsigned capInit;
    unsigned capacity;
    unsigned nbElem;
    T* *arr;

    void expand();
    void initialize(unsigned from = 0);

public:
    DArr(unsigned size = 10);
    DArr(const DArr& arr);
    ~DArr();

    T& operator[] (const unsigned index);
    void operator= (const DArr& arr);

    unsigned size();
    unsigned cap();
    void push(const T element);
    void remove(const unsigned index, bool ordered = false);

};

template <typename T>
DArr<T>::DArr(unsigned size)
{
    this->capacity = size;
    this->capInit = this->capacity;
    this->nbElem = 0;

    this->arr = new T*[this->capacity];

    initialize();
}

template <typename T>
DArr<T>::DArr(const DArr& arr)
{
    this->capacity = arr.capacity;
    this->capInit = arr.capInit;
    this->nbElem = arr.nbElem;

    this->arr = new T*[this->nbElem];

    for (size_t i = 0; i < this->nbElem; i++) {
        this->arr[i] = new T(*arr.arr[i]);
    }

    initialize(this->nbElem);
}

template <typename T>
DArr<T>::~DArr()
{
    for (size_t i = 0; i < this->nbElem; i++) {
        delete this->arr[i];
    }

    delete[] this->arr;
}

template <typename T>
T& DArr<T>::operator[] (const unsigned index)
{
    if(index < 0 || index >= this->nbElem)
        throw("Error : Out of bounds operator[].");

    return *this->arr[index];
}

template <typename T>
void DArr<T>::operator= (const DArr& arr)
{
    for (size_t i = 0; i < this->nbElem; i++) {
        delete this->arr[i];
    }
    delete[] this->arr;

    this->capacity = arr.capacity;
    this->capInit = arr.capInit;
    this->nbElem = arr.nbElem;

    this->arr = new T*[this->nbElem];

    for (size_t i = 0; i < this->nbElem; i++) {
        this->arr[i] = new T(*arr.arr[i]);
    }

    initialize(this->nbElem);
}

template <typename T>
void DArr<T>::expand()
{
    this->capacity += this->capInit;

    T* *tmp = new T*[this->capacity];

    for (size_t i = 0; i < this->nbElem; i++) {
        tmp[i] = this->arr[i];
    }

    delete[] this->arr;
    this->arr = tmp;
    initialize(this->nbElem);
}

template <typename T>
void DArr<T>::initialize(unsigned from)
{
    for (size_t i = from; i < this->capacity; i++) {
        this->arr[i] = nullptr;
    }
}

template <typename T>
unsigned DArr<T>::size()
{
    return this->nbElem;
}

template <typename T>
unsigned DArr<T>::cap()
{
    return this->capacity;
}

template <typename T>
void DArr<T>::push(const T element)
{
    if(this->nbElem >= this->capacity)
        expand();

    this->arr[this->nbElem++] = new T(element);
}

template <typename T>
void DArr<T>::remove(const unsigned index, bool ordered)
{
    if(index < 0 || index >= this->nbElem)
        throw("Error : Out of bounds remove.");

    if (ordered) {
        delete this->arr[index];

        for (size_t i = index; i < this->nbElem - 1; i++) {
            this->arr[i] = this->arr[i + 1];
        }

        this->arr[--this->nbElem] = nullptr;

    } else {
        delete this->arr[index];
        this->arr[index] = this->arr[this->nbElem - 1];
        this->arr[--this->nbElem] = nullptr;
    }
}

#endif
