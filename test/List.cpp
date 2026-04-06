#include <iostream>
#include "List.hpp"
using namespace std;

void testList() {
    cout << "===== List Tests =====\n\n";

    List<int> l = {10, 20, 30};

    l.pushFront(5);
    l.pushBack(40);
    l.display();

    l.popFront();
    l.popBack();
    l.display();

    cout << "Front: " << l.front() << endl;
    cout << "Back: " << l.back() << endl;
    cout << "Size: " << l.size() << endl << "\n";
}

void testListIterator() {
    cout << "===== List STL-style Iterator Tests =====\n\n";

    List<int> list = {100, 200, 300, 400};

    cout << "--- Test 1: Range-based for loop ---\n";
    cout << "Elements: ";
    for (int x : list) {
        cout << x << " ";
    }
    cout << "\n\n";

    cout << "--- Test 2: Manual iterator increment ---\n";
    auto it = list.begin();
    auto end = list.end();
    cout << "Forward iteration: ";
    while (it != end) {
        cout << *it << " ";
        ++it;
    }
    cout << "\n\n";

    cout << "--- Test 3: Decrement (backward) ---\n";
    it = list.end();
    --it;  // Move to last element
    cout << "From last to first: ";
    int count = 0;
    while (count < 4) {
        cout << *it << " ";
        if (count < 3) --it;
        count++;
    }
    cout << "\n\n";

    cout << "--- Test 4: String List ---\n";
    List<string> strList = {"cat", "dog", "bird"};
    for (const auto& s : strList) {
        cout << s << " ";
    }
    cout << "\n";
}

int main() {
    testList();
    testListIterator();
    return 0;
}