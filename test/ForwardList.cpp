#include <iostream>
#include "ForwardList.hpp"
using namespace std;

void testForwardList() {
    cout << "===== ForwardList Tests =====\n\n";

    ForwardList<int> fl = {10, 20, 30};

    fl.pushFront(5);
    fl.display();

    fl.popFront();
    fl.display();

    cout << "Front: " << fl.front() << endl;
    cout << "Size: " << fl.size() << endl << "\n";
}

void testForwardListIterator() {
    cout << "===== ForwardList STL-style Iterator Tests =====\n\n";

    ForwardList<int> flist = {1, 2, 3, 4, 5};

    cout << "--- Test 1: Range-based for loop ---\n";
    cout << "Elements: ";
    for (int x : flist) {
        cout << x << " ";
    }
    cout << "\n\n";

    cout << "--- Test 2: Manual iterator with ++ only ---\n";
    auto it = flist.begin();
    auto end = flist.end();
    cout << "Forward iteration: ";
    while (it != end) {
        cout << *it << " ";
        ++it;
    }
    cout << "\n\n";

    cout << "--- Test 3: Post-increment ---\n";
    it = flist.begin();
    cout << "First element: " << *(it++) << "\n";
    cout << "After post-increment: " << *it << "\n\n";

    cout << "--- Test 4: String ForwardList ---\n";
    ForwardList<string> strFList = {"hello", "world", "cpp"};
    for (const auto& s : strFList) {
        cout << s << " ";
    }
    cout << "\n";
}

int main() {
    testForwardList();
    testForwardListIterator();
    return 0;
}