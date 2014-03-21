#include "..\inc.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(!head)
            return NULL;
        TreeNode * r = new TreeNode(0);
        help(head, NULL, r);
        return r;
    }
    void help(ListNode * h, ListNode * e, TreeNode * n){
        assert(h);
        //find mid node
        ListNode * t = h;
        ListNode * m = h;
        while(t != e){
            assert(t);
            t = t->next;
            if(t == e)
                break;
            assert(t);
            t = t->next;
            assert(m);
            m = m->next;
        }
        assert(n && m);
        n->val = m->val;
        //left child
        if(h != m){
            n->left = new TreeNode(0);
            help(h, m, n->left);
        }
        //right child
        if(m != e && m->next != e){
            n->right = new TreeNode(0);
            help(m->next, e, n->right);
        }
    }
};

int main(){}