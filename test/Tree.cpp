#include <iostream>
#include "Tree.hpp"
using namespace std;

void testTree() {
    cout << "===== Tree Data Structure Tests =====\n\n";

    Tree<int> tree;

    cout << "--- Test 1: Inserting elements ---\n";
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inserted: 50, 30, 70, 20, 40, 60, 80\n";
    cout << "Tree size: " << tree.size() << "\n\n";

    cout << "--- Test 2: All Traversals ---\n";
    tree.displayInOrder();
    tree.displayPreOrder();
    tree.displayPostOrder();
    tree.displayLevelOrder();
    tree.displayMorrisInOrder();
    cout << "\n";

    cout << "--- Test 3: Search Operations ---\n";
    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found") << "\n";
    cout << "Search 100: " << (tree.search(100) ? "Found" : "Not Found") << "\n";
    cout << "Contains 70: " << (tree.contains(70) ? "Yes" : "No") << "\n\n";

    cout << "--- Test 4: Using STL-style Iterator ---\n";
    cout << "Range-based for (in-order): ";
    for (int x : tree) {
        cout << x << " ";
    }
    cout << "\n";

    cout << "Manual iterator: ";
    auto it = tree.begin();
    auto end = tree.end();
    while (it != end) {
        cout << *it << " ";
        ++it;
    }
    cout << "\n\n";

    cout << "--- Test 5: Deleting Elements ---\n";
    cout << "Deleting 20 (leaf node)\n";
    tree.remove(20);
    tree.displayInOrder();

    cout << "Deleting 30 (node with one child)\n";
    tree.remove(30);
    tree.displayInOrder();

    cout << "Deleting 50 (root node with two children)\n";
    tree.remove(50);
    tree.displayInOrder();
    cout << "Tree size after deletions: " << tree.size() << "\n\n";

    cout << "--- Test 6: String Tree ---\n";
    Tree<string> strTree;
    strTree.insert("dog");
    strTree.insert("cat");
    strTree.insert("elephant");
    strTree.insert("ant");
    strTree.insert("bear");

    cout << "String tree insertions: dog, cat, elephant, ant, bear\n";
    strTree.displayInOrder();
    strTree.displayPreOrder();
    cout << "Search 'cat': " << (strTree.search("cat") ? "Found" : "Not Found") << "\n\n";

    cout << "--- Test 7: Empty Tree Check ---\n";
    Tree<int> emptyTree;
    cout << "Empty tree status: " << (emptyTree.isEmpty() ? "Empty" : "Not Empty") << "\n";
    cout << "Empty tree size: " << emptyTree.size() << "\n";
}

int main() {
    testTree();
    return 0;
}
