#include <iostream>
#include "Vector.hpp"

using namespace std;

void separator() {
    cout << "\n---------------------------------\n";
}

int main() {

    cout << "===== VECTOR COMPLETE TEST =====\n";

    separator();
    cout << "1. Initializer List Constructor\n";

    Vector<int> v1 = {10, 20, 30};

    v1.display();

    cout << "Size: " << v1.size() << endl;
    cout << "Capacity: " << v1.capacity() << endl;

    separator();
    cout << "2. pushBack + Resize Test\n";

    for (int i = 40; i <= 100; i += 10) {
        v1.pushBack(i);
    }

    v1.display();

    cout << "Size: " << v1.size() << endl;
    cout << "Capacity: " << v1.capacity() << endl;

    separator();
    cout << "3. front / back\n";

    cout << "Front: " << v1.front() << endl;
    cout << "Back: " << v1.back() << endl;

    separator();
    cout << "4. operator[]\n";

    cout << v1[0] << endl;
    cout << v1[2] << endl;

    separator();
    cout << "5. at()\n";

    cout << v1.at(1) << endl;
    cout << v1.at(3) << endl;

    separator();
    cout << "6. insert()\n";

    v1.insert(2, 999);

    v1.display();

    separator();
    cout << "7. remove()\n";

    v1.remove(2);

    v1.display();

    separator();
    cout << "8. popBack()\n";

    v1.popBack();

    v1.display();

    separator();
    cout << "9. Copy Constructor\n";

    Vector<int> v2(v1);

    cout << "Original:\n";
    v1.display();

    cout << "Copy:\n";
    v2.display();

    v2[0] = 777;

    cout << "\nAfter modifying copy:\n";

    cout << "Original:\n";
    v1.display();

    cout << "Copy:\n";
    v2.display();

    separator();
    cout << "10. Assignment Operator\n";

    Vector<int> v3;

    v3 = v1;

    cout << "Assigned:\n";
    v3.display();

    v3[1] = 555;

    cout << "\nAfter modifying assigned vector:\n";

    cout << "Original:\n";
    v1.display();

    cout << "Assigned:\n";
    v3.display();

    separator();
    cout << "11. Self Assignment\n";

    v3 = v3;

    v3.display();

    separator();
    cout << "12. Exception Tests\n";

    try {
        cout << v1.at(100) << endl;
    }
    catch (const exception& e) {
        cout << "Caught: " << e.what() << endl;
    }

    separator();
    cout << "13. Scope Destruction Test\n";

    {
        Vector<int> temp = {1,2,3,4,5};

        temp.pushBack(6);
        temp.pushBack(7);

        temp.display();
    }

    cout << "Temp destroyed successfully\n";

    separator();
    cout << "ALL TESTS COMPLETED\n";

    return 0;
}