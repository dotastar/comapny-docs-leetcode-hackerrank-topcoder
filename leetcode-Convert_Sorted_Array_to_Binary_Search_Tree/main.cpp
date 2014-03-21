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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return help(num, 0, num.size());
    }
    TreeNode *help(vector<int> &num, int from, int cnt) {
        if(cnt <= 0)
            return NULL;
        int mid = cnt / 2;
        TreeNode * r = new TreeNode(num[from + mid]);
        r->left = help(num, from, mid);
        r->right = help(num, from + mid + 1, cnt - mid - 1);
        return r;
    }
};

/*
   1 2 3

*/
