#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode * nh = NULL;
        ListNode * p = NULL;
        ListNode * c = head;
        while(c){
            ListNode * n = c->next;
            if(!n)
                break;
            c->next = n->next;
            n->next = c;
            if(p)
                p->next = n;
            p = c;
            c = c->next;
            if(!nh)
                nh = n;
        }
        return (nh ? nh : c);
    }
};

void print(ListNode * head)
{
    while(head){
        std::cout<<head->val<<" ";
        head = head->next;
    }
    std::cout<<"\n";
}

int main()
{
    ListNode n1(1), n2(2), n3(3), n4(4);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    print(Solution().swapPairs(&n1));
}

/*
1 2 3 4
2 1 4 3
nh 2
c  1 3 NULL
n  2 4
*/
