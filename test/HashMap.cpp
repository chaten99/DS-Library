#include <iostream>
#include <string>
#include "HashMap.hpp"

using namespace std;

void separator() {
    cout << "\n========================================\n";
}

int main() {

    cout << "HASHMAP TEST SUITE\n";

    separator();
    cout << "1. Constructor Test\n";

    HashMap<string, string> map;

    cout << "Size: " << map.size() << endl;
    cout << "Empty: " << boolalpha << map.empty() << endl;
    cout << "Load Factor: " << map.loadFactor() << endl;

    separator();
    cout << "2. Basic Insertions\n";

    map.set("name", "Arun");
    map.set("city", "Delhi");
    map.set("country", "India");

    map.display();

    cout << "Size: " << map.size() << endl;

    separator();
    cout << "3. get()\n";

    cout << map.get("name") << endl;
    cout << map.get("city") << endl;
    cout << map.get("country") << endl;

    separator();
    cout << "4. exists()\n";

    cout << "name -> " << map.exists("name") << endl;
    cout << "age -> " << map.exists("age") << endl;

    separator();
    cout << "5. Overwrite Existing Key\n";

    map.set("name", "Vikram");

    cout << "Updated name: "
         << map.get("name")
         << endl;

    separator();
    cout << "6. remove()\n";

    map.remove("city");

    cout << "Exists(city): "
         << map.exists("city")
         << endl;

    cout << "Size: "
         << map.size()
         << endl;

    separator();
    cout << "7. Exception Test\n";

    try {

        cout << map.get("city") << endl;

    } catch(const exception& e) {

        cout << "Caught: "
             << e.what()
             << endl;
    }

    separator();
    cout << "8. Rehash Test\n";

    for(int i = 0; i < 100; i++) {

        map.set(
            "key" + to_string(i),
            "value" + to_string(i)
        );
    }

    cout << "Size: "
         << map.size()
         << endl;

    cout << "Load Factor: "
         << map.loadFactor()
         << endl;

    cout << map.get("key0") << endl;
    cout << map.get("key50") << endl;
    cout << map.get("key99") << endl;

    separator();
    cout << "9. Copy Constructor Test\n";

    HashMap<string,string> copyMap(map);

    cout << copyMap.get("key50") << endl;

    copyMap.set("key50", "MODIFIED");

    cout << "\nOriginal:\n";
    cout << map.get("key50") << endl;

    cout << "Copy:\n";
    cout << copyMap.get("key50") << endl;

    separator();
    cout << "10. Assignment Operator Test\n";

    HashMap<string,string> assignedMap;

    assignedMap = map;

    cout << assignedMap.get("key20") << endl;

    assignedMap.set("key20", "CHANGED");

    cout << "\nOriginal:\n";
    cout << map.get("key20") << endl;

    cout << "Assigned:\n";
    cout << assignedMap.get("key20") << endl;

    separator();
    cout << "11. Self Assignment Test\n";

    assignedMap = assignedMap;

    cout << assignedMap.get("key30") << endl;

    separator();
    cout << "12. int -> int Test\n";

    HashMap<int,int> intMap;

    intMap.set(1,100);
    intMap.set(2,200);
    intMap.set(3,300);

    cout << intMap.get(1) << endl;
    cout << intMap.get(2) << endl;
    cout << intMap.get(3) << endl;

    separator();
    cout << "13. int -> string Test\n";

    HashMap<int,string> intStringMap;

    intStringMap.set(1,"One");
    intStringMap.set(2,"Two");
    intStringMap.set(3,"Three");

    cout << intStringMap.get(1) << endl;
    cout << intStringMap.get(2) << endl;
    cout << intStringMap.get(3) << endl;

    separator();
    cout << "14. string -> int Test\n";

    HashMap<string,int> stringIntMap;

    stringIntMap.set("A",10);
    stringIntMap.set("B",20);
    stringIntMap.set("C",30);

    cout << stringIntMap.get("A") << endl;
    cout << stringIntMap.get("B") << endl;
    cout << stringIntMap.get("C") << endl;

    separator();
    cout << "15. Collision/Rehash Verification\n";

    HashMap<int,string> collisionMap;

    for(int i = 0; i < 500; i++) {

        collisionMap.set(
            i,
            "Value" + to_string(i)
        );
    }

    bool passed = true;

    for(int i = 0; i < 500; i++) {

        if(collisionMap.get(i)
           != "Value" + to_string(i)) {

            passed = false;
            break;
        }
    }

    cout << (passed ? "PASS" : "FAIL")
         << endl;

    separator();
    cout << "16. Large Stress Test\n";

    {
        HashMap<int,int> bigMap;

        for(int i = 0; i < 10000; i++) {
            bigMap.set(i, i * 10);
        }

        cout << "Size: "
             << bigMap.size()
             << endl;

        cout << "Value 9999: "
             << bigMap.get(9999)
             << endl;

        cout << "Load Factor: "
             << bigMap.loadFactor()
             << endl;
    }

    cout << "Large map destroyed successfully\n";

    separator();
    cout << "17. Scope Destruction Test\n";

    {
        HashMap<string,string> temp;

        temp.set("A","1");
        temp.set("B","2");
        temp.set("C","3");
    }

    cout << "Temporary map destroyed successfully\n";

    separator();
    cout << "ALL TESTS COMPLETED\n";

    return 0;
}