/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        assert(n > 0);
        if(!head)
            return NULL;
        ListNode * t = head;
        for(int i = 0;i < n && t;++i)
            t = t->next;
        ListNode * p = NULL;
        ListNode * c = head;
        while(t){
            p = c;
            assert(c);
            c = c->next;
            t = t->next;
        }
        if(p){
            p->next = c->next;
        }else{
            head = c->next;
        }
        return head;
    }
};
*/
int main(){}
