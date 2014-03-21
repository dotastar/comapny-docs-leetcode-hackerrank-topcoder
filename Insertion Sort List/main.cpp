#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode * cur = head;
        ListNode * curp = NULL;
        while(cur){
            ListNode * cmp = cur->next;
            ListNode * cmpp = cur;
            while(cmp){
                if(cmp->val < cur->val){
                    //save cmp->next
                    ListNode * n = cmp->next;
                    //insert cmp before cur, update head, cur = cmp
                    if(curp){
                        curp->next = cmp;
                    }else
                        head = cmp;
                    cmp->next = cur;
                    cur = cmp;
                    //set cmp to saved next
                    cmpp->next = n;
                    cmp = n;
                }else{
                    //cmp move to next
                    cmpp = cmp;
                    cmp = cmp->next;
                }
            }
            //cur move to next
            curp = cur;
            cur = cur->next;
        }
        return head;
    }
};

void print(ListNode * h)
{
    while(h)
        cout<<h->val<<" ";
    cout<<endl;
}

int main()
{
    {
        ListNode n1(2), n2(1);
        n1.next = &n2;
        print(Solution().insertionSortList(&n1));
    }
}