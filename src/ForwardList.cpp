#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include "ForwardList.hpp"

template <typename T>
ForwardList<T>::ForwardList() {
    head = nullptr;
    length = 0;
}

template <typename T>
ForwardList<T>::~ForwardList() {
    clear();
}

template <typename T>
ForwardList<T>::ForwardList(std::initializer_list<T> init) {
    head = nullptr;
    length = 0;

    for (auto it = std::rbegin(init); it != std::rend(init); ++it) {
        pushFront(*it);
    }
}

template <typename T>
void ForwardList<T>::copyFrom(const ForwardList& other) {
    if (!other.head) return;

    head = new Node(other.head->data);
    Node* curr = head;
    Node* temp = other.head->next;

    while (temp) {
        curr->next = new Node(temp->data);
        curr = curr->next;
        temp = temp->next;
    }

    length = other.length;
}

template <typename T>
ForwardList<T>::ForwardList(const ForwardList& other) {
    head = nullptr;
    length = 0;
    copyFrom(other);
}

template <typename T>
ForwardList<T>& ForwardList<T>::operator=(const ForwardList& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}

template <typename T>
void ForwardList<T>::pushFront(T val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    length++;
}

template <typename T>
void ForwardList<T>::popFront() {
    if (!head) throw std::runtime_error("ForwardList is empty");

    Node* temp = head;
    head = head->next;
    delete temp;
    length--;
}

template <typename T>
T& ForwardList<T>::front() {
    if (!head) throw std::runtime_error("ForwardList is empty");
    return head->data;
}

template <typename T>
bool ForwardList<T>::empty() const {
    return length == 0;
}

template <typename T>
size_t ForwardList<T>::size() const {
    return length;
}

template <typename T>
void ForwardList<T>::clear() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    length = 0;
}

template <typename T>
void ForwardList<T>::display() const {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}
