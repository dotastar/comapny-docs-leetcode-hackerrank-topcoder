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
    ListNode *partition(ListNode *head, int x) {
        ListNode * h1 = NULL;
        ListNode * p1 = NULL;
        ListNode * h2 = NULL;
        ListNode * p2 = NULL;
        ListNode * c = head;
        while(c){
            if(c->val < x){
                if(p1){
                    p1->next = c;
                    p1 = c;
                }else
                    h1 = p1 = c;
                c = c->next;
                p1->next = NULL;
            }else{
                if(p2){
                    p2->next = c;
                    p2 = c;
                }else
                    h2 = p2 = c;
                c = c->next;
                p2->next = NULL;
            }
        }
        if(h1){
            head = h1;
            if(h2)
                p1->next = h2;
        }else
            head = h2;
        return head;
    }
};

int main()
{
    ListNode n1(1), n2(1);
    n1.next = &n2;
    Solution().partition(&n1, 0);
}
