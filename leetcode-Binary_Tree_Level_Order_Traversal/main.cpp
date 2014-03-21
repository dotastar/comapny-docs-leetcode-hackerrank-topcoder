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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > r;
        if(!root)
            return r;
        vector<TreeNode *> c(1, root), t;
        for(vector<int> v;!c.empty();t.clear()){
            for(size_t i = 0;i < c.size();++i){
                v.push_back(c[i]->val);
                if(c[i]->left)
                    t.push_back(c[i]->left);
                if(c[i]->right)
                    t.push_back(c[i]->right);
            }
            c.swap(t);
            r.resize(r.size() + 1);
            r.back().swap(v);
        }
        return r;
    }
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > r;
        if(!root)
            return r;
        vector<TreeNode *> c(1, root), t;
        for(vector<int> v;!c.empty();t.clear()){
            for(size_t i = 0;i < c.size();++i){
                v.push_back(c[i]->val);
                if(c[i]->left)
                    t.push_back(c[i]->left);
                if(c[i]->right)
                    t.push_back(c[i]->right);
            }
            c.swap(t);
            r.resize(r.size() + 1);
            r.back().swap(v);
        }
        if(r.size() > 1)
            for(size_t i = 0, j = r.size() - 1;i < j;++i, --j)
                r[i].swap(r[j]);
        return r;
    }
};
