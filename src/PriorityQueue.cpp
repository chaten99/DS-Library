#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include <algorithm>
#include "PriorityQueue.hpp"

template <typename T, typename Container, typename Compare>
PriorityQueue<T, Container, Compare>::PriorityQueue() {}

template <typename T, typename Container, typename Compare>
PriorityQueue<T, Container, Compare>::PriorityQueue(std::initializer_list<T> init){
    for (const T &val : init){
        container.pushBack(val);
    }
    for (int i = static_cast<int>(container.size() / 2) - 1; i >= 0; --i){
        heapify(i);
    }
}

template <typename T, typename Container, typename Compare>
PriorityQueue<T, Container, Compare>::~PriorityQueue() {}

template <typename T, typename Container, typename Compare>
void PriorityQueue<T, Container, Compare>::heapify(size_t index){
    size_t largest = index;
    size_t left = 2 * index + 1;
    size_t right = 2 * index + 2;

    if (left < container.size() && compare(container[largest], container[left])){
        largest = left;
    }

    if (right < container.size() && compare(container[largest], container[right])){
        largest = right;
    }

    if (largest != index){
        std::swap(container[index], container[largest]);
        heapify(largest);
    }
}

template <typename T, typename Container, typename Compare>
void PriorityQueue<T, Container, Compare>::push(const T &val){
    container.pushBack(val);

    size_t index = container.size() - 1;
    while (index > 0){
        size_t parent = (index - 1) / 2;
        if (compare(container[parent], container[index])){
            std::swap(container[index], container[parent]);
            index = parent;
        }
        else{
            break;
        }
    }
}

template <typename T, typename Container, typename Compare>
void PriorityQueue<T, Container, Compare>::pop(){
    if (empty()){
        throw std::runtime_error("PriorityQueue is empty");
    }

    container[0] = container[container.size() - 1];
    container.popBack();

    if (!empty()){
        heapify(0);
    }
}

template <typename T, typename Container, typename Compare>
T &PriorityQueue<T, Container, Compare>::top(){
    if (empty()){
        throw std::runtime_error("PriorityQueue is empty");
    }
    return container[0];
}

template <typename T, typename Container, typename Compare>
const T &PriorityQueue<T, Container, Compare>::top() const{
    if (empty()){
        throw std::runtime_error("PriorityQueue is empty");
    }
    return container[0];
}

template <typename T, typename Container, typename Compare>
bool PriorityQueue<T, Container, Compare>::empty() const{
    return container.empty();
}

template <typename T, typename Container, typename Compare>
size_t PriorityQueue<T, Container, Compare>::size() const{
    return container.size();
}
