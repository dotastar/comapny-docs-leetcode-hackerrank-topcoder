/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
            return NULL;
        RandomListNode * cur = head;
        while(cur){
            RandomListNode * n = new RandomListNode(cur->label);
            n->next = cur->next;
            cur->next = n;
            cur = n->next;
        }
        cur = head;
        RandomListNode * ret = cur->next;
        while(cur){
            RandomListNode * cp = cur->next;
            assert(cp);
            if(cur->random)
                cp->random = cur->random->next;
            cur->next = cp->next;
            if(cp->next)
                cp->next = cp->next->next;
            cur = cur->next;
        }
        return ret;
    }
};
