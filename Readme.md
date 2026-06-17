# 📚 DS-Library — Data Structures from Scratch in C++

A collection of fundamental data structures implemented from scratch in C++17, inspired by the C++ STL. No external dependencies — just pure, clean implementations that you can read, learn from, and use in your own projects.

> **Why this exists:** Instead of relying on `std::vector`, `std::map`, etc., this library implements them manually so you can understand how they actually work under the hood — memory management, pointer wrangling, heap operations, hashing, and all.

---

## 🗂️ What's Inside

| # | Data Structure | Header | Underlying Structure |
|---|---------------|--------|---------------------|
| 1 | [Vector](#1-vector) | `Vector.hpp` | Dynamic array |
| 2 | [List](#2-list) | `List.hpp` | Doubly linked list |
| 3 | [ForwardList](#3-forwardlist) | `ForwardList.hpp` | Singly linked list |
| 4 | [Deque](#4-deque) | `Deque.hpp` | Block-mapped array |
| 5 | [Stack](#5-stack) | `Stack.hpp` | Container adaptor (uses Deque) |
| 6 | [Queue](#6-queue) | `Queue.hpp` | Container adaptor (uses Deque) |
| 7 | [Priority Queue](#7-priority-queue) | `PriorityQueue.hpp` | Binary heap (uses Vector) |
| 8 | [HashMap](#8-hashmap) | `HashMap.hpp` | Hash table with chaining |
| 9 | [Tree (BST)](#9-tree-binary-search-tree) | `Tree.hpp` | Binary search tree |
| 10 | [Redis CLI](#10-redis-cli) | `RedisCLI.hpp` | Interactive key-value store (uses HashMap) |

---

## 📖 Data Structures in Detail

### 1. Vector

A dynamic array that automatically doubles in capacity when it runs out of space. Elements are stored contiguously in memory, which means great cache performance and O(1) random access.

**When to use:** You need fast access by index, or you mostly add/remove elements from the end.

#### API

| Method | What it Does |
|--------|-------------|
| `pushBack(val)` | Appends an element to the end |
| `popBack()` | Removes the last element |
| `insert(index, val)` | Inserts element at a specific position (shifts everything after it) |
| `remove(index)` | Removes element at a specific position (shifts everything after it) |
| `operator[index]` | Access element by index (no bounds check) |
| `at(index)` | Access element by index (with bounds check, throws on invalid) |
| `front()` | Returns reference to the first element |
| `back()` | Returns reference to the last element |
| `size()` | Returns the number of elements |
| `capacity()` | Returns the current allocated capacity |
| `empty()` | Returns `true` if the vector has no elements |
| `display()` | Prints all elements to stdout |

#### Time Complexity

| Operation | Best | Average | Worst |
|-----------|------|---------|-------|
| `pushBack` | O(1) | O(1) amortized | O(n) — when resizing |
| `popBack` | O(1) | O(1) | O(1) |
| `insert` | O(1) — at end | O(n) | O(n) — shifting elements |
| `remove` | O(1) — at end | O(n) | O(n) — shifting elements |
| `operator[]` / `at` | O(1) | O(1) | O(1) |
| `front` / `back` | O(1) | O(1) | O(1) |
| `size` / `empty` | O(1) | O(1) | O(1) |

**Space Complexity:** O(n)

#### Example

```cpp
#include "Vector.hpp"

Vector<int> v = {10, 20, 30};
v.pushBack(40);
v.insert(1, 15);           // v = {10, 15, 20, 30, 40}
std::cout << v[0];          // 10
std::cout << v.back();      // 40
v.popBack();
std::cout << v.size();      // 4
```

---

### 2. List

A doubly linked list — each node has a `prev` and `next` pointer. Insertions and deletions anywhere are O(1) once you have the position, but random access requires traversal.

**When to use:** You need to frequently insert or remove elements from the middle, front, or back.

#### API

| Method | What it Does |
|--------|-------------|
| `pushFront(val)` | Inserts element at the beginning |
| `pushBack(val)` | Inserts element at the end |
| `insert(index, val)` | Inserts element at a specific index |
| `popFront()` | Removes the first element |
| `popBack()` | Removes the last element |
| `front()` | Returns reference to the first element |
| `back()` | Returns reference to the last element |
| `at(index)` | Returns reference to element at index (traverses to it) |
| `search(val)` | Returns `true` if value exists in the list |
| `size()` | Returns the number of elements |
| `empty()` | Returns `true` if the list is empty |
| `clear()` | Removes all elements |
| `display()` | Prints all elements to stdout |

#### Time Complexity

| Operation | Best | Average | Worst |
|-----------|------|---------|-------|
| `pushFront` | O(1) | O(1) | O(1) |
| `pushBack` | O(1) | O(1) | O(1) |
| `insert` | O(1) — at head/tail | O(n) | O(n) — traversal to index |
| `popFront` | O(1) | O(1) | O(1) |
| `popBack` | O(1) | O(1) | O(1) |
| `front` / `back` | O(1) | O(1) | O(1) |
| `at(index)` | O(1) — index 0 | O(n) | O(n) |
| `search` | O(1) — found first | O(n) | O(n) |
| `size` / `empty` | O(1) | O(1) | O(1) |
| `clear` | O(n) | O(n) | O(n) |

**Space Complexity:** O(n) — each node stores data + two pointers

#### Example

```cpp
#include "List.hpp"

List<int> l = {1, 2, 3};
l.pushFront(0);              // l = {0, 1, 2, 3}
l.pushBack(4);               // l = {0, 1, 2, 3, 4}
std::cout << l.front();      // 0
std::cout << l.back();       // 4
l.popFront();
std::cout << l.size();       // 4
```

---

### 3. ForwardList

A singly linked list — each node only has a `next` pointer (no `prev`). Uses less memory per node than `List`, but you can only traverse forward.

**When to use:** Memory is tight, you only traverse forward, and you mostly insert/remove at the front.

#### API

| Method | What it Does |
|--------|-------------|
| `pushFront(val)` | Inserts element at the beginning |
| `popFront()` | Removes the first element |
| `insert(index, val)` | Inserts element at a specific index |
| `front()` | Returns reference to the first element |
| `search(val)` | Returns `true` if value exists |
| `size()` | Returns the number of elements |
| `empty()` | Returns `true` if the list is empty |
| `clear()` | Removes all elements |
| `display()` | Prints all elements to stdout |

#### Time Complexity

| Operation | Best | Average | Worst |
|-----------|------|---------|-------|
| `pushFront` | O(1) | O(1) | O(1) |
| `popFront` | O(1) | O(1) | O(1) |
| `insert` | O(1) — at head | O(n) | O(n) — traversal to index |
| `front` | O(1) | O(1) | O(1) |
| `search` | O(1) — found first | O(n) | O(n) |
| `size` / `empty` | O(1) | O(1) | O(1) |
| `clear` | O(n) | O(n) | O(n) |

**Space Complexity:** O(n) — each node stores data + one pointer

#### Example

```cpp
#include "ForwardList.hpp"

ForwardList<int> fl = {10, 20, 30};
fl.pushFront(5);                // fl = {5, 10, 20, 30}
std::cout << fl.front();        // 5
fl.popFront();
std::cout << fl.size();         // 3
```

---

### 4. Deque

A double-ended queue backed by a block-mapped array (array of fixed-size blocks). Supports efficient push/pop from both front and back, plus random access by index.

**When to use:** You need fast insertions/removals at both ends, AND random access.

#### API

| Method | What it Does |
|--------|-------------|
| `pushFront(val)` | Inserts element at the front |
| `pushBack(val)` | Inserts element at the back |
| `popFront()` | Removes element from the front |
| `popBack()` | Removes element from the back |
| `front()` | Returns reference to the first element |
| `back()` | Returns reference to the last element |
| `operator[index]` | Random access by index |
| `size()` | Returns the number of elements |
| `empty()` | Returns `true` if the deque is empty |
| `display()` | Prints all elements to stdout |

#### Time Complexity

| Operation | Best | Average | Worst |
|-----------|------|---------|-------|
| `pushFront` | O(1) | O(1) amortized | O(n) — when map reallocates |
| `pushBack` | O(1) | O(1) amortized | O(n) — when map reallocates |
| `popFront` | O(1) | O(1) | O(1) |
| `popBack` | O(1) | O(1) | O(1) |
| `front` / `back` | O(1) | O(1) | O(1) |
| `operator[]` | O(1) | O(1) | O(1) |
| `size` / `empty` | O(1) | O(1) | O(1) |

**Space Complexity:** O(n)

#### Example

```cpp
#include "Deque.hpp"

Deque<int> d;
d.pushBack(10);
d.pushFront(5);
d.pushBack(20);
std::cout << d.front();    // 5
std::cout << d.back();     // 20
std::cout << d[1];         // 10
```

---

### 5. Stack

A **LIFO** (Last-In, First-Out) container adaptor. Internally uses `Deque` by default, but you can swap in any container that supports `pushBack`, `popBack`, `back`, `size`, and `empty`.

**When to use:** Undo/redo systems, expression evaluation, backtracking, DFS.

#### API

| Method | What it Does |
|--------|-------------|
| `push(val)` | Pushes element onto the top |
| `pop()` | Removes the top element |
| `top()` | Returns reference to the top element |
| `size()` | Returns the number of elements |
| `empty()` | Returns `true` if stack is empty |
| `display()` | Prints all elements to stdout |

#### Time Complexity

| Operation | Best | Average | Worst |
|-----------|------|---------|-------|
| `push` | O(1) | O(1) | O(1) amortized |
| `pop` | O(1) | O(1) | O(1) |
| `top` | O(1) | O(1) | O(1) |
| `size` / `empty` | O(1) | O(1) | O(1) |

**Space Complexity:** O(n)

#### Example

```cpp
#include "Stack.hpp"

Stack<int> s;
s.push(1);
s.push(2);
s.push(3);
std::cout << s.top();    // 3
s.pop();
std::cout << s.top();    // 2
```

---

### 6. Queue

A **FIFO** (First-In, First-Out) container adaptor. Internally uses `Deque` by default.

**When to use:** Task scheduling, BFS, request processing, print queues.

#### API

| Method | What it Does |
|--------|-------------|
| `push(val)` | Adds element to the back |
| `pop()` | Removes element from the front |
| `front()` | Returns reference to the front element |
| `back()` | Returns reference to the back element |
| `size()` | Returns the number of elements |
| `empty()` | Returns `true` if queue is empty |
| `display()` | Prints all elements to stdout |

#### Time Complexity

| Operation | Best | Average | Worst |
|-----------|------|---------|-------|
| `push` | O(1) | O(1) | O(1) amortized |
| `pop` | O(1) | O(1) | O(1) |
| `front` / `back` | O(1) | O(1) | O(1) |
| `size` / `empty` | O(1) | O(1) | O(1) |

**Space Complexity:** O(n)

#### Example

```cpp
#include "Queue.hpp"

Queue<int> q = {10, 20, 30};
std::cout << q.front();    // 10
q.pop();
std::cout << q.front();    // 20
```

---

### 7. Priority Queue

A max-heap (by default) built on top of `Vector`. The highest priority element is always at the top. Supports custom comparators for min-heap or any other ordering.

**When to use:** Dijkstra's algorithm, task scheduling with priorities, median finding, heap sort.

#### API

| Method | What it Does |
|--------|-------------|
| `push(val)` | Inserts element and restores heap property (bubble up) |
| `pop()` | Removes the highest priority element (heapify down) |
| `top()` | Returns reference to the highest priority element |
| `size()` | Returns the number of elements |
| `empty()` | Returns `true` if the heap is empty |
| `heapify(index)` | Restores heap property starting from given index |

#### Time Complexity

| Operation | Best | Average | Worst |
|-----------|------|---------|-------|
| `push` | O(1) — already in order | O(log n) | O(log n) |
| `pop` | O(log n) | O(log n) | O(log n) |
| `top` | O(1) | O(1) | O(1) |
| `heapify` | O(1) — already a heap | O(log n) | O(log n) |
| `size` / `empty` | O(1) | O(1) | O(1) |
| Build from list | — | O(n) | O(n) |

**Space Complexity:** O(n)

#### Max-Heap vs Min-Heap

```cpp
#include "PriorityQueue.hpp"

// Max-heap (default) — largest element on top
PriorityQueue<int> maxPQ = {10, 30, 20, 50, 15};
std::cout << maxPQ.top();    // 50

// Min-heap — smallest element on top
PriorityQueue<int, Vector<int>, std::greater<int>> minPQ;
minPQ.push(10);
minPQ.push(5);
minPQ.push(20);
std::cout << minPQ.top();    // 5
```

---

### 8. HashMap

A hash table using **separate chaining** (linked lists at each bucket) for collision resolution. Automatically rehashes when the load factor gets too high.

**When to use:** Fast key-value lookups, counting frequencies, caching, building indexes.

#### API

| Method | What it Does |
|--------|-------------|
| `set(key, value)` | Inserts or updates a key-value pair |
| `get(key)` | Returns the value for a key (throws if not found) |
| `exists(key)` | Returns `true` if the key exists |
| `remove(key)` | Deletes a key-value pair |
| `size()` | Returns the number of stored pairs |
| `empty()` | Returns `true` if the map is empty |
| `loadFactor()` | Returns `elementCount / bucketCount` (as a float) |
| `clear()` | Removes all key-value pairs |
| `display()` | Prints all buckets and their contents |

#### Time Complexity

| Operation | Best | Average | Worst |
|-----------|------|---------|-------|
| `set` | O(1) | O(1) | O(n) — all keys hash to same bucket |
| `get` | O(1) | O(1) | O(n) — all keys in one chain |
| `exists` | O(1) | O(1) | O(n) |
| `remove` | O(1) | O(1) | O(n) |
| `loadFactor` | O(1) | O(1) | O(1) |
| `size` / `empty` | O(1) | O(1) | O(1) |
| `clear` | O(n + b) | O(n + b) | O(n + b) — n = elements, b = buckets |
| `rehash` (internal) | O(n) | O(n) | O(n) |

**Space Complexity:** O(n + b) — n elements across b buckets

#### Example

```cpp
#include "HashMap.hpp"

HashMap<std::string, int> map;
map.set("alice", 95);
map.set("bob", 87);
std::cout << map.get("alice");      // 95
std::cout << map.exists("bob");     // 1 (true)
map.remove("bob");
std::cout << map.size();            // 1
```

---

### 9. Tree (Binary Search Tree)

A standard BST where the left child is always smaller and the right child is always larger than the parent. Supports 5 different traversal methods, including **Morris In-Order Traversal** which uses O(1) extra space.

**When to use:** Sorted data storage, range queries, in-order processing.

#### API

| Method | What it Does |
|--------|-------------|
| `insert(val)` | Inserts a value into the BST |
| `remove(val)` | Removes a value from the BST |
| `search(val)` | Returns `true` if value exists |
| `contains(val)` | Alias for `search` |
| `inOrderTraversal()` | Returns vector of elements: Left → Root → Right (sorted order) |
| `preOrderTraversal()` | Returns vector of elements: Root → Left → Right |
| `postOrderTraversal()` | Returns vector of elements: Left → Right → Root |
| `levelOrderTraversal()` | Returns vector of elements level by level (BFS) |
| `morrisInOrderTraversal()` | Returns in-order vector using O(1) extra space |
| `displayInOrder()` | Prints in-order traversal |
| `displayPreOrder()` | Prints pre-order traversal |
| `displayPostOrder()` | Prints post-order traversal |
| `displayLevelOrder()` | Prints level-order traversal |
| `displayMorrisInOrder()` | Prints Morris in-order traversal |
| `size()` | Returns the number of nodes |
| `isEmpty()` | Returns `true` if tree has no nodes |

#### Time Complexity

| Operation | Best | Average | Worst (skewed tree) |
|-----------|------|---------|---------------------|
| `insert` | O(log n) | O(log n) | O(n) |
| `remove` | O(log n) | O(log n) | O(n) |
| `search` / `contains` | O(1) — root match | O(log n) | O(n) |
| `inOrderTraversal` | O(n) | O(n) | O(n) |
| `preOrderTraversal` | O(n) | O(n) | O(n) |
| `postOrderTraversal` | O(n) | O(n) | O(n) |
| `levelOrderTraversal` | O(n) | O(n) | O(n) |
| `morrisInOrderTraversal` | O(n) | O(n) | O(n) |
| `size` / `isEmpty` | O(1) | O(1) | O(1) |

> **Note:** Worst-case O(n) happens when the tree degenerates into a linked list (e.g., inserting already sorted data). A self-balancing tree (AVL, Red-Black) would guarantee O(log n), but this is a plain BST.

**Space Complexity:**
- Tree itself: O(n)
- Recursive traversals: O(h) stack space where h = height
- Morris traversal: O(1) extra space (modifies and restores pointers temporarily)

#### Example

```cpp
#include "Tree.hpp"

Tree<int> bst;
bst.insert(50);
bst.insert(30);
bst.insert(70);
bst.insert(20);
bst.insert(40);

bst.displayInOrder();        // 20 30 40 50 70
std::cout << bst.search(30); // 1 (true)
bst.remove(30);
bst.displayInOrder();        // 20 40 50 70
```

---

### 10. Redis CLI

A **mini Redis-like command-line interface** built on top of the `HashMap`. It's an interactive REPL that lets you store, retrieve, and manage string key-value pairs using familiar Redis-style commands.

This is a practical demo showing the HashMap in action — you type commands, it responds.

#### Supported Commands

| Command | Usage | What it Does |
|---------|-------|-------------|
| `SET` | `SET <key> <value>` | Stores a key-value pair (overwrites if key exists) |
| `GET` | `GET <key>` | Retrieves the value for a key (prints "Not Found" if missing) |
| `DEL` | `DEL <key>` | Deletes a key-value pair |
| `EXISTS` | `EXISTS <key>` | Checks if a key exists (prints "true" or "false") |
| `COUNT` | `COUNT` | Prints the total number of stored pairs |
| `CLEAR` | `CLEAR` | Deletes all stored data |
| `EXIT` | `EXIT` | Quits the Redis CLI |

#### Example Session

```
Redis Lite Started
Type 'EXIT' to quit
redis> SET name Chaten
OK
redis> SET lang C++
OK
redis> GET name
Chaten
redis> EXISTS lang
true
redis> COUNT
2
redis> DEL name
Deleted
redis> GET name
Not Found
redis> CLEAR
Cleared
redis> COUNT
0
redis> EXIT
Exiting Redis Lite.
```

---

## 📊 Time Complexity Cheat Sheet

A quick-reference table comparing all data structures side-by-side:

| Operation | Vector | List | ForwardList | Deque | Stack | Queue | Priority Queue | HashMap | BST (avg) | BST (worst) |
|-----------|--------|------|-------------|-------|-------|-------|---------------|---------|-----------|-------------|
| Insert (front) | O(n) | O(1) | O(1) | O(1)* | — | — | — | — | — | — |
| Insert (back) | O(1)* | O(1) | — | O(1)* | O(1)* | O(1)* | O(log n) | — | — | — |
| Insert (middle) | O(n) | O(n) | O(n) | — | — | — | — | — | O(log n) | O(n) |
| Remove (front) | O(n) | O(1) | O(1) | O(1) | — | O(1) | — | — | — | — |
| Remove (back) | O(1) | O(1) | — | O(1) | O(1) | — | — | — | — | — |
| Remove (arbitrary) | O(n) | O(n) | O(n) | — | — | — | O(log n) | O(1) avg | O(log n) | O(n) |
| Access (by index) | O(1) | O(n) | O(n) | O(1) | — | — | — | — | — | — |
| Access (front/top) | O(1) | O(1) | O(1) | O(1) | O(1) | O(1) | O(1) | — | — | — |
| Search | O(n) | O(n) | O(n) | O(n) | — | — | — | O(1) avg | O(log n) | O(n) |
| Space | O(n) | O(n) | O(n) | O(n) | O(n) | O(n) | O(n) | O(n+b) | O(n) | O(n) |

> `*` = amortized, `—` = not supported / not applicable

---

## 🔧 Building the Project

### Prerequisites

- A C++17 compiler (g++, clang++, or MSVC)
- CMake 3.20 or higher

### Build Steps

```bash
# 1. Create and enter the build directory
mkdir build
cd build

# 2. Generate the build files
cmake ..

# 3. Build everything
cmake --build .
```

On Linux/Mac you can also just run `make` after step 2.

---

## 🧪 Running Tests

Each data structure has its own test executable:

```bash
./Vector-Test
./List-Test
./ForwardList-Test
./Deque-Test
./Stack-Test
./Queue-Test
./PriorityQueue-Test
./Tree-Test
./HashMap-Test
./RedisCLI-Test
```

Each test covers basic operations and edge cases (empty container access, boundary conditions, etc.).

---

## 📁 Project Structure

```
DS-Library/
├── include/                # Header files (class declarations)
│   ├── Vector.hpp
│   ├── List.hpp
│   ├── ForwardList.hpp
│   ├── Deque.hpp
│   ├── Stack.hpp
│   ├── Queue.hpp
│   ├── PriorityQueue.hpp
│   ├── HashMap.hpp
│   ├── Tree.hpp
│   └── RedisCLI.hpp
├── src/                    # Implementation files (template definitions)
│   ├── Vector.cpp
│   ├── List.cpp
│   ├── ForwardList.cpp
│   ├── Deque.cpp
│   ├── Stack.cpp
│   ├── Queue.cpp
│   ├── PriorityQueue.cpp
│   ├── HashMap.cpp
│   ├── Tree.cpp
│   └── RedisCLI.cpp
├── test/                   # Test files for each data structure
│   ├── Vector.cpp
│   ├── List.cpp
│   ├── ForwardList.cpp
│   ├── Deque.cpp
│   ├── Stack.cpp
│   ├── Queue.cpp
│   ├── PriorityQueue.cpp
│   ├── HashMap.cpp
│   ├── Tree.cpp
│   └── RedisCLI.cpp
├── CMakeLists.txt          # CMake build configuration
└── Readme.md               # You're reading it
```

---

## ✅ Features

- **Template-based** — Works with any data type (`int`, `float`, `std::string`, custom classes, you name it)
- **STL-style API** — If you know the STL, you already know how to use this
- **Container adaptors** — Stack and Queue are adaptors over Deque (swappable underlying container)
- **Custom comparators** — Priority Queue supports `std::less`, `std::greater`, or your own functor
- **Automatic rehashing** — HashMap grows its bucket array when load factor gets too high
- **Morris traversal** — BST supports O(1) space in-order traversal
- **Error handling** — Throws exceptions for invalid operations (empty pops, out-of-bounds access, missing keys)
- **Redis CLI** — A working interactive demo built entirely on the HashMap
- **Well-tested** — Separate test files for every data structure

---

## 📝 Notes

- All containers use `nullptr` and modern C++17 features
- Template implementations are `#include`d from headers (since templates can't be separately compiled in the traditional sense)
- The BST is **not** self-balancing — worst-case performance degrades to O(n) on sorted input
- Stack defaults to `Deque<T>` internally, Queue also defaults to `Deque<T>`
- Priority Queue defaults to `Vector<T>` as its backing container with `std::less<T>` as the comparator (max-heap)
