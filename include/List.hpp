#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>
#include <initializer_list>


template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(T val) : data(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t length;

    void copyFrom(const List& other);

public:
    List();
    ~List();

    List(std::initializer_list<T> init);
    List(const List& other);
    List& operator=(const List& other);

    void pushFront(T val);
    void pushBack(T val);

    void popFront();
    void popBack();

    T& front();
    T& back();
    T& at(size_t index);

    bool empty() const;
    size_t size() const;

    void clear();
    void display() const;
};

#include "../src/List.cpp"

#endif