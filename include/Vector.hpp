#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>
#include <initializer_list>

template <typename T>
class Vector;

template <typename T>
class VectorIterator {
public:
    using value_type = T;
    using pointer = T*;
    using reference = T&;

private:
    T* ptr;

public:
    VectorIterator(T* p = nullptr) : ptr(p) {}

    reference operator*() const {
        return *ptr;
    }

    pointer operator->() const {
        return ptr;
    }

    VectorIterator& operator++() {
        ++ptr;
        return *this;
    }

    VectorIterator operator++(int) {
        VectorIterator tmp = *this;
        ++ptr;
        return tmp;
    }

    VectorIterator& operator--() {
        --ptr;
        return *this;
    }

    VectorIterator operator--(int) {
        VectorIterator tmp = *this;
        --ptr;
        return tmp;
    }

    bool operator==(const VectorIterator& other) const {
        return ptr == other.ptr;
    }

    bool operator!=(const VectorIterator& other) const {
        return ptr != other.ptr;
    }

    VectorIterator operator+(ptrdiff_t n) const {
        return VectorIterator(ptr + n);
    }

    VectorIterator operator-(ptrdiff_t n) const {
        return VectorIterator(ptr - n);
    }
};

template <typename T>
class Vector {
private:
    T* arr;
    size_t currentSize;
    size_t currentCapacity;

    void resize();

public:
    using iterator = VectorIterator<T>;
    using const_iterator = VectorIterator<const T>;

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

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    void display() const;

    friend class VectorIterator<T>;
};

#include "../src/Vector.cpp"

#endif