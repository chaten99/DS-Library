#include <iostream>
#include <queue>
#include <vector>
#include <stdexcept>
#include "Tree.hpp"

template <typename T>
Tree<T>::Tree() : root(nullptr), nodeCount(0) {}

template <typename T>
Tree<T>::~Tree() {
    clear(root);
}

template <typename T>
void Tree<T>::clear(Node* node) {
    if (node == nullptr) return;
    clear(node->left);
    clear(node->right);
    delete node;
}

template <typename T>
typename Tree<T>::Node* Tree<T>::insert(Node* node, T val) {
    if (node == nullptr) {
        nodeCount++;
        return new Node(val);
    }

    if (val < node->data) {
        node->left = insert(node->left, val);
    } else if (val > node->data) {
        node->right = insert(node->right, val);
    }

    return node;
}

template <typename T>
void Tree<T>::insert(T val) {
    root = insert(root, val);
}

template <typename T>
typename Tree<T>::Node* Tree<T>::findMin(Node* node) const {
    if (node == nullptr) return nullptr;
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

template <typename T>
typename Tree<T>::Node* Tree<T>::deleteNode(Node* node, T val) {
    if (node == nullptr) return nullptr;

    if (val < node->data) {
        node->left = deleteNode(node->left, val);
    } else if (val > node->data) {
        node->right = deleteNode(node->right, val);
    } else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            nodeCount--;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            nodeCount--;
            return temp;
        }

        Node* minRight = findMin(node->right);
        node->data = minRight->data;
        node->right = deleteNode(node->right, minRight->data);
    }

    return node;
}

template <typename T>
void Tree<T>::remove(T val) {
    root = deleteNode(root, val);
}

template <typename T>
typename Tree<T>::Node* Tree<T>::search(Node* node, T val) const {
    if (node == nullptr) return nullptr;

    if (val == node->data) {
        return node;
    } else if (val < node->data) {
        return search(node->left, val);
    } else {
        return search(node->right, val);
    }
}

template <typename T>
bool Tree<T>::search(T val) const {
    return search(root, val) != nullptr;
}

template <typename T>
bool Tree<T>::contains(T val) const {
    return search(val);
}

// In-order traversal: Left -> Root -> Right
template <typename T>
void Tree<T>::inOrderHelper(Node* node, std::vector<T>& result) const {
    if (node == nullptr) return;
    inOrderHelper(node->left, result);
    result.push_back(node->data);
    inOrderHelper(node->right, result);
}

template <typename T>
std::vector<T> Tree<T>::inOrderTraversal() const {
    std::vector<T> result;
    inOrderHelper(root, result);
    return result;
}

// Pre-order traversal: Root -> Left -> Right
template <typename T>
void Tree<T>::preOrderHelper(Node* node, std::vector<T>& result) const {
    if (node == nullptr) return;
    result.push_back(node->data);
    preOrderHelper(node->left, result);
    preOrderHelper(node->right, result);
}

template <typename T>
std::vector<T> Tree<T>::preOrderTraversal() const {
    std::vector<T> result;
    preOrderHelper(root, result);
    return result;
}

// Post-order traversal: Left -> Right -> Root
template <typename T>
void Tree<T>::postOrderHelper(Node* node, std::vector<T>& result) const {
    if (node == nullptr) return;
    postOrderHelper(node->left, result);
    postOrderHelper(node->right, result);
    result.push_back(node->data);
}

template <typename T>
std::vector<T> Tree<T>::postOrderTraversal() const {
    std::vector<T> result;
    postOrderHelper(root, result);
    return result;
}

// Level-order traversal: BFS using queue
template <typename T>
std::vector<T> Tree<T>::levelOrderTraversal() const {
    std::vector<T> result;
    if (root == nullptr) return result;

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        result.push_back(node->data);

        if (node->left != nullptr) q.push(node->left);
        if (node->right != nullptr) q.push(node->right);
    }

    return result;
}

// Morris In-order traversal: O(n) time, O(1) space, no recursion
template <typename T>
std::vector<T> Tree<T>::morrisInOrderTraversal() const {
    std::vector<T> result;
    Node* current = root;

    while (current != nullptr) {
        if (current->left == nullptr) {
            result.push_back(current->data);
            current = current->right;
        } else {
            Node* predecessor = current->left;
            while (predecessor->right != nullptr && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == nullptr) {
                predecessor->right = current;
                current = current->left;
            } else {
                predecessor->right = nullptr;
                result.push_back(current->data);
                current = current->right;
            }
        }
    }

    return result;
}

// Display functions
template <typename T>
void Tree<T>::displayInOrder() const {
    std::cout << "In-order: ";
    for (T val : inOrderTraversal()) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

template <typename T>
void Tree<T>::displayPreOrder() const {
    std::cout << "Pre-order: ";
    for (T val : preOrderTraversal()) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

template <typename T>
void Tree<T>::displayPostOrder() const {
    std::cout << "Post-order: ";
    for (T val : postOrderTraversal()) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

template <typename T>
void Tree<T>::displayLevelOrder() const {
    std::cout << "Level-order: ";
    for (T val : levelOrderTraversal()) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

template <typename T>
void Tree<T>::displayMorrisInOrder() const {
    std::cout << "Morris In-order: ";
    for (T val : morrisInOrderTraversal()) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

template <typename T>
bool Tree<T>::isEmpty() const {
    return root == nullptr;
}

template <typename T>
size_t Tree<T>::size() const {
    return nodeCount;
}

template <typename T>
typename Tree<T>::iterator Tree<T>::begin() {
    std::vector<T> elements = inOrderTraversal();
    return iterator(elements, true);
}

template <typename T>
typename Tree<T>::iterator Tree<T>::end() {
    std::vector<T> elements = inOrderTraversal();
    return iterator(elements, false);
}
