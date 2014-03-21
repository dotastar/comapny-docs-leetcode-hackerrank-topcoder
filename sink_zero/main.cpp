#include "../inc.h"

TreeNode * help(TreeNode * root)
{
    if(!root)
        return NULL;
    TreeNode * r = help(root->left);
    if(r)
        return r;
    r = help(root->right);
    if(r)
        return r;
    return (root->val ? root : NULL);
}

void solve(TreeNode * root)
{
    if(!root)
        return;
    if(0 == root->val){
        TreeNode * n = help(root);
        if(!n)
            return;
        swap(n->val, root->val);
    }
    solve(root->left);
    solve(root->right);
}

int main()
{
    {
        TreeNode n[7];
        n[0].left = &n[1];
        n[0].right = &n[2];
        n[1].left = &n[3];
        n[1].right = &n[4];
        n[2].left = &n[5];
        //n[2].right = &n[6];
        n[5].val = 1;

        solve(n);
        print(n);
    }
    {
        TreeNode n[7];
        n[0].left = &n[1];
        n[0].right = &n[2];
        n[1].left = &n[3];
        n[1].right = &n[4];
        n[2].left = &n[5];
        n[2].right = &n[6];
        n[3].val = 2;
        n[4].val = 3;
        n[5].val = 4;
        n[6].val = 5;

        solve(n);
        print(n);
    }
    {
        TreeNode n[7];
        n[0].left = &n[1];
        n[0].right = &n[2];
        n[1].left = &n[3];
        n[1].right = &n[4];
        n[2].left = &n[5];
        n[2].right = &n[6];

        n[1].val = 1;
        n[2].val = 1;
        n[3].val = 2;
        n[4].val = 3;
        n[5].val = 4;
        n[6].val = 5;

        solve(n);
        print(n);
    }
}
