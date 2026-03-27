#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class Vector {
private:
    T* arr;
    size_t currentSize;
    size_t currentCapacity;

    void resize();

public:
    Vector();
    ~Vector();

    Vector(std::initializer_list<T> init);

    void pushBack(T val);
    void popBack();

    T& operator[](size_t index);
    T& at(size_t index);

    T& front();
    T& back();

    bool empty() const;
    size_t size() const;

    void display() const;
};

#include "../src/Vector.cpp"

#endif