# Data Structure Library (Inspired by STL)

A C++ library with basic data structures and containers similar to the Standard Template Library.

## Containers Included

### 1. Vector
A dynamic array that can change size. Elements stored in order, accessed by position.
- Insert at end: `pushBack()`
- Remove from end: `popBack()`
- Get by index: `operator[]` or `at()`
- Get first/last: `front()` or `back()`

#### Iterator:
Use `VectorIterator<T>` to walk through vector sequentially.
- `hasNext()` - Check if more elements exist
- `next()` - Get next element value
- `nextRef()` - Get reference to next element (for modification)
- `reset()` - Go back to start
- `getCurrentIndex()` - Know which position you are at

### 2. List
A linked list where elements are connected by pointers. Good for adding/removing from anywhere.
- Insert at end: `pushBack()`
- Remove from end: `popBack()`
- Insert at start: `pushFront()`
- Remove from start: `popFront()`

### 3. ForwardList
A simpler linked list with one direction only. Uses less memory.
- Insert at start: `pushFront()`
- Remove from start: `popFront()`
- Insert after position: `insertAfter()`
- Remove after position: `eraseAfter()`

### 4. Deque
A double-ended queue. Add/remove from both front and back efficiently.
- Add at front/back: `pushFront()` or `pushBack()`
- Remove from front/back: `popFront()` or `popBack()`
- Access by index: `operator[]` or `at()`

### 5. Stack
Last-in, first-out (LIFO). Like a pile of plates - you use the top one first.
- Add to top: `push()`
- Remove from top: `pop()`
- Look at top: `top()`

### 6. Queue
First-in, first-out (FIFO). Like a line - first person in is first person out.
- Add to back: `enqueue()`
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
