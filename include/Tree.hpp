#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <queue>
#include <vector>
#include <functional>

template <typename T>
class Tree;

template <typename T>
class TreeIterator {
public:
    using value_type = T;

private:
    std::vector<T> elements;
    typename std::vector<T>::iterator current;

public:
    TreeIterator() : current(elements.end()) {}
    explicit TreeIterator(const std::vector<T>& elem, bool isBegin = true)
        : elements(elem) {
        current = isBegin ? elements.begin() : elements.end();
    }

    T& operator*() {
        return *current;
    }

    const T& operator*() const {
        return *current;
    }

    T* operator->() {
        return &(*current);
    }

    const T* operator->() const {
        return &(*current);
    }

    TreeIterator& operator++() {
        ++current;
        return *this;
    }

    TreeIterator operator++(int) {
        TreeIterator tmp = *this;
        ++current;
        return tmp;
    }

    TreeIterator& operator--() {
        --current;
        return *this;
    }

    TreeIterator operator--(int) {
        TreeIterator tmp = *this;
        --current;
        return tmp;
    }

    bool operator==(const TreeIterator& other) const {
        return current == other.current;
    }

    bool operator!=(const TreeIterator& other) const {
        return current != other.current;
    }

    friend class Tree<T>;
};

template <typename T>
class Tree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;
    size_t nodeCount;

    Node* insert(Node* node, T val);
    Node* deleteNode(Node* node, T val);
    Node* findMin(Node* node) const;
    void inOrderHelper(Node* node, std::vector<T>& result) const;
    void preOrderHelper(Node* node, std::vector<T>& result) const;
    void postOrderHelper(Node* node, std::vector<T>& result) const;
    void clear(Node* node);
    Node* search(Node* node, T val) const;

public:
    using iterator = TreeIterator<T>;

    Tree();
    ~Tree();

    void insert(T val);
    void remove(T val);
    bool search(T val) const;
    bool contains(T val) const;

    std::vector<T> inOrderTraversal() const;
    std::vector<T> preOrderTraversal() const;
    std::vector<T> postOrderTraversal() const;
    std::vector<T> levelOrderTraversal() const;
    std::vector<T> morrisInOrderTraversal() const;

    void displayInOrder() const;
    void displayPreOrder() const;
    void displayPostOrder() const;
    void displayLevelOrder() const;
    void displayMorrisInOrder() const;

    bool isEmpty() const;
    size_t size() const;

    iterator begin();
    iterator end();

    friend class TreeIterator<T>;
};

#include "../src/Tree.cpp"

#endif
