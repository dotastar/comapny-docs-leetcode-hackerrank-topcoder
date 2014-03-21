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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        assert(inorder.size() == postorder.size());
        return help(inorder, postorder, 0, 0, postorder.size());
    }
    TreeNode * help(vector<int> &inorder, vector<int> &postorder, size_t ifrom, size_t pfrom, size_t len){
        if(!len)
            return NULL;
        assert(pfrom + len <= postorder.size());
        TreeNode * n = new TreeNode(postorder[pfrom + len - 1]);
        size_t i = 0;
        for(;i < len;++i)
            if(inorder[ifrom + i] == n->val)
                break;
        assert(i < len);
        n->left = help(inorder, postorder, ifrom, pfrom, i);
        n->right = help(inorder, postorder, ifrom + i + 1, pfrom + i, len - i - 1);
        return n;
    }
};

int main()
{
    vector<int> in, po;
    in.push_back(1);
    in.push_back(2);
    po.push_back(2);
    po.push_back(1);

    Solution().buildTree(in, po);
}
