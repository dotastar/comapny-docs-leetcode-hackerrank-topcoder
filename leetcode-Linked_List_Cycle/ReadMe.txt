Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

II
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?
用两个指针p1、p2指向表头，每次循环时p1指向它的后继，
p2指向它后继的后继。若p2的后继为NULL，表明链表没有环；
否则有环且p1==p2时循环可以终止。此时为了寻找环的入口，
将p1重新指向表头且仍然每次循环都指向后继，p2每次也指
向后继。当p1与p2再次相等时，相等点就是环的入口。
