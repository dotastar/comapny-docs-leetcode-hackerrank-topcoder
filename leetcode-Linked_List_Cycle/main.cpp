#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle1(ListNode *head) {
        ListNode * m = head;
        ListNode * t = head;
        while(t){
            t = t->next;
            if(t){
                if(m == t)
                    return true;
                t = t->next;
                if(m == t)
                    return true;
                m = m->next;
            }
        }
        return false;
    }
    //no extra space
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        head->val = 0;
        while(head->next){
            if(head->next == head)
                return true;
            if(0 == memcmp(&head->next->val, &head->next, sizeof head->next->val)){
                if(++head->val > 100)
                    return true;
            }else
                head->val = 0;
            memcpy(&head->next->val, &head->next, sizeof head->next->val);
            head->next = head->next->next;
        }
        return false;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode * m = head;
        ListNode * t = head;
        while(t){
            t = t->next;
            if(!t)
                return NULL;
            t = t->next;
            if(!t)
                return NULL;
            m = m->next;
            if(t == m)
                break;
        }
        m = head;
        while(m != t){
            m = m->next;
            t = t->next;
        }
        return m;
    }
};

int main()
{
    {
        ListNode n(1);
        n.next = &n;
        cout<<Solution().hasCycle(&n)<<endl;
    }
}
