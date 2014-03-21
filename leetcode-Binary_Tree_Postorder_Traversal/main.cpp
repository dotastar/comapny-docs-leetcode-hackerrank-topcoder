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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        if(!root)
            return ret;
        vector<TreeNode *> v;
        TreeNode * cur = root;
        for(bool s = true;;){
            if(s){
                for(;;){
                    if(cur->left){
                        v.push_back(cur);
                        cur = cur->left;
                    }else if(cur->right){
                        v.push_back(cur);
                        cur = cur->right;
                    }else
                        break;
                }
            }
            ret.push_back(cur->val);
            if(v.empty())
                break;
            TreeNode * p = v.back();
            if(p->left == cur && p->right){
                cur = p->right;
                s = true;
            }else{
                cur = p;
                v.pop_back();
                s = false;
            }
        }
        return ret;
    }
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        if(!root)
            return ret;
        vector<TreeNode *> v;
        TreeNode * cur = root;
        for(bool s = true;;){
            if(s){
                ret.push_back(cur->val);
                if(cur->left){
                    v.push_back(cur);
                    cur = cur->left;
                    continue;
                }else if(cur->right){
                    v.push_back(cur);
                    cur = cur->right;
                    continue;
                }
            }
            if(v.empty())
                break;
            TreeNode * p = v.back();
            if(p->left == cur && p->right){
                cur = p->right;
                s = true;
            }else{
                cur = p;
                v.pop_back();
                s = false;
            }
        }
        return ret;
    }
};
