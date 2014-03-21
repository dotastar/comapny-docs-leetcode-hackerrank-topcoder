#include "../inc.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(!head || !head->next || k <= 0)
            return head;
        ListNode * t;
        for(;;){
            t = head;
            int sz = 0;
            for(;sz < k && t;++sz)
                t = t->next;
            if(t)
                break;
            assert(sz > 0);
            k %= sz;
            if(!k)
                return head;
        }
        ListNode * p = head;
        assert(t);
        while(t->next){
            p = p->next;
            t = t->next;
        }
        t->next = head;
        head = p->next;
        p->next = NULL;
        return head;
    }
};

int main()
{
    ListNode n1(1), n2(2);
    n1.next = &n2;
    print(Solution().rotateRight(&n1, 2));
}