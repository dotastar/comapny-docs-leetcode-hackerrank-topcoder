#include "..\inc.h"

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
    int sumNumbers(TreeNode *root) {
        int r = 0;
        if(!root)
            return r;
        help(root, 0, r);
        return r;
    }
    void help(TreeNode * n, int s, int & r){
        assert(n);
        s = s * 10 + n->val;
        if(!n->left && !n->right){
            r += s;
            return;
        }
        if(n->left)
            help(n->left, s, r);
        if(n->right)
            help(n->right, s, r);
    }
};

int main(){}
