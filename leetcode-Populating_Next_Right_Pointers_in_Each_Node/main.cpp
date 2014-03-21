/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode * h = root;
        while(h && h->left){
            TreeLinkNode * c = h;
            TreeLinkNode * s = NULL;
            while(c){
                if(s)
                    s->next = c->left;
                s = c->left->next = c->right;
                c = c->next;
            }
            h = h->left;
        }
    }
};
