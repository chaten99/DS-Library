#include <iostream>
#include <stdexcept>
#include <initializer_list>


template <typename T>
List<T>::List() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template <typename T>
List<T>::~List() {
    clear();
}

template <typename T>
List<T>::List(std::initializer_list<T> init) {
    head = nullptr;
    tail = nullptr;
    length = 0;

    for (const T& val : init) {
        pushBack(val);
    }
}

template <typename T>
void List<T>::copyFrom(const List& other) {
    Node* temp = other.head;
    while (temp) {
        pushBack(temp->data);
        temp = temp->next;
    }
}

template <typename T>
List<T>::List(const List& other) {
    head = nullptr;
    tail = nullptr;
    length = 0;
    copyFrom(other);
}

template <typename T>
List<T>& List<T>::operator=(const List& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}

template <typename T>
void List<T>::pushFront(T val) {
    Node* newNode = new Node(val);

    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    length++;
}

template <typename T>
void List<T>::pushBack(T val) {
    Node* newNode = new Node(val);

    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    length++;
}

template <typename T>
void List<T>::popFront() {
    if (!head) throw std::runtime_error("List is empty");

    Node* temp = head;
    head = head->next;

    if (head) head->prev = nullptr;
    else tail = nullptr;

    delete temp;
    length--;
}

template <typename T>
void List<T>::popBack() {
    if (!tail) throw std::runtime_error("List is empty");

    Node* temp = tail;
    tail = tail->prev;

    if (tail) tail->next = nullptr;
    else head = nullptr;

    delete temp;
    length--;
}

template <typename T>
T& List<T>::front() {
    if (!head) throw std::runtime_error("List is empty");
    return head->data;
}

template <typename T>
T& List<T>::back() {
    if (!tail) throw std::runtime_error("List is empty");
    return tail->data;
}

template <typename T>
T& List<T>::at(size_t index) {
    if (index >= length) throw std::out_of_range("Index out of range");

    Node* temp = head;
    for (size_t i = 0; i < index; i++) {
        temp = temp->next;
    }

    return temp->data;
}

template <typename T>
bool List<T>::empty() const {
    return length == 0;
}

template <typename T>
size_t List<T>::size() const {
    return length;
}

template <typename T>
void List<T>::clear() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    tail = nullptr;
    length = 0;
}

template <typename T>
void List<T>::display() const {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " <-> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

template <typename T>
typename List<T>::iterator List<T>::begin() {
    return iterator(head);
}

template <typename T>
typename List<T>::iterator List<T>::end() {
    return iterator(nullptr);
}
