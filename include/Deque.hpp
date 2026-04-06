#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Deque;

template <typename T>
class DequeIterator {
public:
    using value_type = T;

private:
    Deque<T>* deque;
    size_t index;

public:
    DequeIterator() : deque(nullptr), index(0) {}
    DequeIterator(Deque<T>* d, size_t i) : deque(d), index(i) {}

    T& operator*() const {
        return (*deque)[index];
    }

    T* operator->() const {
        return &((*deque)[index]);
    }

    DequeIterator& operator++() {
        ++index;
        return *this;
    }

    DequeIterator operator++(int) {
        DequeIterator tmp = *this;
        ++index;
        return tmp;
    }

    DequeIterator& operator--() {
        --index;
        return *this;
    }

    DequeIterator operator--(int) {
        DequeIterator tmp = *this;
        --index;
        return tmp;
    }

    bool operator==(const DequeIterator& other) const {
        return deque == other.deque && index == other.index;
    }

    bool operator!=(const DequeIterator& other) const {
        return !(*this == other);
    }

    friend class Deque<T>;
};

template <typename T>
class Deque {
private:
    T** map;
    size_t mapSize;
    size_t blockSize;

    size_t frontIndex;
    size_t backIndex;

    size_t frontBlock;
    size_t backBlock;
    size_t currentSize;

    void allocateBlock(size_t index);
    void reallocateMap();

public:
    using iterator = DequeIterator<T>;

    Deque();
    ~Deque();

    void pushBack(T val);
    void pushFront(T val);

    void popBack();
    void popFront();

    T& front();
    T& back();

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    bool empty() const;
    size_t size() const;

    iterator begin();
    iterator end();

    void display() const;

    friend class DequeIterator<T>;
};

#include "../src/Deque.cpp"

#endif