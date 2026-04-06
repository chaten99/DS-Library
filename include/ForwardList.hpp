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
    class iterator {
    private:
        Node* current;

    public:
        iterator() : current(nullptr) {}
        explicit iterator(Node* node) : current(node) {}

        T& operator*() const {
            return current->data;
        }

        T* operator->() const {
            return &(current->data);
        }

        iterator& operator++() {
            if (current) current = current->next;
            return *this;
        }

        iterator operator++(int) {
            iterator tmp = *this;
            if (current) current = current->next;
            return tmp;
        }

        bool operator==(const iterator& other) const {
            return current == other.current;
        }

        bool operator!=(const iterator& other) const {
            return current != other.current;
        }

        friend class ForwardList<T>;
    };

    ForwardList();
    ~ForwardList();

    ForwardList(std::initializer_list<T> init);
    ForwardList(const ForwardList& other);
    ForwardList& operator=(const ForwardList& other);

    void pushFront(T val);
    void popFront();

    T& front();

    bool empty() const;
    size_t size() const;

    iterator begin();
    iterator end();

    void clear();
    void display() const;
};

#include "../src/ForwardList.cpp"

#endif