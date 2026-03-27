#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include "Queue.hpp"

template <typename T, typename Container>
Queue<T, Container>::Queue() {}

template <typename T, typename Container>
Queue<T, Container>::Queue(std::initializer_list<T> init) {
    for (const T& val : init) {
        container.pushBack(val);
    }
}

template <typename T, typename Container>
void Queue<T, Container>::push(const T& val) {
    container.pushBack(val);
}

template <typename T, typename Container>
void Queue<T, Container>::pop() {
    if (empty()) {
        throw std::runtime_error("Queue is empty");
    }
    container.popFront();
}

template <typename T, typename Container>
T& Queue<T, Container>::front() {
    if (empty()) {
        throw std::runtime_error("Queue is empty");
    }
    return container.front();
}

template <typename T, typename Container>
const T& Queue<T, Container>::front() const {
    if (empty()) {
        throw std::runtime_error("Queue is empty");
    }
    return container.front();
}

template <typename T, typename Container>
T& Queue<T, Container>::back() {
    if (empty()) {
        throw std::runtime_error("Queue is empty");
    }
    return container.back();
}

template <typename T, typename Container>
const T& Queue<T, Container>::back() const {
    if (empty()) {
        throw std::runtime_error("Queue is empty");
    }
    return container.back();
}

template <typename T, typename Container>
bool Queue<T, Container>::empty() const {
    return container.empty();
}

template <typename T, typename Container>
size_t Queue<T, Container>::size() const {
    return container.size();
}

template <typename T, typename Container>
void Queue<T, Container>::display() const {
    container.display();
}