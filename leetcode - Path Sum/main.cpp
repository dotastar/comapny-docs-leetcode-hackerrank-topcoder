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
    bool hasPathSum(TreeNode *root, int sum) {
        if(!root)
            return false;
        sum -= root->val;
        if(!root->left && !root->right)
            return !sum;
        if(root->left && hasPathSum(root->left, sum))
            return true;
        if(root->right && hasPathSum(root->right, sum))
            return true;
        return false;
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > r;
        if(!root)
            return r;
        vector<int> v;
        help(root, sum, v, r);
        return r;
    }
    void help(TreeNode * n, int sum, vector<int> & v, vector<vector<int> > & r){
        assert(n);
        sum -= n->val;
        v.push_back(n->val);
        if(!n->left && !n->right && !sum){
            r.push_back(v);
            return;
        }
        size_t old = v.size();
        if(n->left)
            help(n->left, sum, v, r);
        v.resize(old);
        if(n->right)
            help(n->right, sum, v, r);
    }
};

int main(){}