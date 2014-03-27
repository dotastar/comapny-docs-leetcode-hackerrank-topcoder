Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass

dozerg:
首先，t指针指向head，然后往后移动n+1次。如果中途遇到NULL，则说明head要被移走。
然后p指针指向head，和t同步向后移动，直到t为NULL。此时p指向要移走的node的前一个node。
p->next = p->next->next
返回head，完成。