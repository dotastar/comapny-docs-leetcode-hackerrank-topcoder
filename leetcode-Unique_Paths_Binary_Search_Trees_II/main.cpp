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
    vector<TreeNode *> generateTrees(int n) {
        return help(1, n);
    }
    vector<TreeNode *> help(int s, int e){
        vector<TreeNode *> r;
        if(s > e){
            r.push_back(NULL);
            return r;
        }
        for(int i = s;i <= e;++i){
            vector<TreeNode *> le = help(s, i - 1);
            vector<TreeNode *> ri = help(i + 1, e);
            for(size_t j = 0;j < le.size();++j)
                for(size_t k = 0;k < ri.size();++k){
                    r.push_back(new TreeNode(i));
                    r.back()->left = le[j];
                    r.back()->right = ri[k];
                }
        }
        return r;
    }
};

int main()
{
}
