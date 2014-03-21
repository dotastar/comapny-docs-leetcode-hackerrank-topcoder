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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode * h = NULL;
        ListNode * t = NULL;
        int rem = 0;
        do{
            //add l1 & l2 value
            ListNode * c = new ListNode(rem);
            if(l1){
                c->val += l1->val;
                l1 = l1->next;
            }
            if(l2){
                c->val += l2->val;
                l2 = l2->next;
            }
            rem = (c->val < 10 ? 0 : 1);
            c->val %= 10;
            //insert
            if(t)
                t->next = c;
            t = c;
            if(!h)
                h = t;
        }while(l1 || l2 || rem);
        return h;
    }
};

int main(){}
