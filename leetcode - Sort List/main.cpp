#include <iostream>
#include <algorithm>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        ListNode * t[32] = {NULL};
        while(head){
            t[0] = next(head);
            for(int i = 1;i < 32;++i){
                if(t[i])
                    merge(t[i - 1], t[i]);
                else{
                    swap(t[i - 1], t[i]);
                    break;
                }
            }
        }
        for(int i = 1;i < 32;++i)
            if(t[i]){
                if(!t[0]){
                    t[0] = t[i];
                    t[i] = NULL;
                }else
                    merge(t[i], t[0]);
            }
        return t[0];
    }
    ListNode * next(ListNode *& n){
        if(!n)
            return NULL;
        ListNode * r = n;
        n = n->next;
        r->next = NULL;
        return r;
    }
    void append(ListNode *& h, ListNode *& t, ListNode * n){
        if(NULL == h)
            h = n;
        if(t)
            t->next = n;
        t = n;
    }
    void merge(ListNode *& a, ListNode *& b){
        ListNode * h = NULL;
        ListNode * t = NULL;
        while(a && b){
            if(a->val < b->val){
                append(h, t, next(a));
            }else if(a->val > b->val){
                append(h, t, next(b));
            }else{
                append(h, t, next(a));
                append(h, t, next(b));
            }
        }
        if(a){
            append(h, t, a);
            a = NULL;
        }else if(b){
            append(h, t, b);
        }
        b = h;
    }
};

void print(ListNode * h)
{
    while(h){
        cout<<h->val;
        h = h->next;
    }
    cout<<endl;
}

int main()
{
    {
        ListNode n1(2), n2(1);
        n1.next = &n2;
        //print(Solution().sortList(&n1));
    }{
        ListNode n1(3), n2(2), n3(4);
        n1.next = &n2;
        n2.next = &n3;
        print(Solution().sortList(&n1));
    }
}