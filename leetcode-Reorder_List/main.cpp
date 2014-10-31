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
    //O(N^2) time, O(1) space
    void reorderList1(ListNode *head) {
        if(!head)
            return;
        ListNode * cur = head->next;
        head->next = NULL;
        for(;cur;){
            if(cur->next){
                //find tail
                ListNode * p = cur;
                ListNode * t = cur->next;
                while(t->next){
                    p = t;
                    t = t->next;
                }
                //append tail
                head->next = t;
                p->next = NULL;
                head = t;
            }
            //append cur
            head->next = cur;
            head = cur;
            cur = cur->next;
            head->next = NULL;
        }
    }
    //O(N) time, O(N) space
    void reorderList2(ListNode *head) {
        if(!head)
            return;
        vector<ListNode *> v;
        while(head){
            v.push_back(head);
            head = head->next;
        }
        head = NULL;
        int i = 0, j = v.size() - 1;
        for(;i < j;++i, --j){
            if(head)
                head->next = v[i];
            head = v[i];
            head->next = v[j];
            head = v[j];
        }
        if(i == j){
            if(head)
                head->next = v[i];
            head = v[i];
        }
        head->next = NULL;
    }
    //O(N) time, O(1) space
    void reorderList(ListNode *head) {
        //find mid
        ListNode * p = NULL;
        ListNode * mid = head;
        ListNode * t = head;
        while(t){
            p = mid;
            mid = mid->next;
            t = t->next;
            if(!t)
                break;
            t = t->next;
        }
        if(!mid)
            return;
        p->next = NULL;
        //reverse [mid, tail];
        p = NULL;
        while(mid){
            t = mid->next;
            mid->next = p;
            p = mid;
            mid = t;
        }
        mid = p;
        //merge
        while(head && mid){
            t = head->next;
            head->next = mid;
            p = mid->next;
            mid->next = t;
            mid = p;
            head = t;
        }
    }
};

class Solution2 {
public:
    void reorderList(ListNode *head) {
        ListNode * tail = head;
        ListNode * cur = tail;
        for(;tail && tail->next && tail->next->next;cur = cur->next, tail = tail->next->next);
        if(cur == head)
            return;
        tail = cur->next;
        cur->next = NULL;
        ListNode * prev = NULL;
        for(cur = tail;cur;){
            ListNode * next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        for(tail = prev;tail;head = tail->next = cur, tail = prev){
            cur = head->next;
            prev = tail->next;
            head->next = tail;
        }
    }
};