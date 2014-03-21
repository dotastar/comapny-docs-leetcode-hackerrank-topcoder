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
    bool isSymmetric1(TreeNode *root) {
        if(!root)
            return true;
        return isSymRecur(root->left, root->right);
    }
    bool isSymRecur(TreeNode * t1, TreeNode * t2){
        if(!t1 || !t2)
            return t1 == t2;
        if(t1->val != t2->val)
            return false;
        return isSymRecur(t1->left, t2->right) && isSymRecur(t1->right, t2->left);
    }
    bool isSymmetric2(TreeNode *root) {
        if(!root)
            return true;
        deque<TreeNode *> left, right;
        left.push_back(root->left);
        right.push_back(root->right);
        while(!left.empty() && !right.empty()){
            if(!isEq(left.front(), right.front()))
                return false;
            if(left.front()){
                left.push_back(left.front()->left);
                left.push_back(left.front()->right);
                right.push_back(right.front()->right);
                right.push_back(right.front()->left);
            }
            left.pop_front();
            right.pop_front();
        }
        return left.empty() && right.empty();
    }
    bool isEq(TreeNode * t1, TreeNode * t2){
        if(!t1 || !t2)
            return t1 == t2;
        return t1->val == t2->val;
    }
};


