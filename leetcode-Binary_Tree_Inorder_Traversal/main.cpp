#include "../inc.h"

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

//recursion version
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> r;
        help(root, r);
        return r;
    }
    void help(TreeNode *root, vector<int> & r){
        if (!root)
            return;
        help(root->right, r);
        r.push_back(root->val);
        help(root->right, r);
    }
};

//iteration version
class Solution3 {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> r;
        vector<TreeNode *> s;
        for (TreeNode * c = root; c || !s.empty();){
            for (; c && c->left; c = c->left)
                s.push_back(c);
            if (!c){
                c = s.back();
                s.pop_back();
            }
            r.push_back(c->val);
            c = c->right;
        }
        return r;
    }
};

int main()
{
}
