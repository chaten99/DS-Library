#include <iostream>
#include "PriorityQueue.hpp"
using namespace std;

void testPriorityQueueMaxHeap(){
    cout << "===== Priority Queue Tests (Max Heap - std::less) =====\n\n";

    PriorityQueue<int> pq = {10, 30, 20, 50, 15};

    cout << "Max element (top): " << pq.top() << endl;
    cout << "Size: " << pq.size() << "\n\n";

    cout << "Extracting elements in priority order:\n";
    while (!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";
}

void testPriorityQueueMinHeap(){
    cout << "\n===== Priority Queue Tests (Min Heap - std::greater) =====\n\n";

    PriorityQueue<int, Vector<int>, std::greater<int>> pqMin = {10, 30, 20, 50, 15};

    cout << "Min element (top): " << pqMin.top() << endl;
    cout << "Size: " << pqMin.size() << "\n\n";

    cout << "Extracting elements in reverse priority order:\n";
    while (!pqMin.empty()){
        cout << pqMin.top() << " ";
        pqMin.pop();
    }
    cout << "\n";
}

void testPriorityQueueOperations(){
    cout << "\n===== Priority Queue Operations Tests =====\n\n";

    PriorityQueue<int> pq;

    cout << "Empty check (should be 1): " << pq.empty() << endl;

    pq.push(25);
    pq.push(10);
    pq.push(30);
    pq.push(5);
    pq.push(20);

    cout << "After pushing 25, 10, 30, 5, 20:\n";
    cout << "Top: " << pq.top() << endl;
    cout << "Size: " << pq.size() << endl;
    cout << "Empty check (should be 0): " << pq.empty() << "\n\n";

    cout << "Pop and display:\n";
    pq.pop();
    cout << "Top after pop: " << pq.top() << endl;
    cout << "Size after pop: " << pq.size() << "\n";
}

void testPriorityQueueString(){
    cout << "\n===== Priority Queue with Strings =====\n\n";

    PriorityQueue<string> pqStr = {"apple", "zebra", "banana", "orange"};

    cout << "String Priority Queue (max-heap by lexicographic order):\n";
    cout << "Top: " << pqStr.top() << "\n\n";

    cout << "Extracting in order:\n";
    while (!pqStr.empty()){
        cout << pqStr.top() << "\n";
        pqStr.pop();
    }
}

int main(){
    testPriorityQueueMaxHeap();
    testPriorityQueueMinHeap();
    testPriorityQueueOperations();
    testPriorityQueueString();
    return 0;
}
