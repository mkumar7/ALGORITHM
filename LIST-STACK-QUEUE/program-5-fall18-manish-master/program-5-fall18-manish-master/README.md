# CS580u Programming and System Tools
## Fall 2018
### PROGRAM 5 README FILE

Group member:

mkumar7
YANKUNCHEN1

## KNOWN BUGS AND INCOMPLETE PARTS:
- What parts of the program you were not able to complete

## REFERENCES:
- List any outside resources used

## MISCELLANEOUS COMMENTS:
- Anything you would like the grader to know

# Assignment Description
## Program 5 - Sequential Collections
### Due Date: 5:00 p.m., December 7th, 2018

*All programs will be tested on the machines in the Q22 lab. If your code does not run on the system in this lab, it is considered non-functioning EVEN IF IT RUNS ON YOUR PERSONAL COMPUTER. Always check that your code runs on the lab machines before submitting.*

### Driver Code and Test Files

* program5.c
    * include the driver code with your submission, but do not alter it, except where specified by comments
* profile.c/.h

### Grading Rubric

**_TOTAL: 55 points_**

* **Part A** (10 points): Vectors
    * [2 pts] Test 1 Passed: newVector function creates a vector with properly initialized values
    * [2 pts] Test 2-4 Passed: inserting into the vector passes all tests
    * [2 pts] Test 5-7 Passed: reading from vector passes all tests
    * [2 pts] Test 8-9 Passed: removing from vector passes tests
    * [2 pts] Test 10 Passed:  deleting vector does not result in memory leak
* **Part B** (10 points): Lists
    * [2 pts] Test 11 Passed: newList function creates a list with properly initialized values
    * [2 pts] Test 12 Passed: inserting into list at index passes test
    * [2 pts] Test 13 Passed: reading from list at index passes test
    * [4 pts] Test 14 Passed: removing and deleting from list at index passes test
* **Part C** (30 points): Stacks and Queues
    * [2 pts] Test 15 Passed: create Stackvector and Stacklist without error
    * [2 pts] Test 16 Passed: push onto Stackvector and Stacklist
    * [2 pts] Test 17 Passed: pop from Stackvector and Stacklist
    * [4 pts] Test 18 Passed: peek Stackvector and Stacklist
    * [2 pts] Test 19 Passed: clear Stackvector and Stacklist
    * [2 pts] Test 20 Passed: delete Stackvector and Stacklist without error
    * [2 pts] Test 21 Passed: create Queuevector and Queuelist without error
    * [4 pts] Test 22 Passed: enqueue into Queuevector and Queuelist
    * [2 pts] Test 23 Passed: dequeue from Queuevector and Queuelist
    * [2 pts] Test 24 Passed: peek onto Queuevector and Queuelist
    * [2 pts] Test 25 Passed: clear Queuevector and Queuelist
    * [4 pts] Test 26 Passed: delete Stackvector and Stacklist without error
* **Part D** (5 points): Profile
   * [5 pts] completes profiling without error
* **Style Guidelines and Memory Leaks**
    * You will lose significant points for the following:
        * Makefile does not have requested format and labels (-5 points)
        * Memory leak or error detected in valgrind  (-10 points)
        * Does not follow requested program structure and submission format (-10 points)

### Guidelines

This is a pair programming assignment. You and a partner can divide up the work. Although both of you may not work on all parts of the program you should understand and be able to fully explain every portion of the code. Outside of your team, it is permissible to consult with classmates to ask general questions about the assignment, to help discover and fix specific bugs, and to talk about high level approaches in general terms. It is not permissible to give or receive answers or solution details from fellow students.

You may research online for additional resources; however, you may not use code that was written specifically to solve the problem you have been given, and you may not have anyone else help you or your partner write the code or solve the problem. You may use code snippets found online, providing that they are appropriately and clearly cited, within your submitted code.

If you or your partner are found to have plagiarized any part of the assignment, both will receive a 0 and be reported.

__In this program, you will learn to__:

* Work with sequential and secondary data structures

For the last program you and partner are going to build both a dynamic array (vector) and a linked list. Each data structure will be tested to ensure the validity of its operations. Once that is complete and you know your data structures are working, we are going to use them as internal data structures for a Stack and a Queue. I have provided code that will evaluate both versions of the Stack and Queue to see which provides better performance.

To make our code more portable, we are going to wrap our data in a Data struct and build all our operations around this data type. In a header file, data.h, create a struct, Data, that contains the following:
* a single integer called, ‘value’

Since we are going to be passing by value, we will not need a constructor or destructor.

:warning: *For all Data Structures, you may (and probably should) add additional functions, methods, and attributes, but what follows is the required minimum interface*

## Part A: Vectors
You must break up your code into vector.h and vector.c according to the conventions we discussed in class.

Create a dynamic array data structure, Vector. You must create your struct and internal array on the heap (using malloc). Your dynamic array should have, at minimum, the following:
    ```
        Data data //A pointer to a Data struct array
        int current_size//an integer containing the current size
        int max_size // an integer containing the maximum capacity
        void (*insert)(Vector *, int, Data) //a function pointer to an insert function
        Data * (*read)(Vector *, int)//a function pointer to an read function
        void (*remove)(Vector *, int)//a function pointer to an delete function
        void (*delete)(Vector *)//a function pointer to a destructor
    ```
You must create the following functions for your Vector
* Constructor - initializes the vector struct attributes and returns a pointer to a Vector struct created on the heap
    * `Vector * newVector()`

:bulb: The remaining function names are suggestions since the driver code calls them all via function pointers

* Insert - inserts an element at the specified index. Use the 2n+1 geometric expansion formula to increase the size of your list if the index is out of the current bounds.
    * `void insertVector(Vector *, int, Data);`
* Remove - deletes an element from the list at the specified index.
    * `void removeVector(Vector *, int);`
        * You must implement true deletion, which will reduce the size of the vector by 1
* Read - return the pointer to the data struct from the specified index, return NULL if the index is out of bounds, and a data struct with the value set to -1 if the index has not been initialized
    * `Data * readVector(Vector * array, int index);`
* Destructor - free all allocated memory for the vector
    * `void * deleteVector`
        * frees all struct memory
        * You should return a NULL pointer from any delete procedure. This is just a convention.

## Part B: Linked Lists
You must break up your code into list.h and list.c according to the conventions we discussed in class.

Your node struct must have the following:
```
    struct Node * next/prev; // A pointer to the next and previous nodes
    Data data; // A data object (:note: not a pointer)
```
Your list struct must have the following:
```
    Node * head, tail //A pointer to nodes at the head and tail
    void (*insert)(List *, int, Data) //a function pointer to an insert function
    Data * (*read)(List *, int) //a function pointer to a read function
    void (*remove)(List *, int) //a function pointer to an delete function
    void (*delete)(List *) //a function pointer to a destructor
```
Create a doubly linked list using a list and node structs. You must create your linked list on the heap (using malloc). Your linked list should have the following operations:
* Constructor - initializes the linked list struct:
    * `List * newList()`
        * A pointer to a head and tail node, both initialized to NULL
        * set function pointers to the appropriate functions
        * returns a pointer to a List struct created on the heap

:bulb: The remaining function names are suggestions since the driver code calls them all via function pointers

* Insert - inserts an element at a specified index in the list.
    * `void insertList(List * list, int index, Data value);`
        * Adds the Data to the specified index
        * If the index is out of bounds, adds the data to the end of your list.
* Delete - deletes an element from a specified index in the list.
    * `void removeData(List * list, int index);`
        * If the index is out of bounds, you should just return without doing anything.
* Read - returns a pointer to the data element stored in the list
    * `Data * readData(List * list, int index);`
        * If the index is out of bounds, return a NULL pointer

## Part C: Stacks and Queues

### Stack
You must break up your code into stack.h and stack.c according to the conventions we discussed in class.

You will have two Stack structs, Stacklist and Stackvector. You will be using your list and vector as the internal data structure, respectively.

#### Stacklist

Your Stacklist must have the following:
```
    List * data;
    Data (*peek)(struct stacklist *);
    Data (*pop)(struct stacklist *);
    void (*push)(struct stacklist *, Data);
    void (*clear)(struct stacklist *);
    void (*delete)(struct stacklist *);
```

You must create your Stacklist on the heap (using malloc). Your Stacklist should have the following operations:
* Constructor - initializes the List struct:
    * `Stacklist * newStacklist()`
        * initializes internal List struct
        * set function pointers to the appropriate functions
        * returns a pointer to a Stacklist struct created on the heap

:bulb: The remaining function names are suggestions since the driver code calls them all via function pointers

* Push - pushes a value onto the top of the stack
    * `void pushStacklist(struct stacklist *, Data);`
        * Adds the Data to the stack
* Pop - deletes and returns an element from the stack
    * `Data popStacklist(struct stacklist *);`
        * Removes the top element on the stack
        * If the stack is empty return a Data struct with -1 for a value
* Peek - returns an element from the stack without deleting
    * `Data peekStacklist(struct stacklist *);`
        * Returns but does not remove the top element on the stack
        * If the stack is empty return a Data struct with -1 for a value
* Clear - removes all elements form the stack
    * `void clearStacklist(struct stacklist *);`
        * removes all elements from the stack
* Delete - frees all memory associated with the stack
    * `void * deleteStacklist(struct stacklist *);`
        * frees the stack memory, including the stack itself

#### Stackvector

Your Stackvector must have the following:
```
    Vector * data;
    Data (*peek)(struct stackvector *);
    Data (*pop)(struct stackvector *);
    void (*push)(struct stackvector *, Data);
    void (*clear)(struct stackvector *);
    void (*delete)(struct stackvector *);
```

You must create your Stackvector on the heap (using malloc). Your Stackvector should have the following operations:
* Constructor - initializes the vector struct:
    * `Stackvector * newStackvector()`
        * initializes internal vector struct
        * set function pointers to the appropriate functions
        * returns a pointer to a Stackvector struct created on the heap
* Push - pushes a value onto the top of the stack
    * `void pushStackvector(struct stackvector *, Data);`
        * Adds the Data to the stack
* Pop - deletes and returns an element from the stack
    * `Data popStackvector(struct stackvector *);`
        * Removes the top element on the stack
        * If the stack is empty return a Data struct with -1 for a value
* Peek - returns an element from the stack without deleting
    * `Data peekStackvector(struct stackvector *);`
        * Returns but does not remove the top element on the stack
        * If the stack is empty return a Data struct with -1 for a value
* Clear - removes all elements form the stack
    * `void clearStackvector(struct stackvector *);`
        * removes all elements from the stack
* Delete - frees all memory associated with the stack
    * `void * deleteStackvector(struct stackvector *);`
        * frees the stack memory, including the stack itself

#### Queuelist

Your Queuelist must have the following:
```
    List * data;
    Data (*peek)(struct queuelist *);
    Data (*dequeue)(struct queuelist *);
    void (*enqueue)(struct queuelist *, Data);
    void (*clear)(struct queuelist *);
    void (*delete)(struct queuelist * s);
```

You must create your Queuelist on the heap (using malloc). Your Queuelist should have the following operations:
* Constructor - initializes the linked list struct:
    * `List * newQueuelist()`
        * initializes internal list struct
        * set function pointers to the appropriate functions
        * returns a pointer to a Queuelist struct created on the heap

:bulb: The remaining function names are suggestions since the driver code calls them all via function pointers

* Enqueue - pushes a value onto the Queue
    * `void enqueueQueuelist(struct queuelist *, Data);`
        * Adds the Data to the Queue
* Dequeue - deletes and returns an element from the Queue
    * `Data dequeueQueuelist(struct queuelist *);`
        * Removes an element from the Queue
        * If the Queue is empty return a Data struct with -1 for a value
* Peek - returns an element from the Queue without deleting
    * `Data peekQueuelist(struct queuelist *);`
        * Returns but does not remove the top element on the Queue
        * If the Queue is empty return a Data struct with -1 for a value
* Clear - removes all elements from the Queue
    * `void clearQueuelist(struct queuelist *);`
        * removes all elements from the Queue
* Delete - frees all memory associated with the Queue
    * `void * deleteQueuelist(struct queuelist *);`
        * frees the Queue memory, including the Queue itself   

#### Queuevector

Your Queuevector must have the following:
```
    List * data;
    Data (*peek)(struct queuevector *);
    Data (*dequeue)(struct queuevector *);
    void (*enqueue)(struct queuevector *, Data);
    void (*clear)(struct queuevector *);
    void (*delete)(struct queuevector *);
```

You must create your Queuevector on the heap (using malloc). Your Queuevector should have the following operations:
* Constructor - initializes the vector struct:
    * `List * newQueuevector()`
        * initializes internal vector struct
        * set function pointers to the appropriate functions
        * returns a pointer to a Queuevector struct created on the heap

:bulb: The remaining function names are suggestions since the driver code calls them all via function pointers

* Enqueue - pushes a value onto the queue
    * `void pushQueuevector(struct queuevector *, Data);`
        * Adds the Data to the queue
* Dequeue - deletes and returns an element from the queue
    * `Data popQueuevector(struct queuevector *);`
        * Removes the next element on the queue
        * If the queue is empty return a Data struct with -1 for a value
* Peek - returns an element from the queue without deleting
    * `Data peekQueuevector(struct queuevector *);`
        * Returns but does not remove the top element on the queue
        * If the queue is empty return a Data struct with -1 for a value
* Clear - removes all elements form the queue
    * `void clearQueuevector(struct queuevector *);`
        * removes all elements from the queue
* Delete - frees all memory associated with the queue
    * `void * deleteQueuevector(struct queuevector *);`
        * frees the queue memory, including the queue itself

## Part D: Profiling

Welcome to the easy part. If you made it this far, you can sit back and relax. I have included a source file called profile.c/.h. Inside this file I have implemented functions that test the operations for both your stacks and queues.

Pay attention to the output.
* What implementation is better for insertion?
* Reading?
* Overall?

## Part E: Submission

### Required file naming and organization:
* program5.c //Driver Code
* data.h
* list.c/.h
* profile.c/.h (provided)
* queue.c/.h
* stack.c/.h
* vector.c/.h
* makefile
    * You must have the following labels in your makefile:
        * all - to compile all your code to an executable called ‘program4’ (no extension). Do not run.
        * run - to compile if necessary and run
        * memcheck - to compile only if necessary and run with valgrind
        * clean - to remove all executables and object files

:no_entry: Every program will have a required submission guidelines. Please read submission requirements carefully. Any deviations from specifications will result in point deductions or incomplete grades.

## README

* KNOWN BUGS AND INCOMPLETE PARTS
* REFERENCES
* MISCELLANEOUS COMMENTS

Before your final submission, edit the content for each of these sections in this README for your program. You do not have to use markdown, but you can find out more about markdown [here](https://guides.github.com/features/mastering-markdown/) if you would like to.

### Git

Below is a reminder of the commands you need to use to submit your program.

:warning: You have created several files and even a folder for this program. Be sure you add them to the repo. If you forget to add the files to the repo, your assignment will be considered late or not accepted at all.

```shell
git status
git add mylib.h
git commit -a -m "commit message"
git push
```

To find your most recent commit hash, use the following command:

```shell
git rev-parse HEAD
```    

To complete your submission, you must copy and paste this number into mycourses. Go to MyCourses, select cs580u, and **Assignment Hash Submission**.

:warning: You __MUST__ submit the commit hash on mycourses before the deadline to be considered on time **even if your program is completely working before the deadline**. :warning:
