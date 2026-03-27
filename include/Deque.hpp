#ifndef DEQUE_H
#define DEQUE_H


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

    void allocateBlock(size_t index);
    void reallocateMap();

public:
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

    void display() const;
};

#include "../src/Deque.cpp"

#endif