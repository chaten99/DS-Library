#ifndef STACK_H
#define STACK_H

#include "Deque.hpp"

template <typename T, typename Container = Deque<T>>
class Stack {
private:
    Container container;

public:
    Stack();
    Stack(std::initializer_list<T> init);

    void push(const T& val);
    void pop();

    T& top();
    const T& top() const;

    bool empty() const;
    size_t size() const;

    void display() const;
};

#include "Stack.cpp"


#endif