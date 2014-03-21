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
    //O(N * logM): N is node count, M is list count
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty())
            return NULL;
        while(lists.size() > 1){
            vector<ListNode *> t;
            for(size_t i = 0;i < lists.size();i += 2)
                if(i + 1 < lists.size())
                    t.push_back(merge(lists[i], lists[i + 1]));
                else
                    t.push_back(lists[i]);
            t.swap(lists);
        }
        return lists[0];
    }
    ListNode * merge(ListNode * li1, ListNode * li2){
        if(!li1)
            return li2;
        if(!li2)
            return li1;
        ListNode * h = NULL;
        ListNode * c = NULL;
        for(;li1 && li2;c->next = NULL){
            if(li1->val < li2->val){
                if(c)
                    c->next = li1;
                c = li1;
                li1 = c->next;
            }else{
                if(c)
                    c->next = li2;
                c = li2;
                li2 = c->next;
            }
            if(!h)
                h = c;
        }
        if(li1){
            if(c)
                c->next = li1;
            c = li1;
        }else if(li2){
            if(c)
                c->next = li2;
            c = li2;
        }
        if(!h)
            h = c;
        return h;
    }
};

int main()
{
}
