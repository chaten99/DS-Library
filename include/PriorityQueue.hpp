#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>
#include <stdexcept>
#include <initializer_list>

#include "Vector.hpp"

template <typename T, typename Container = Vector<T>, typename Compare = std::less<T>>

class PriorityQueue{
private:
    Container container;
    Compare compare;

public:
    PriorityQueue();
    PriorityQueue(std::initializer_list<T> init);
    ~PriorityQueue();

    void heapify(size_t index);
    void push(const T &val);
    void pop();
    T &top();
    const T &top() const;
    bool empty() const;
    size_t size() const;
};

#include "../src/PriorityQueue.cpp"

#endif