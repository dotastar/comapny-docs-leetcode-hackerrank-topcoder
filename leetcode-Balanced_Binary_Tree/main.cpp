#include <vector>
#include <iostream>

using namespace std;


//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced1(TreeNode *root) {
        if(!root)
            return true;
        vector<TreeNode *> v(1, root), t;
        for(bool f = true;!v.empty();t.clear()){
            bool e = true;
            for(size_t i = 0;i < v.size();++i){
                if(v[i]->left){
                    if(!f)
                        return false;
                    t.push_back(v[i]->left);
                }else
                    e = false;
                if(v[i]->right){
                    if(!f)
                        return false;
                    t.push_back(v[i]->right);
                }else
                    e = false;
            }
            f = e;
            v.swap(t);
        }
        return true;
    }
    bool isBalanced2(TreeNode *root) {
        if(!root)
            return true;
        int l = height(root->left);
        int r = height(root->right);
        if(!(r - 1 <= l && l <= r + 1))
            return false;
        return isBalanced2(root->left) && isBalanced2(root->right);
    }
    int height(TreeNode * root){
        if(!root)
            return 0;
        int l = 1 + height(root->left);
        int r = 1 + height(root->right);
        return (l > r ? l : r);
    }
};

int main()
{
    TreeNode n1(1), n2(2);
    n1.right = &n2;
    cout<<Solution().isBalanced1(&n1)<<endl;
}
