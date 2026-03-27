#include <iostream>
#include "List.hpp"
using namespace std;

void testList() {
    cout << "\nLIST TEST\n";

    List<int> l = {10, 20, 30};

    l.pushFront(5);
    l.pushBack(40);
    l.display();

    l.popFront();
    l.popBack();
    l.display();

    cout << "Front: " << l.front() << endl;
    cout << "Back: " << l.back() << endl;

    cout << "Size: " << l.size() << endl;
}

int main() {
    testList();
    return 0;
}