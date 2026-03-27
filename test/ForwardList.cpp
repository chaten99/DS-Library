#include <iostream>
#include "ForwardList.hpp"
using namespace std;

void testForwardList() {
    cout << "\nFORWARD LIST TEST\n";

    ForwardList<int> fl = {10, 20, 30};

    fl.pushFront(5);
    fl.display();

    fl.popFront();
    fl.display();

    cout << "Front: " << fl.front() << endl;
    cout << "Size: " << fl.size() << endl;
}

int main() {
    testForwardList();
    return 0;
}