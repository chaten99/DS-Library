#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include "Stack.hpp"

template <typename T, typename Container>
Stack<T, Container>::Stack() {}

template <typename T, typename Container>
Stack<T, Container>::Stack(std::initializer_list<T> init) {
    for (const T& val : init) {
        container.pushBack(val);
    }
}

template <typename T, typename Container>
void Stack<T, Container>::push(const T& val) {
    container.pushBack(val);
}

template <typename T, typename Container>
void Stack<T, Container>::pop() {
    if (empty()) {
        throw std::runtime_error("Stack is empty");
    }
    container.popBack();
}

template <typename T, typename Container>
T& Stack<T, Container>::top() {
    if (empty()) {
        throw std::runtime_error("Stack is empty");
    }
    return container.back();
}

template <typename T, typename Container>
const T& Stack<T, Container>::top() const {
    if (empty()) {
        throw std::runtime_error("Stack is empty");
    }
    return container.back();
}

template <typename T, typename Container>
bool Stack<T, Container>::empty() const {
    return container.empty();
}

template <typename T, typename Container>
size_t Stack<T, Container>::size() const {
    return container.size();
}

template <typename T, typename Container>
void Stack<T, Container>::display() const {
    container.display();
}