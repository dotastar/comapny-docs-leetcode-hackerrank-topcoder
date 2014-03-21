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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        assert(1 <= m && m <= n);
        if(m == n)
            return head;
        //find from & to
        ListNode * t = head;
        for(int i = 0;i < n - m;++i){
            assert(t);
            t = t->next;
        }
        assert(t);
        ListNode * p = NULL;
        ListNode * f = head;
        for(int i = 1;i < m;++i){
            assert(f && t);
            p = f;
            f = f->next;
            t = t->next;
        }
        //move 'from' after 'to'
        for(;f != t;){
            assert(f && t);
            ListNode * ne = f->next;
            f->next = t->next;
            t->next = f;
            if(p)
                p->next = ne;
            f = ne;
        }
        return (p ? head : t);
    }
};

int main()
{
    ListNode n1(3), n2(5);
    n1.next = &n2;
    Solution().reverseBetween(&n1, 1, 2);
}
