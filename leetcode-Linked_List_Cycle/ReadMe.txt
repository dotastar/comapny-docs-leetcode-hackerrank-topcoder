I
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

dozerg:
如果链表有环，令环之前的链表有a个节点，环有b个节点；
第一轮fast指针每次走2步，slow指针每次走1步，
假设相遇位置距环的入口有c个节点，那么有如下关系：
fast = 2*slow
fast = a + N*b + c  //fast在遇到slow之前，已经绕环N周了
slow = a + c
由此可以得到：
c = N*b - a     //显然，如果b >= a，那么N=1；反之，N=(a+b-1)/b

第二轮，fast从起点出发，每次1步；slow从c出发，每次1步，
当fast走到环入口时
fast = a
slow = c + a = N*b
即slow也在环的入口，故fast与slow必相遇在环入口。