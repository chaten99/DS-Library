#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <iostream>
#include <stdexcept>
#include <initializer_list>

template <typename T>
class ForwardList {
public:
    struct Node {
        T data;
        Node* next;

        Node(T val) : data(val), next(nullptr) {}
    };

private:
    Node* head;
    size_t length;

    void copyFrom(const ForwardList& other);

public:
    ForwardList();
    ~ForwardList();

    ForwardList(std::initializer_list<T> init);
    ForwardList(const ForwardList& other);
    ForwardList& operator=(const ForwardList& other);

    void pushFront(T val);
    void popFront();
    void insert(size_t index, T val);

    T& front();

    bool empty() const;
    size_t size() const;

    bool search(T val) const;

    void clear();
    void display() const;
};

#include "../src/ForwardList.cpp"

#endif