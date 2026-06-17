#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>
#include <initializer_list>

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
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);

    Vector(std::initializer_list<T> init);

    void pushBack(T val);
    void popBack();
    void insert(size_t index, T val);

    void remove(size_t index);

    T& operator[](size_t index);
    T& at(size_t index);

    T& front();
    T& back();

    bool empty() const;
    size_t size() const;
    size_t capacity() const;

    void display() const;
};

#include "../src/Vector.cpp"

#endif