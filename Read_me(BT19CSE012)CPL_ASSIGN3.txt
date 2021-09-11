NAME :- BARTAKKE ONKAR SUHAS
ENROLL :- BT19CSE012

CPL Assignment 3 

Implementation of First fit Algo

First Fit Algorithm is the simplest technique of allocating the memory block to the processes amongst all.
In this algorithm, the pointer keeps track of all the free blocks in the memory and accepts the request of allocating a memory block to the coming process

So what happens is when request is made to allocate memory of some size to some pointer, in the heap it is searched from start the largest continoues block
just >= required memory. If memory is found it is allocated.


In my program Each memory node is largest continous block of memory available in the heap memory
Where we can see that fields like allocate, free and total space (allocated+free) gives info about that memory block of the memory.

class memory_Node
{
    public:
        int tag;
        vector<pair<char,int>>allocated_ids;
        int Total_space;
        int allocated_space;
        int free_space;
        int count;
        memory_Node *next;
        memory_Node *prev;
};

Here allocated id is the vector pair, where 1st part stores the name of thee pointer and the 2nd part of it stores the size of memory allocated by the pointer
in that continous memory block.

count is the total number of active pointers contained by that heap block

tag-id is the id of that memory heap block (starts from 1) 

unordered_map<char,int>mp;
I have used this mapping functions which maps from pointer name to the tag-id of the memory heap block(which we have represented by memory node) in O(1) time
once we get tag id, we go to that memory node by traversing the double link list and then perform our operation.

INPUTS :-
give the number continous memory heap blocks you want to be created , (that many nodes of the List will be created)

Afer that Enter the Sizes of those blocks 

and then we can perform mentioned operations


DEMO PROGRAM - 

Enter the Number of FREE Memory Blocks in the Heap : 3

Enter the sizes of this 3 Blocks : 
100

Block with tag id 1 created for which :- 

Total space - 100
Allocated space - 0
Free Space - 100

200

Block with tag id 2 created for which :-

Total space - 200
Allocated space - 0
Free Space - 200

500

Block with tag id 3 created for which :-

Total space - 500
Allocated space - 0
Free Space - 500


Memory is Ready for Allocation and Deletion process

Select from Following :-
1)Allocate
2)Delete
3)Display Memory stats
4)Exit the program

1

Enter the space to be allocated : 475

Enter the name of pointer which will point to that space : a

Memory Successfully allocated in the Block with tag-id 3
After Allocation :-
Freespace = 500 - 475 = 25
Allocated space = 0 + 475 = 475


Allocated-memory with pointer  a

Select from Following :-
1)Allocate
2)Delete
3)Display Memory stats
4)Exit the program

1

Enter the space to be allocated : 50

Enter the name of pointer which will point to that space : p

Memory Successfully allocated in the Block with tag-id 1
After Allocation :-
Freespace = 100 - 50 = 50
Allocated space = 0 + 50 = 50


Allocated-memory with pointer  p

Select from Following :-
1)Allocate
2)Delete
3)Display Memory stats
4)Exit the program

1

Enter the space to be allocated : 37

Enter the name of pointer which will point to that space : q

Memory Successfully allocated in the Block with tag-id 1
After Allocation :-
Freespace = 50 - 37 = 13
Allocated space = 50 + 37 = 87


Allocated-memory with pointer  q

Select from Following :-
1)Allocate
2)Delete
3)Display Memory stats
4)Exit the program

3

Memory Blocks are :-
Tag-id   Block-size
1        100
2        200
3        500


Memory Stats :-



Block Tag id - 1
Free Space - 13
Allocate Space - 87
Total Space - 100
Number of Process blocks it contains : 2
Process Blocks are :-
Pointer name :- p | Process size(memory occupied) 50
Pointer name :- q | Process size(memory occupied) 37


Block Tag id - 2
Free Space - 200
Allocate Space - 0
Total Space - 200
Number of Process blocks it contains : 0

Block Tag id - 3
Free Space - 25
Allocate Space - 475
Total Space - 500
Number of Process blocks it contains : 1
Process Blocks are :-
Pointer name :- a | Process size(memory occupied) 475

Select from Following :-
1)Allocate
2)Delete
3)Display Memory stats
4)Exit the program

1

Enter the space to be allocated : 108

Enter the name of pointer which will point to that space : n

Memory Successfully allocated in the Block with tag-id 2
After Allocation :-
Freespace = 200 - 108 = 92
Allocated space = 0 + 108 = 108


Allocated-memory with pointer  n

Select from Following :-
1)Allocate
2)Delete
3)Display Memory stats
4)Exit the program

2

Enter the pointer name for Deletion of allocated Process memory : a

Memory of size 475 by pointer a Deleted from Block with Tag-id 3
After Deletion:-
Free space = 25 + 475 = 500
Allocated space = 475 - 475 = 0

Select from Following :-
1)Allocate
2)Delete
3)Display Memory stats
4)Exit the program

3

Memory Blocks are :-
Tag-id   Block-size
1        100
2        200
3        500


Memory Stats :-



Block Tag id - 1
Free Space - 13
Allocate Space - 87
Total Space - 100
Number of Process blocks it contains : 2
Process Blocks are :-
Pointer name :- p | Process size(memory occupied) 50
Pointer name :- q | Process size(memory occupied) 37


Block Tag id - 2
Free Space - 92
Allocate Space - 108
Total Space - 200
Number of Process blocks it contains : 1
Process Blocks are :-
Pointer name :- n | Process size(memory occupied) 108


Block Tag id - 3
Free Space - 500
Allocate Space - 0
Total Space - 500
Number of Process blocks it contains : 0
Select from Following :-
1)Allocate
2)Delete
3)Display Memory stats
4)Exit the program

4