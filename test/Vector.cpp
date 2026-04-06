#include <iostream>
#include "Vector.hpp"
using namespace std;

void testVector() {
    cout << "===== Vector Tests =====\n\n";

    Vector<int> v = {10, 20, 30};

    v.pushBack(40);
    v.display();

    v.popBack();
    v.display();

    cout << "Front: " << v.front() << endl;
    cout << "Back: " << v.back() << endl;
    cout << "At(1): " << v.at(1) << endl;

    cout << "Size: " << v.size() << endl << "\n";
}

void testVectorIterator() {
    cout << "===== Vector STL-style Iterator Tests =====\n\n";

    Vector<int> vec = {5, 15, 25, 35, 45};

    cout << "--- Test 1: Range-based for loop ---\n";
    cout << "Elements: ";
    for (int x : vec) {
        cout << x << " ";
    }
    cout << "\n\n";

    cout << "--- Test 2: Manual iterator with ++/-- ---\n";
    auto it = vec.begin();
    auto end = vec.end();
    
    cout << "Forward: ";
    while (it != end) {
        cout << *it << " ";
        ++it;
    }
    cout << "\n";
    
    cout << "Manual position at index 2: ";
    it = vec.begin();
    ++it;
    ++it;
    cout << *it << "\n\n";

    cout << "--- Test 3: String Vector ---\n";
    Vector<string> strVec = {"apple", "banana", "cherry"};
    cout << "Strings: ";
    for (const auto& s : strVec) {
        cout << s << " ";
    }
    cout << "\n\n";

    cout << "--- Test 4: Arrow operator ---\n";
    Vector<pair<int, int>> pVec = {{1, 2}, {3, 4}, {5, 6}};
    for (auto it = pVec.begin(); it != pVec.end(); ++it) {
        cout << "(" << it->first << ", " << it->second << ") ";
    }
    cout << "\n";
}

int main() {
    testVector();
    testVectorIterator();
    return 0;
}