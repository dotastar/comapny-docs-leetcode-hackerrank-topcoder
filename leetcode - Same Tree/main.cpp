/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(!p || !q)
            return p == q;
        vector<TreeNode *> pn;
        vector<TreeNode *> qn;
        pn.push_back(p);
        qn.push_back(q);
        for(size_t i = 0;i < pn.size();++i){
            if(pn[i]->val != qn[i]->val
                    || bool(pn[i]->left) != bool(qn[i]->left)
                    || bool(pn[i]->right) != bool(qn[i]->right))
                return false;
            if(pn[i]->left){
                pn.push_back(pn[i]->left);
                qn.push_back(qn[i]->left);
            }
            if(pn[i]->right){
                pn.push_back(pn[i]->right);
                qn.push_back(qn[i]->right);
            }
        }
        return true;
    }
};
*/
int main(){}
