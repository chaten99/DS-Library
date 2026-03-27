#ifndef QUEUE_H
#define QUEUE_H

#include "Deque.hpp"

template <typename T, typename Container = Deque<T>>
class Queue {
private:
    Container container;

public:
    Queue();
    Queue(std::initializer_list<T> init);

    void push(const T& val);
    void pop();

    T& front();
    const T& front() const;

    T& back();
    const T& back() const;

    bool empty() const;
    size_t size() const;

    void display() const;
};

#include "../src/Queue.cpp"


#endif