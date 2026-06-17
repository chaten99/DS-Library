#include <iostream>
#include "List.hpp"

using namespace std;

void separator() {
    cout << "\n---------------------------------\n";
}

int main() {

    cout << "===== DOUBLY LINKED LIST TEST =====\n";

    separator();
    cout << "1. Initializer List Constructor\n";

    List<int> l1 = {10, 20, 30};

    l1.display();

    cout << "Size: " << l1.size() << endl;

    separator();
    cout << "2. pushFront()\n";

    l1.pushFront(5);

    l1.display();

    separator();
    cout << "3. pushBack()\n";

    l1.pushBack(40);

    l1.display();

    separator();
    cout << "4. front() / back()\n";

    cout << "Front: " << l1.front() << endl;
    cout << "Back: " << l1.back() << endl;

    separator();
    cout << "5. at()\n";

    cout << "at(0): " << l1.at(0) << endl;
    cout << "at(2): " << l1.at(2) << endl;
    cout << "at(4): " << l1.at(4) << endl;

    separator();
    cout << "6. insert(index, value)\n";

    l1.insert(2, 999);

    l1.display();

    separator();
    cout << "7. search()\n";

    cout << "Search 999: "
         << (l1.search(999) ? "Found" : "Not Found")
         << endl;

    cout << "Search 777: "
         << (l1.search(777) ? "Found" : "Not Found")
         << endl;

    separator();
    cout << "8. popFront()\n";

    l1.popFront();

    l1.display();

    separator();
    cout << "9. popBack()\n";

    l1.popBack();

    l1.display();

    separator();
    cout << "10. Copy Constructor\n";

    List<int> l2(l1);

    cout << "Original:\n";
    l1.display();

    cout << "Copy:\n";
    l2.display();

    l2.at(0) = 777;

    cout << "\nAfter modifying copy:\n";

    cout << "Original:\n";
    l1.display();

    cout << "Copy:\n";
    l2.display();

    separator();
    cout << "11. Assignment Operator\n";

    List<int> l3;

    l3 = l1;

    cout << "Assigned:\n";
    l3.display();

    l3.at(1) = 555;

    cout << "\nAfter modifying assigned list:\n";

    cout << "Original:\n";
    l1.display();

    cout << "Assigned:\n";
    l3.display();

    separator();
    cout << "12. Self Assignment\n";

    l3 = l3;

    l3.display();

    separator();
    cout << "13. Exception Tests\n";

    try {
        cout << l1.at(100) << endl;
    }
    catch (const exception& e) {
        cout << "Caught: " << e.what() << endl;
    }

    separator();
    cout << "14. Scope Destruction Test\n";

    {
        List<int> temp = {1,2,3,4,5};

        temp.pushFront(0);
        temp.pushBack(6);

        temp.display();
    }

    cout << "Temp destroyed successfully\n";

    separator();
    cout << "ALL TESTS COMPLETED\n";

    return 0;
}