#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H


template <typename T>
class ForwardList {
private:
    struct Node {
        T data;
        Node* next;

        Node(T val) : data(val), next(nullptr) {}
    };

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

    T& front();

    bool empty() const;
    size_t size() const;

    void clear();
    void display() const;
};

#include "../src/ForwardList.cpp"

#endif