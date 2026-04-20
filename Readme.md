# Data Structures Library (C++ STL-Inspired)

A comprehensive C++ library implementing fundamental data structures from scratch, designed similarly to the C++ Standard Template Library (STL). This project is perfect for learning how these structures work internally or for use in projects where you need custom implementations.

## Table of Contents

- [Available Data Structures](#available-data-structures)
- [Building the Project](#building-the-project)
- [Running Tests](#running-tests)
- [Usage Examples](#usage-examples)
- [Features](#features)

## Available Data Structures

### 1. **Vector**

A dynamic, resizable array that grows automatically as you add elements.

**Best for:** Random access, storing sequences where you mostly add/remove from the end.

**Main Operations:**

- `pushBack(value)` - Add element to the end
- `popBack()` - Remove element from the end
- `operator[index]` or `at(index)` - Access element by position
- `front()` - Get first element
- `back()` - Get last element
- `size()` - Get number of elements
- `empty()` - Check if empty

**Iterator Support:** Supports range-based for loops and manual iteration.

---

### 2. **List**

A doubly-linked list where each element points to the next and previous elements.

**Best for:** Frequent insertions and deletions from any position in the list.

**Main Operations:**

- `pushBack(value)` - Add to end
- `popBack()` - Remove from end
- `pushFront(value)` - Add to beginning
- `popFront()` - Remove from beginning
- `front()` - Get first element
- `back()` - Get last element
- `size()` - Get number of elements
- `empty()` - Check if empty

---

### 3. **ForwardList**

A singly-linked list where each element only points to the next element (uses less memory).

**Best for:** Space-constrained applications where you only need forward iteration.

**Main Operations:**

- `pushFront(value)` - Add to beginning
- `popFront()` - Remove from beginning
- `insertAfter(index, value)` - Insert after a specific position
- `eraseAfter(index)` - Remove element after a position
- `front()` - Get first element
- `size()` - Get number of elements

---

### 4. **Deque (Double-Ended Queue)**

A queue that efficiently supports adding and removing from both ends.

**Best for:** Situations where you need fast operations at both the front and back.

**Main Operations:**

- `pushFront(value)` - Add to front
- `pushBack(value)` - Add to back
- `popFront()` - Remove from front
- `popBack()` - Remove from back
- `front()` - Access first element
- `back()` - Access last element
- `operator[index]` - Random access
- `size()` - Get number of elements

---

### 5. **Stack**

A Last-In-First-Out (LIFO) container. Think of it like a stack of plates—you add and remove from the top.

**Best for:** Undo/redo functionality, backtracking, function call management.

**Main Operations:**

- `push(value)` - Add element to top
- `pop()` - Remove element from top
- `top()` - View top element
- `size()` - Get number of elements
- `empty()` - Check if empty

---

### 6. **Queue**

A First-In-First-Out (FIFO) container. Think of it like a line at a store—first person in is first person out.

**Best for:** Task scheduling, breadth-first search, processing requests in order.

**Main Operations:**

- `push(value)` - Add element to back
- `pop()` - Remove element from front
- `front()` - View first element
- `back()` - View last element
- `size()` - Get number of elements
- `empty()` - Check if empty

---

### 7. **Priority Queue**

A special queue where elements are processed based on priority, not insertion order. Higher priority elements come out first.

**Best for:** Task scheduling with priorities, Dijkstra's algorithm, heap sort.

**Main Operations:**

- `push(value)` - Add element (automatically maintains heap structure)
- `pop()` - Remove highest priority element
- `top()` - View highest priority element
- `size()` - Get number of elements
- `empty()` - Check if empty

**Customization:**

- Use `std::less<T>` (default) for max-heap: largest element has highest priority
- Use `std::greater<T>` for min-heap: smallest element has highest priority
- Custom comparators supported

**Example:**

```cpp
PriorityQueue<int> pq;  // Max heap (default)
pq.push(10);
pq.push(20);
pq.push(5);
cout << pq.top();  // Outputs: 20

PriorityQueue<int, Vector<int>, std::greater<int>> minPq;  // Min heap
minPq.push(10);
minPq.push(20);
minPq.push(5);
cout << minPq.top();  // Outputs: 5
```

---

### 8. **Tree**

A tree data structure for hierarchical organization of data.

**Best for:** Representing hierarchies, binary search trees, expression trees.

**Main Operations:**

- Tree traversal and manipulation methods
- Hierarchical data storage

## Building the Project

### Prerequisites

- C++ compiler with C++17 support (g++, clang, MSVC)
- CMake (version 3.4 or higher)

### Build Instructions

1. Clone or download the project
2. Create a build directory:

   ```bash
   mkdir build
   cd build
   ```

3. Run CMake:

   ```bash
   cmake ..
   ```

4. Build the project:
   ```bash
   cmake --build .
   ```

Or on Linux/Mac:

```bash
make
```

## Running Tests

After building, run individual tests to verify each data structure:

```bash
./Vector-Test
./List-Test
./ForwardList-Test
./Deque-Test
./Stack-Test
./Queue-Test
./Tree-Test
./PriorityQueue-Test
```

Each test file demonstrates basic operations and edge cases for its respective data structure.

## Usage Examples

### Vector Example

```cpp
#include "Vector.hpp"

Vector<int> v = {10, 20, 30};
v.pushBack(40);
cout << v[0];        // Outputs: 10
cout << v.back();    // Outputs: 40
v.popBack();
cout << v.size();    // Outputs: 3
```

### Stack Example

```cpp
#include "Stack.hpp"

Stack<int> s;
s.push(1);
s.push(2);
s.push(3);
cout << s.top();  // Outputs: 3
s.pop();
cout << s.top();  // Outputs: 2
```

### Queue Example

```cpp
#include "Queue.hpp"

Queue<int> q = {10, 20, 30};
cout << q.front();  // Outputs: 10
q.pop();
cout << q.front();  // Outputs: 20
```

### Priority Queue Example

```cpp
#include "PriorityQueue.hpp"

PriorityQueue<int> pq = {10, 30, 20, 50, 15};
cout << pq.top();   // Outputs: 50 (highest priority)
pq.pop();
cout << pq.top();   // Outputs: 30
```

## Features

✅ **Template-Based:** Works with any data type (int, float, string, custom classes, etc.)

✅ **STL-Compatible Design:** Similar interfaces to standard C++ containers

✅ **Efficient:** Optimized implementations with appropriate time/space complexities

✅ **Safe:** Error handling for empty containers and invalid operations

✅ **Well-Tested:** Comprehensive test suite for each data structure

✅ **Educational:** Clean, readable code perfect for learning how data structures work

✅ **Customizable:** Priority Queue supports custom comparison functions

## Project Structure

```
.
├── include/          # Header files (.hpp)
├── src/              # Implementation files (.cpp)
├── test/             # Test files for each data structure
├── CMakeLists.txt    # Build configuration
└── Readme.md         # This file
```

## Notes

- All containers are template-based for type flexibility
- Implementations follow C++ best practices and STL conventions
- Error handling includes exceptions for invalid operations (e.g., accessing empty containers)
- The library is header-included for template instantiation
- Remove from front: `dequeue()`
- Look at front: `front()`

### 7. Tree (Binary Search Tree)

A tree structure where left child is smaller, right child is larger. Used for fast searching and sorting.

#### Features:

- **Insert**: Add elements maintaining tree order
- **Delete**: Remove elements while keeping tree structure
- **Search**: Find elements quickly
- **Five Traversal Methods**:
  - **In-order**: Left → Root → Right (gives sorted order)
  - **Pre-order**: Root → Left → Right (root first)
  - **Post-order**: Left → Right → Root (root last)
  - **Level-order**: Top to bottom, left to right (breadth-first)
  - **Morris In-order**: In-order with no extra stack, O(1) memory

#### Methods:

- `insert(value)` - Add element
- `remove(value)` - Delete element
- `search(value)` or `contains(value)` - Find element
- `inOrderTraversal()` - Return in-order list
- `preOrderTraversal()` - Return pre-order list
- `postOrderTraversal()` - Return post-order list
- `levelOrderTraversal()` - Return level-order list
- `morrisInOrderTraversal()` - Return in-order using Morris method
- `displayInOrder()` - Print in-order
- `displayPreOrder()` - Print pre-order
- `displayPostOrder()` - Print post-order
- `displayLevelOrder()` - Print level-order
- `displayMorrisInOrder()` - Print Morris in-order
- `size()` - Get number of elements
- `isEmpty()` - Check if tree is empty

#### Iterator:

Use `TreeIterator<T>` to walk through tree in sorted order.

## How to Build and Run

### Build all:

```bash
mkdir build
cd build
cmake ..
make
```

### Run individual tests:

```bash
./Vector-Test
./List-Test
./ForwardList-Test
./Deque-Test
./Stack-Test
./Queue-Test
./Tree-Test
```

## File Structure

- `include/` - Header files for all containers
- `src/` - Implementation files (templates included)
- `test/` - Test files for each container

## Notes

- All containers are templates - work with any data type
- Implementation uses `nullptr` and modern C++17 standards
- Each container has basic tests showing how to use it
