#include "../inc.h"

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
    //O(logN) space (use stack space)
    void recoverTree1(TreeNode *root) {
        vector<TreeNode *> r(3);
        help(root, r);
        if(r[1] && r[2])
            swap(r[1]->val, r[2]->val);
    }
    void help(TreeNode * n, vector<TreeNode *> & r){
        if(!n)
            return;
        help(n->left, r);
        if(r[0] && r[0]->val > n->val){
            if(!r[1]){
                r[1] = r[0];
                r[2] = n;
            }else
                r[2] = n;
        }
        r[0] = n;
        help(n->right, r);
    }

    //O(1) space
    void recoverTree2(TreeNode *root) {
        TreeNode * s1 = NULL;
        TreeNode * s2 = NULL;
        TreeNode * p = NULL;
        TreeNode * pp = NULL;
        TreeNode * c = root;
        while(c){
            if(c->left){
                p = c->left;
                while(p->right && p->right != c)
                    p = p->right;
                if(p->right){
                    //2nd time: revert
                    p->right = NULL;
                    if(p->val > c->val){
                        if(!s1)
                            s1 = p;
                        s2 = c;
                    }
                    pp = c;
                    c = c->right;
                }else{
                    //1st time: make a threadd binary tree
                    p->right = c;
                    c = c->left;
                }
            }else{
                if(pp && pp->val > c->val){
                    if(!s1)
                        s1 = pp;
                    s2 = c;
                }
                pp = c;
                c = c->right;
            }
        }
        if(s1 && s2)
            swap(s1->val, s2->val);
    }
};

int main()
{
}
