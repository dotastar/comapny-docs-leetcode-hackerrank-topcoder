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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(k < 2)
            return head;
        ListNode * p = NULL;
        ListNode * h = head;
        for(;;){
            //find k-th node
            ListNode * t = h;
            for(int i = 1;i < k && t;++i)
                t = t->next;
            if(!t)
                break;
            //save next
            ListNode * n = t->next;
            //reverse cur group nodes
            ListNode * f = h;
            ListNode * pp = NULL;
            while(f != t){
                ListNode * nn = f->next;
                if(p)
                    p->next = nn;
                f->next = t->next;
                t->next = f;
                if(!pp)
                    pp = f;
                f = nn;
            }
            if(!p)
                head = t;
            //move to next group
            p = pp;
            h = n;
        }
        return head;
    }
};

int main()
{
    //Solution().reverseKGroup(NULL, 10);
    ListNode n1(1), n2(2), n3(3), n4(4);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    Solution().reverseKGroup(&n1, 2);
}
