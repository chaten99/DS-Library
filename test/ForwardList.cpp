#include <iostream>
#include "ForwardList.hpp"

using namespace std;

void separator() {
    cout << "\n---------------------------------\n";
}

int main() {

    cout << "===== FORWARD LIST TEST =====\n";

    separator();
    cout << "1. Initializer List Constructor\n";

    ForwardList<int> fl1 = {10, 20, 30};

    fl1.display();

    cout << "Size: " << fl1.size() << endl;

    separator();
    cout << "2. pushFront()\n";

    fl1.pushFront(5);

    fl1.display();

    separator();
    cout << "3. front()\n";

    cout << "Front: " << fl1.front() << endl;

    separator();
    cout << "4. insert(index, value)\n";

    fl1.insert(2, 999);

    fl1.display();

    separator();
    cout << "5. search()\n";

    cout << "Search 999: "
         << (fl1.search(999) ? "Found" : "Not Found")
         << endl;

    cout << "Search 777: "
         << (fl1.search(777) ? "Found" : "Not Found")
         << endl;

    separator();
    cout << "6. popFront()\n";

    fl1.popFront();

    fl1.display();

    separator();
    cout << "7. Copy Constructor\n";

    ForwardList<int> fl2(fl1);

    cout << "Original:\n";
    fl1.display();

    cout << "Copy:\n";
    fl2.display();

    fl2.front() = 777;

    cout << "\nAfter modifying copy:\n";

    cout << "Original:\n";
    fl1.display();

    cout << "Copy:\n";
    fl2.display();

    separator();
    cout << "8. Assignment Operator\n";

    ForwardList<int> fl3;

    fl3 = fl1;

    cout << "Assigned:\n";
    fl3.display();

    fl3.front() = 555;

    cout << "\nAfter modifying assigned list:\n";

    cout << "Original:\n";
    fl1.display();

    cout << "Assigned:\n";
    fl3.display();

    separator();
    cout << "9. Self Assignment\n";

    fl3 = fl3;

    fl3.display();

    separator();
    cout << "10. Exception Test\n";

    try {
        ForwardList<int> emptyList;

        emptyList.popFront();
    }
    catch (const exception& e) {
        cout << "Caught: " << e.what() << endl;
    }

    separator();
    cout << "11. Scope Destruction Test\n";

    {
        ForwardList<int> temp = {1,2,3,4,5};

        temp.pushFront(0);
        temp.insert(3, 100);

        temp.display();
    }

    cout << "Temp destroyed successfully\n";

    separator();
    cout << "12. Large Allocation Test\n";

    {
        ForwardList<int> bigList;

        for (int i = 0; i < 10000; i++) {
            bigList.pushFront(i);
        }

        cout << "Inserted 10000 nodes\n";
        cout << "Size: " << bigList.size() << endl;
    }

    cout << "Large list destroyed successfully\n";

    separator();
    cout << "ALL TESTS COMPLETED\n";

    return 0;
}