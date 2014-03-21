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
    ListNode *deleteDuplicatesI(ListNode *head) {
        ListNode * cur = NULL;
        ListNode * n = head;
        while(n){
            if(!cur)
                cur = n;
            else if(cur->val != n->val){
                cur->next = n;
                cur = n;
            }
            n = n->next;
        }
        if(cur)
            cur->next = NULL;
        return head;
    }
    ListNode *deleteDuplicatesII(ListNode *head) {
        ListNode * p = NULL;
        ListNode * c = head;
        while(c){
            if(!c->next || c->next->val != c->val){
                if(!p)
                    head = c;
                p = c;
                c = c->next;
            }else{
                ListNode * t = c->next;
                while(t->next && t->next->val == c->val)
                    t = t->next;
                if(p){
                    c = p->next = t->next;
                }else
                    head = c = t->next;
            }
        }
        return head;
    }
};

int main(){}
