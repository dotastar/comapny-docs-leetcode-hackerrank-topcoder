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
    typedef unordered_map<TreeNode *, pair<int, int> > __Map;
    int maxPathSum(TreeNode *root) {
        if(!root)
            return 0;
        //calc & save left & right path max sum
        __Map save;
        help(root, save);
        //calc max path through each 'root'
        return calc(root, save);
    }
    __Map::const_iterator help(TreeNode * n, __Map & save){
        assert(n);
        pair<int, int> r;
        if(n->left){
            __Map::const_iterator it = help(n->left, save);
            r.first = max(n->left->val, n->left->val + it->second.first);
            r.first = max(r.first, n->left->val + it->second.second);
        }
        if(n->right){
            __Map::const_iterator it = help(n->right, save);
            r.second = max(n->right->val, n->right->val + it->second.first);
            r.second = max(r.second, n->right->val + it->second.second);
        }
        return save.insert(make_pair(n, r)).first;
    }
    int calc(TreeNode * n, const __Map & save){
        assert(n);
        __Map::const_iterator wh = save.find(n);
        assert(wh != save.end());
        int r = max(n->val, n->val + wh->second.first);
        r = max(r, r + wh->second.second);
        if(n->left)
            r = max(r, calc(n->left, save));
        if(n->right)
            r = max(r, calc(n->right, save));
        return r;
    }
};

class Solution2 {
public:
    int maxPathSum(TreeNode *root) {
        if (!root)
            return 0;
        int r = root->val;
        help(root, r);
        return r;
    }
    int help(TreeNode * root, int & m){
        if (!root)
            return 0;
        int le = help(root->left, m);
        int ri = help(root->right, m);
        int r = max(0, max(le, ri));
        m = max(m, root->val + max(r, le + ri));
        return root->val + r;
    }
};

int main()
{
    {
        TreeNode n1(1), n2(2), n3(3);
        n1.left = &n2;
        n1.right = &n3;
        cout << Solution().maxPathSum(&n1) << endl;
        cout << Solution2().maxPathSum(&n1) << endl;
    }
}
