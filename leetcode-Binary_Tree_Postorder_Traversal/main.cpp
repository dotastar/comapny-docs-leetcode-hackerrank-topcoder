#include "../inc.h"

class Solution1 {
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

class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> r;
        vector<TreeNode *> s;
        for (TreeNode *c = root, *p = NULL; c || !s.empty();){
            for (; c; c = c->left)
                s.push_back(c);
            c = s.back();
            if (!c->right || p == c->right){
                r.push_back(c->val);
                s.pop_back();
                p = c;
                c = NULL;
            } else
                c = c->right;
        }
        return r;
    }
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> r;
        vector<TreeNode *> s;
        for (TreeNode *c = root; c || !s.empty();){
            for (; c; c = c->left){
                r.push_back(c->val);
                s.push_back(c);
            }
            c = s.back()->right;
            s.pop_back();
        }
        return r;
    }
};

int main()
{

}