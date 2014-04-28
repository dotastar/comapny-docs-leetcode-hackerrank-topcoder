#include "../inc.h"

void help(TreeNode * parent, TreeNode * cur, const vector<int> & preorder, size_t & idx)
{
    if(idx >= preorder.size())
        return;
    assert(cur);
    if(preorder[idx] < cur->val) {
        if(!cur->left)
            cur->left = new TreeNode(preorder[idx++]);
        help(cur, cur->left, preorder, idx);
    }
    while(idx < preorder.size() && (!parent || preorder[idx] < parent->val)) {
        if(!cur->right)
            cur->right = new TreeNode(preorder[idx++]);
        help(parent, cur->right, preorder, idx);
    }
}

TreeNode * solve(const vector<int> & preorder)
{
    if(preorder.empty())
        return NULL;
    TreeNode * root = new TreeNode(preorder[0]);
    size_t idx = 1;
    help(NULL, root, preorder, idx);
    return root;
}

int main()
{
    srand(time(NULL));
    print(solve({8, 4, 2, 6, 5, 7, 12, 10, 14}));
    {
        vector<int> s;
        for(size_t i = 0; i < 10; ++i)
            s.push_back(i + 1);
        random_shuffle(s.begin(), s.end());
        cout << "---\n";
        print(s);
        print(solve(s));
    }
}