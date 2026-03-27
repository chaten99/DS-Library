#include <iostream>
#include "Stack.hpp"
using namespace std;

void testStack() {
    cout << "\nSTACK TEST\n";

    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl;

    s.pop();

    cout << "Top after pop: " << s.top() << endl;
}

int main() {
    testStack();
    return 0;
}