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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > r;
        if(!root)
            return r;
        vector<TreeNode *> v(1, root);
        for(bool z = true;!v.empty();z = !z){
            vector<TreeNode *> t;
            vector<int> vv(v.size());
            for(int i = 0;i < int(v.size());++i){
                if(z)
                    vv[i] = v[i]->val;
                else
                    vv[vv.size() - 1 - i] = v[i]->val;
                if(v[i]->left)
                    t.push_back(v[i]->left);
                if(v[i]->right)
                    t.push_back(v[i]->right);
            }
            t.swap(v);
            r.push_back(vv);
        }
        return r;
    }
};

int main(){}
