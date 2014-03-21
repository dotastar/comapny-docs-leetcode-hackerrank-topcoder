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
    void flatten(TreeNode *root) {
        if(!root)
            return;
        flatten(root->left);
        flatten(root->right);
        if(root->left){
            TreeNode * n = root->left;
            while(n->right)
                n = n->right;
            n->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
    }
};

int main(){}
