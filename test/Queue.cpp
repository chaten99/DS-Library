#include <iostream>
#include "Queue.hpp"
using namespace std;

void testQueue() {
    cout << "\nQUEUE TESTn";

    Queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl;

    q.pop();

    cout << "Front after pop: " << q.front() << endl;
}

int main() {
    testQueue();
    return 0;
}