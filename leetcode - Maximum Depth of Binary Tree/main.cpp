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
    int maxDepth(TreeNode *root) {
        if(!root)
            return 0;
        vector<TreeNode *> cur;
        vector<TreeNode *> next;
        cur.push_back(root);
        int dep = 0;
        for(;!cur.empty();++dep){
            for(size_t i = 0;i < cur.size();++i){
                TreeNode * n = cur[i];
                if(n->left)
                    next.push_back(n->left);
                if(n->right)
                    next.push_back(n->right);
            }
            cur.clear();
            cur.swap(next);
        }
        return dep;
    }
};
*/
int main(){}
