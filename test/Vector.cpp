#include <iostream>
#include "Vector.hpp"
using namespace std;

void testVector() {
    Vector<int> v = {10, 20, 30};

    v.pushBack(40);
    v.display();

    v.popBack();
    v.display();

    cout << "Front: " << v.front() << endl;
    cout << "Back: " << v.back() << endl;
    cout << "At(1): " << v.at(1) << endl;

    cout << "Size: " << v.size() << endl;
}

int main() {
    testVector();
    return 0;
}