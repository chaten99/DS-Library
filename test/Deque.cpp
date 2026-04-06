#include <iostream>
#include "Deque.hpp"
using namespace std;

void testDeque() {
    cout << "===== Deque Tests =====\n\n";

    Deque<int> d;

    d.pushBack(10);
    d.pushBack(20);
    d.pushFront(5);
    d.pushFront(1);

    d.display();

    d.popFront();
    d.popBack();

    d.display();

    cout << "Front: " << d.front() << endl;
    cout << "Back: " << d.back() << endl;

    cout << "Index [1]: " << d[1] << endl;
    cout << "Size: " << d.size() << endl << "\n";

    try {
    d.popBack();
    d.popBack();
    d.popBack();
    d.popBack();
    d.popBack();
    } catch(const exception& e){
        cout << "\033[31mError: "<< e.what() << "\033[0m" << endl;
    }
}

void testDequeIterator() {
    cout << "\n===== Deque STL-style Iterator Tests =====\n\n";

    Deque<int> deque;
    for (int i = 10; i <= 50; i += 10) {
        deque.pushBack(i);
    }

    cout << "--- Test 1: Range-based for loop ---\n";
    cout << "Elements: ";
    for (int x : deque) {
        cout << x << " ";
    }
    cout << "\n\n";

    cout << "--- Test 2: Manual iterator ---\n";
    auto it = deque.begin();
    auto end = deque.end();
    cout << "Forward iteration: ";
    while (it != end) {
        cout << *it << " ";
        ++it;
    }
    cout << "\n\n";

    cout << "--- Test 3: Random access with increment ---\n";
    it = deque.begin();
    cout << "First: " << *it << "\n";
    ++it;
    cout << "Second: " << *it << "\n";
    ++it;
    cout << "Third: " << *it << "\n";
}

int main() {
    testDeque();
    testDequeIterator();
    return 0;
}