#include "..\inc.h"

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
        TreeLinkNode * p = NULL;
        TreeLinkNode * c = root;
        TreeLinkNode * ch = c;
        TreeLinkNode * s = NULL;
        TreeLinkNode * nh = NULL;
        for(;c;s = NULL){
            //set children head
            if(!nh){
                if(c->left)
                    nh = c->left;
                else
                    nh = c->right;
                if(nh)
                    ch = c;
            }
            //find sibling
            if(p){
                if(p->left == c)
                    s = p->right;
                while(!s){
                    p = p->next;
                    if(!p)
                        break;
                    if(p->left)
                        s = p->left;
                    else
                        s = p->right;
                }
            }
            if(s){  //move to sibling
                c->next = s;
                c = s;
            }else{  //move to children
                p = ch;
                c = nh;
                ch = nh = NULL;
            }
        }
    }
};

int main(){}



/*
         1
       /  \
      2    3
     / \    \
    4   5    7
p
c  1
ch
s
n
nh
*/