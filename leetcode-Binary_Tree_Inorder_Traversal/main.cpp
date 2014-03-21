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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> r;
        if(!root)
            return r;
        vector<TreeNode *> p;
        TreeNode * c = root;
        for(int s = 3;;){
            if((s & 1) && c->left){
                p.push_back(c);
                c = c->left;
                s = 3;
                continue;
            }
            if(s & 2){
                r.push_back(c->val);
                if(c->right){
                    p.push_back(c);
                    c = c->right;
                    s = 3;
                    continue;
                }
            }
            if(p.empty())
                break;
            if(p.back()->left == c)
                s = 2;
            else
                s = 0;
            c = p.back();
            p.pop_back();
        }
        return r;
    }
};
