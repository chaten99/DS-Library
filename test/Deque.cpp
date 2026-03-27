#include <iostream>
#include "Deque.hpp"
using namespace std;

void testDeque() {
    cout << "\nDEQUE TEST\n";

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
    cout << "Size: " << d.size() << endl;

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

int main() {
    testDeque();
    return 0;
}