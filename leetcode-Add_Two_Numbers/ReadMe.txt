You are given two linked lists representing two 
non-negative numbers. The digits are stored in 
reverse order and each of their nodes contain a 
single digit. Add the two numbers and return it 
as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8


dozerg:
如果数字不是逆序的，而是正序的，如何做？
例如：
2->5->8 + 5->6 = 3->1->4

方法1：
reverse list 1;
reverse list 2;
add list 1 and 2;
reverse result list;

方法2：
find equal start postion of list 1 & list from end;
add each pair of nodes from list 1 and list 2 (node value may > 9);
reverse result list and handle node value > 9;
reverse result list again;