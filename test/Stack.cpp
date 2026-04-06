#include <iostream>
#include "Stack.hpp"
using namespace std;

void testStack() {
    cout << "===== Stack Tests =====\n\n";

    Stack<int> s = {10, 20, 30};

    cout << "Top: " << s.top() << endl;

    s.pop();

    cout << "Top after pop: " << s.top() << endl;
    cout << "Size: " << s.size() << endl << "\n";

    cout << "All elements (popping): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}

void testStackAdvanced() {
    cout << "\n===== Stack Advanced Tests =====\n\n";

    Stack<string> stext;
    stext.push("first");
    stext.push("second");
    stext.push("third");

    cout << "String Stack - Pop in order:\n";
    while (!stext.empty()) {
        cout << stext.top() << "\n";
        stext.pop();
    }
}

int main() {
    testStack();
    testStackAdvanced();
    return 0;
}