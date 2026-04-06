#include <iostream>
#include "Queue.hpp"
using namespace std;

void testQueue() {
    cout << "===== Queue Tests =====\n\n";

    Queue<int> q = {10, 20, 30};

    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;

    q.pop();

    cout << "Front after pop: " << q.front() << endl;
    cout << "Size: " << q.size() << endl << "\n";

    cout << "All elements (dequeue): ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}

void testQueueAdvanced() {
    cout << "\n===== Queue Advanced Tests =====\n\n";

    Queue<string> qtext;
    qtext.push("first");
    qtext.push("second");
    qtext.push("third");

    cout << "String Queue - Dequeue in order:\n";
    while (!qtext.empty()) {
        cout << qtext.front() << "\n";
        qtext.pop();
    }
}

int main() {
    testQueue();
    testQueueAdvanced();
    return 0;
}