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
    bool isValidBST(TreeNode *root) {
        return help(root, 0x80000000, 0x7FFFFFFF);
    }
    bool help(TreeNode * n, int min, int max){
        if(!n)
            return true;
        assert(min <= max);
        if(n->val < min || n->val > max)
            return false;
        if(n->val > min){
            if(!help(n->left, min, n->val - 1))
                return false;
        }else if(n->left)
            return false;
        if(n->val < max){
            if(!help(n->right, n->val + 1, max))
                return false;
        }else if(n->right)
            return false;
        return true;
    }
};

int main(){}
