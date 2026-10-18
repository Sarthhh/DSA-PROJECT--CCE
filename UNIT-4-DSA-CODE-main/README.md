# Employee-ID-Directory-using-Threaded-Binary-Search-Tree

## Problem Statement
To design and implement a C++ based Employee ID Directory System using a Double Threaded Binary Search Tree. The system stores unique employee IDs in sorted order and allows traversal without recursion or a stack by using threads.

## Objective
To implement a Threaded Binary Search Tree for managing employee IDs and performing insertion, traversal, and predecessor/successor searching efficiently.

## Data Structure Used
- Binary Search Tree
- Double Threaded Binary Tree (threads on both left and right sides)

## Operations
1. Insert Employee ID
2. Inorder Traversal
3. Find Predecessor and Successor
4. Preorder Traversal
5. Exit

## Concepts Used
- C++
- Binary Search Tree
- Threaded Binary Tree
- Structures
- Pointers
- Dynamic Memory Allocation
- Inorder Predecessor and Successor
- Tree Traversals (Inorder and Preorder)

## Algorithm
1. Start the program.
2. Create an empty threaded binary search tree.
3. Insert a new employee ID at its correct position in the tree. If the ID already exists, display "Duplicate Employee ID!".
4. While inserting, set the new node's left and right threads to its inorder predecessor and successor, and update the parent's thread flag to a real child link.
5. Perform inorder traversal by starting at the leftmost node and repeatedly moving to the inorder successor using threads.
6. To find the predecessor and successor, search for the given employee ID and then use the threads or the rightmost/leftmost node of the subtree.
7. Perform preorder traversal by visiting the node and then following the left and right child links (not threads).
8. Repeat the operations until the user selects Exit.
9. Stop the program.

## Advantages
- Inorder traversal is done without recursion or an explicit stack.
- NULL pointers are reused as threads, so space is utilized efficiently.
- Predecessor and successor can be found quickly.
- Employee IDs are always kept in sorted order.
- Duplicate employee IDs are not allowed.
- Memory is allocated dynamically as new IDs are added.

## How to Run
```
g++ main.cpp -o directory
./directory
```
Sample run: see `output.txt`.

## Conclusion
The Employee ID Directory using a Double Threaded Binary Search Tree demonstrates how threads can make tree traversal faster and simpler in C++. It performs essential operations such as inserting employee IDs, inorder and preorder traversals, and finding the predecessor and successor of an ID. This project helps in understanding binary search trees, threaded binary trees, pointers, and dynamic memory allocation.
