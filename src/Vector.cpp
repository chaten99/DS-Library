#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include "Vector.hpp"


template <typename T>
Vector<T>::Vector() {
    currentSize = 0;
    currentCapacity = 1;
    arr = new T[currentCapacity];
}

template <typename T>
Vector<T>::~Vector() {
    delete[] arr;
}

template <typename T>
Vector<T>::Vector(const Vector& other) {
    currentSize = other.currentSize;
    currentCapacity = other.currentCapacity;

    arr = new T[currentCapacity];

    for (size_t i = 0; i < currentSize; i++) {
        arr[i] = other.arr[i];
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this != &other) {

        delete[] arr;

        currentSize = other.currentSize;
        currentCapacity = other.currentCapacity;

        arr = new T[currentCapacity];

        for (size_t i = 0; i < currentSize; i++) {
            arr[i] = other.arr[i];
        }
    }

    return *this;
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> init) {
    currentSize = init.size();
    currentCapacity = currentSize > 0 ? currentSize : 1;

    arr = new T[currentCapacity];

    size_t i = 0;
    for (const T& val : init) arr[i++] = val;
}

template <typename T>
void Vector<T>::resize() {
    currentCapacity *= 2;
    T* newArr = new T[currentCapacity];

    for (size_t i = 0; i < currentSize; i++) {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
}

template <typename T>
void Vector<T>::pushBack(T val) {
    if (currentSize == currentCapacity) resize();
    arr[currentSize++] = val;
}

template <typename T>
void Vector<T>::popBack() {
    if (currentSize == 0) throw std::runtime_error("Vector is empty");
    currentSize--;
}

template <typename T>
void Vector<T>::insert(size_t index, T val) {

    if (index > currentSize)
        throw std::out_of_range("Index out of range");

    if (currentSize == currentCapacity)
        resize();

    for (size_t i = currentSize; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = val;
    currentSize++;
}

template <typename T>
void Vector<T>::remove(size_t index) {

    if (index >= currentSize)
        throw std::out_of_range("Index out of range");

    for (size_t i = index; i < currentSize - 1; i++) {
        arr[i] = arr[i + 1];
    }

    currentSize--;
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
    return arr[index];
}

template <typename T>
T& Vector<T>::at(size_t index) {
    if (index >= currentSize) throw std::out_of_range("Index out of range");
    return arr[index];
}

template <typename T>
T& Vector<T>::front() {
    if (currentSize == 0) throw std::runtime_error("Vector is empty");
    return arr[0];
}

template <typename T>
T& Vector<T>::back() {
    if (currentSize == 0) throw std::runtime_error("Vector is empty");
    return arr[currentSize - 1];
}

template <typename T>
bool Vector<T>::empty() const {
    return currentSize == 0;
}

template <typename T>
size_t Vector<T>::size() const {
    return currentSize;
}

template <typename T>
size_t Vector<T>::capacity() const {
    return currentCapacity;
}

template <typename T>
void Vector<T>::display() const {
    for (size_t i = 0; i < currentSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}


