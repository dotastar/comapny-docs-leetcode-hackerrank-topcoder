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

class Solution2 {
public:
    ListNode *sortList(ListNode *head) {
        vector<ListNode *> vec(33);
        while(head){
            vec[0] = head;
            head = head->next;
            vec[0]->next = NULL;
            for(size_t i = 1;i < vec.size();++i)
                if(!mergeOrMove(vec[i - 1], vec[i]))
                    break;
        }
        for(size_t i = 1;i < vec.size();++i)
            vec[0] = merge(vec[0], vec[i]);
        return vec[0];
    }
    bool mergeOrMove(ListNode *& from, ListNode *& to){
        if(!to){
            swap(from, to);
            return false;
        }
        to = merge(from, to);
        from = NULL;
        return true;
    }
    ListNode * merge(ListNode * h1, ListNode * h2){
        ListNode * r = NULL;
        ListNode * t = NULL;
        while(h1 && h2){
            if(h1->val < h2->val){
                append(r, t, h1);
                h1 = h1->next;
            }else{
                append(r, t, h2);
                h2 = h2->next;
            }
        }
        if(h1)
            append(r, t, h1);
        if(h2)
            append(r, t, h2);
        return r;
    }
    void append(ListNode *& head, ListNode *& tail, ListNode * node){
        assert(node);
        if(tail)
            tail->next = node;
        tail = node;
        if(!head)
            head = tail;
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