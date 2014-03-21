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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *h = NULL, *r = NULL;
        while(l1 && l2){
            if(l1->val < l2->val){
                if(!r)
                    r = l1;
                else{
                    r->next = l1;
                    r = l1;
                }
                l1 = l1->next;
            }else{
                if(!r)
                    r = l2;
                else{
                    r->next = l2;
                    r = l2;
                }
                l2 = l2->next;
            }
            r->next = NULL;
            if(!h)
                h = r;
        }
        if(l1){
            if(!r)
                r = l1;
            else
                r->next = l1;
        }else if(l2){
            if(!r)
                r = l2;
            else
                r->next = l2;
        }
        return (h ? h : r);
    }
};
