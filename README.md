# Data Structure and Algorithm Practice

A collection of C++ implementations for learning core data structures,
algorithms, recursion, dynamic programming, graph traversal, expression
conversion, and object-oriented programming.

The programs are intentionally small and focused on one concept at a time.
Most files contain their own `main()` function and can be compiled
independently. The repository is suitable for classroom practice, algorithm
visualization, and experimenting with different implementation techniques.

## Topics

- Sorting and searching
- Dynamic programming and greedy algorithms
- Arrays and matrices
- Linked lists
- Stacks and queues
- Binary trees, BSTs, AVL trees, and heaps
- Graph representations and graph traversal
- Expression conversion and evaluation
- Recursion
- Structures, classes, and encapsulation
- A small university management system

## Compile and Run

Compile one source file from the repository root:

```bash
g++ -std=c++17 -Wall -Wextra "merge_sort.cpp" -o merge_sort
./merge_sort
```

For filenames containing spaces, keep the filename inside quotes:

```bash
g++ -std=c++17 -Wall -Wextra "Coin _Change.cpp" -o coin_change
./coin_change
```

Some programs use `#include <bits/stdc++.h>` and are therefore most
convenient to compile with GCC or MinGW. `ums.cpp` also uses `<conio.h>`,
which is primarily available in Windows-compatible environments.

## Source Guide

### Arrays and Matrices

#### [`2D_array.cpp`](<2D_array.cpp>)

Demonstrates a three-dimensional array used to store and search student
records. The dimensions represent a student index, an information field such
as name or ID, and a value such as a CGPA.

#### [`two_pointer.cpp`](<two_pointer.cpp>)

Demonstrates the two-pointer technique on an array. Two indices move through
the data to solve a pair-oriented problem more efficiently than checking
every possible pair.

---

### Searching and Sorting

#### [`Binary_search.cpp`](<Binary_search.cpp>)

Implements iterative and recursive binary search. The array must be sorted;
each comparison discards half of the remaining search interval, giving
`O(log n)` search time.

#### [`Bubble_insert_slection.cpp`](<Bubble_insert_slection.cpp>)

Contains bubble sort, selection sort, and insertion sort. It is useful for
comparing their loop structure and `O(n²)` average or worst-case behavior.

#### [`Bubble_sort_using_recursion.cpp`](<Bubble_sort_using_recursion.cpp>)

Implements bubble sort recursively. Each recursive call completes one pass,
placing the largest unsorted element at the end of the array.

#### [`MERGEsort.cpp`](<MERGEsort.cpp>)

Implements merge sort on a `vector<int>`. The array is divided into halves,
the halves are sorted recursively, and then merged in order.

#### [`merge_sort.cpp`](<merge_sort.cpp>)

Implements merge sort using a raw integer array and a separate merge function.

#### [`QuickSort.cpp`](<QuickSort.cpp>)

Implements quicksort using partitioning around a pivot and recursive sorting
of the resulting subarrays.

#### [`binary_search_merge_sort.cpp`](<binary_search_merge_sort.cpp>)

Combines merge sort and binary search: it sorts an array and then searches for
a target value in logarithmic time.

---

### Dynamic Programming and Greedy Algorithms

#### [`01_knapsack.cpp`](<01_knapsack.cpp>)

Solves the 0/1 knapsack problem, where each item can be selected once or
skipped to maximize value under a weight capacity.

#### [`factorial_Knapsack.cpp`](<factorial_Knapsack.cpp>)

Implements fractional knapsack. Items are ordered by value per unit weight,
and a fraction of the final item may be selected.

#### [`Coin _Change.cpp`](<Coin _Change.cpp>)

Provides a coin-change solution in online-judge style using a `Solution`
class.

#### [`coin_change_dp.cpp`](<coin_change_dp.cpp>)

Demonstrates a dynamic-programming approach to coin change by reusing results
for smaller amounts.

#### [`Factorial_using_dp.cpp`](<Factorial_using_dp.cpp>)

Calculates factorial values using stored subproblem results.

#### [`fibonacii_dp.cpp`](<fibonacii_dp.cpp>)

Builds Fibonacci numbers with dynamic programming so previous values are not
recalculated.

---

### Trees

#### [`BST.cpp`](<BST.cpp>)

Implements a binary search tree with insertion, in-order traversal, search,
and deletion.

#### [`binary_tree_traversal.cpp`](<binary_tree_traversal.cpp>)

Demonstrates in-order, pre-order, and post-order traversal of a binary tree.

#### [`avl_tree_insertion.cpp`](<avl_tree_insertion.cpp>)

Implements AVL insertion with height and balance-factor checks. LL, RR, LR,
and RL rotations keep the tree balanced.

#### [`lab_performace_02/Avl_tree.cpp`](<lab_performace_02/Avl_tree.cpp>)

An extended AVL implementation that includes insertion, deletion, height
updates, balance calculations, and rebalancing.

#### [`max_heap.cpp`](<max_heap.cpp>)

Implements a max heap using an array. Insertion uses upward heapification and
deletion uses downward heapification.

---

### Linked Lists

#### [`single_linked_list.cpp`](<single_linked_list.cpp>)

Implements a singly linked list with insertion at the front, tail, or a
position, display, counting, deletion, and updates.

#### [`linked_list_insertion.cpp`](<linked_list_insertion.cpp>)

Focuses on singly linked-list insertion at the head and tail, display, and
search operations.

#### [`linked_list_deletion.cpp`](<linked_list_deletion.cpp>)

Demonstrates singly linked-list deletion from the head and deletion by value,
along with insertion, display, and search helpers.

#### [`doubly_linked_list.cpp`](<doubly_linked_list.cpp>)

Implements a doubly linked list with insertion, deletion, display, and
reversal.

#### [`circular_single_linked_list.cpp`](<circular_single_linked_list.cpp>)

Implements a circular singly linked list using a tail pointer, including
position-based insertion and deletion.

#### [`circular_doubly_linked_lisr.cpp`](<circular_doubly_linked_lisr.cpp>)

Implements a circular doubly linked list with two-way traversal, insertion,
deletion, and updates.

---

### Stacks

#### [`stack_arr.cpp`](<stack_arr.cpp>)

Implements a fixed-size stack using an array with push, pop, peek, overflow,
underflow, and print operations.

#### [`stack_linked_list.cpp`](<stack_linked_list.cpp>)

Implements a stack using linked nodes, allowing the stack to grow without a
fixed array capacity.

#### [`stack_applicatn_brakets.cpp`](<stack_applicatn_brakets.cpp>)

Uses a stack to check whether brackets in an expression are balanced.

#### [`prefix_posfix_stack.cpp`](<prefix_posfix_stack.cpp>)

Evaluates prefix and postfix arithmetic expressions using a stack.

#### [`infixTOprefix.cpp`](<infixTOprefix.cpp>)

Converts an infix expression into prefix notation using operator precedence
and a stack.

#### [`infixToposfix.cpp`](<infixToposfix.cpp>)

Converts an infix expression into postfix, or Reverse Polish, notation.

#### [`stack_to_que_que_to_stack.cpp`](<stack_to_que_que_to_stack.cpp>)

Demonstrates how to implement a queue with stacks and a stack with queues.

---

### Queues

#### [`Q_arry_implecation.cpp`](<Q_arry_implecation.cpp>)

Implements a queue with an array and front/rear indexes.

#### [`Q_linkedLIst.cpp`](<Q_linkedLIst.cpp>)

Implements a queue using linked nodes, with removal from the front and
insertion at the rear.

#### [`circular_queue.cpp`](<circular_queue.cpp>)

Implements a circular array queue whose indexes wrap around to reuse freed
slots.

---

### Graphs

#### [`graph_representation_by_matrix.cpp`](<graph_representation_by_matrix.cpp>)

Represents a weighted graph with an adjacency matrix and demonstrates adding,
deleting, and displaying edges.

#### [`multistage_graph_sorthest_path.cpp`](<multistage_graph_sorthest_path.cpp>)

Calculates a shortest path in a multistage directed graph using dynamic
programming over its stages.

#### [`lab_performace_02/BFS.cpp`](<lab_performace_02/BFS.cpp>)

Implements breadth-first search with an adjacency matrix and an explicit
queue. Vertices are visited level by level.

#### [`lab_performace_02/DFS.cpp`](<lab_performace_02/DFS.cpp>)

Implements depth-first search with an adjacency matrix and an explicit stack.
It explores one branch before backtracking.

---

### Huffman Coding

#### [`Huffman_code.cpp`](<Huffman_code.cpp>)

Builds a Huffman tree from characters and frequencies using a min heap.
Frequent characters receive shorter prefix-free codes.

---

### Recursion

#### [`tower_of_hanoi_recursive.cpp`](<tower_of_hanoi_recursive.cpp>)

Solves the Tower of Hanoi puzzle recursively by moving a stack of disks from
source to destination using a helper peg.

---

### Structures, Classes, and Encapsulation

#### [`Structure.cpp`](<Structure.cpp>)

Demonstrates a `struct` representing a book and different ways to pass
structure data to functions.

#### [`nested_structure.cpp`](<nested_structure.cpp>)

Uses nested structures to model a student and related grade information.

#### [`class_and_object.cpp`](<class_and_object.cpp>)

Introduces a class-based bank-account example with member data and methods.

#### [`private_class.cpp`](<private_class.cpp>)

Demonstrates private class members and controlled access through public
methods, reinforcing encapsulation.

---

### University Management System

#### [`ums.cpp`](<ums.cpp>)

A menu-driven university management example combining a queue for student
registration, a binary search tree for course management, and a stack for
faculty management. It also demonstrates console login and menu navigation.

---

## Suggested Practice Order

1. Arrays, structures, and classes
2. Searching and elementary sorting
3. Recursion and dynamic programming
4. Stacks and queues
5. Linked lists
6. Binary trees, BSTs, AVL trees, and heaps
7. Graph representations and traversal
8. Huffman coding and the university management system

For each program, read the input section in `main()`, predict the output,
trace the data structure after each operation, and then modify the example
with your own values.

## Repository Files

- [`LICENSE`](LICENSE) — project license
- [`SECURITY.md`](SECURITY.md) — security policy and reporting guidance
