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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        assert(preorder.size() == inorder.size());
        return help(preorder, inorder, 0, 0, preorder.size());
    }
    TreeNode * help(vector<int> &preorder, vector<int> &inorder, size_t pfrom, size_t ifrom, size_t len){
        if(!len)
            return NULL;
        assert(pfrom < preorder.size());
        TreeNode * n = new TreeNode(preorder[pfrom]);
        size_t i = 0;
        for(;i < len;++i)
            if(inorder[ifrom + i] == n->val)
                break;
        assert(i < len);
        n->left = help(preorder, inorder, pfrom + 1, ifrom, i);
        n->right = help(preorder, inorder, pfrom + 1 + i, ifrom + i + 1, len - i - 1);
        return n;
    }
};

int main(){}
