#include <iostream>
#include <stdexcept>
#include "Deque.hpp"

template <typename T>
Deque<T>::Deque() {
    mapSize = 10;
    blockSize = 4;

    map = new T*[mapSize];

    for(size_t i = 0; i < mapSize; i++) map[i] = nullptr;

    frontBlock = backBlock = mapSize / 2;
    allocateBlock(frontBlock);

    frontIndex = backIndex = blockSize / 2;
}

template <typename T>
void Deque<T>::reallocateMap() {
    size_t newMapSize = mapSize * 2;

    T** newMap = new T*[newMapSize];

    for (size_t i = 0; i < newMapSize; i++) {
        newMap[i] = nullptr;
    }

    size_t usedBlocks = backBlock - frontBlock + 1;
    size_t newFrontBlock = (newMapSize - usedBlocks) / 2;

    size_t j = newFrontBlock;

    for (size_t i = frontBlock; i <= backBlock; i++) {
        newMap[j++] = map[i];
    }

    delete[] map;

    map = newMap;
    mapSize = newMapSize;

    backBlock = newFrontBlock + usedBlocks - 1;
    frontBlock = newFrontBlock;
}

template <typename T>
Deque<T>::~Deque() {
    for(size_t i = 0; i < mapSize; i++) {
        delete[] map[i];
    }
    delete[] map;
}

template <typename T>
void Deque<T>::allocateBlock(size_t index) {
    if (!map[index]) {
        map[index] = new T[blockSize];
    }
}

template <typename T>
void Deque<T>::pushBack(T val) {
    if (backBlock == mapSize - 1 && backIndex == blockSize) {
        reallocateMap();
    }

    if (backIndex == blockSize) {
        backBlock++;
        allocateBlock(backBlock);
        backIndex = 0;
    }

    map[backBlock][backIndex++] = val;
}

template <typename T>
void Deque<T>::pushFront(T val) {
    if (frontBlock == 0 && frontIndex == 0) {
        reallocateMap();
    }

    if (frontIndex == 0) {
        frontBlock--;
        allocateBlock(frontBlock);
        frontIndex = blockSize;
    }

    map[frontBlock][--frontIndex] = val;
}

template <typename T>
void Deque<T>::popBack() {
    if (empty()) throw std::runtime_error("Deque empty");

    if (backIndex == 0) {
        backBlock--;
        backIndex = blockSize;
    }

    backIndex--;
}

template <typename T>
void Deque<T>::popFront() {
    if (empty()) throw std::runtime_error("Deque empty");

    frontIndex++;

    if (frontIndex == blockSize) {
        frontBlock++;
        frontIndex = 0;
    }
}

template <typename T>
T& Deque<T>::front() {
    if (empty()) throw std::runtime_error("Deque empty");
    return map[frontBlock][frontIndex];
}

template <typename T>
T& Deque<T>::back() {
    if (empty()) throw std::runtime_error("Deque empty");

    size_t b = backBlock;
    size_t i = backIndex;

    if (i == 0) {
        b--;
        i = blockSize;
    }

    return map[b][i - 1];
}

template <typename T>
T& Deque<T>::operator[](size_t index) {
    if (index >= size()) throw std::out_of_range("Index out of range");

    size_t offset = frontIndex + index;

    size_t block = frontBlock + (offset / blockSize);
    size_t pos = offset % blockSize;

    return map[block][pos];
}

template <typename T>
const T& Deque<T>::operator[](size_t index) const {
    if (index >= size()) throw std::out_of_range("Index out of range");

    size_t offset = frontIndex + index;

    size_t block = frontBlock + (offset / blockSize);
    size_t pos   = offset % blockSize;

    return map[block][pos];
}



template <typename T>
bool Deque<T>::empty() const {
    return frontBlock == backBlock && frontIndex == backIndex;
}

template <typename T>
size_t Deque<T>::size() const {
    return (backBlock - frontBlock) * blockSize + (backIndex - frontIndex);
}

template <typename T>
void Deque<T>::display() const {
    for (size_t i = 0; i < size(); i++) {
        std::cout << (*this)[i] << " ";
    }
    std::cout << "\n";
}