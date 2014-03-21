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
    int minDepth(TreeNode *root) {
        if(!root)
            return 0;
        vector<TreeNode *> c(1, root), t;
        int r = 1;
        for(;!c.empty();++r){
            for(size_t i = 0;i < c.size();++i){
                if(!c[i]->left && !c[i]->right)
                    return r;
                if(c[i]->left)
                    t.push_back(c[i]->left);
                if(c[i]->right)
                    t.push_back(c[i]->right);
            }
            c.swap(t);
            t.clear();
        }
        return r;
    }
};

int main(){}
