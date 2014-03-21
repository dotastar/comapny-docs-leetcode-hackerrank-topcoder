#include <iostream>
#include <cassert>

struct CNode
{
    CNode * left_;
    CNode * right_;
    int v_;
    explicit CNode(int v, CNode * l = NULL, CNode * r = NULL):left_(l),right_(r),v_(v){}
};

namespace m1{
    bool isSubBst(const CNode * n, int min, int max)
    {
        if(!n)
            return true;
        assert(min <= max);
        if(n->v_ < min || n->v_ > max)
            return false;
        if(n->v_ > min){
            if(!isSubBst(n->left_, min, n->v_ - 1))
                return false;
        }else if(n->left_)
            return false;
        if(n->v_ < max){
            if(!isSubBst(n->right_, n->v_ + 1, max))
                return false;
        }else if(n->right_)
            return false;
        return true;
    }
    bool isBST(const CNode * n)
    {
        return isSubBst(n, 0x80000000, 0x7FFFFFFF);
    }
}

namespace m2{
    //allow duplicate node
    bool isSubBst(const CNode * n, int min, int max)
    {
        if(!n)
            return true;
        assert(min <= max);
        if(n->v_ < min || n->v_ > max)
            return false;
        return isSubBst(n->left_, min, n->v_)
            && isSubBst(n->right_, n->v_, max);
    }
    bool isBST(const CNode * n)
    {
        return isSubBst(n, 0x80000000, 0x7FFFFFFF);
    }
}

int main()
{
    CNode n2(2);
    CNode n11(11);
    CNode n4(4, &n2, &n11);
    CNode n10(10);
    CNode n8(8, &n4, &n10);

    std::cout<<m1::isBST(&n8)<<"\n";
    std::cout<<"---\n";
    std::cout<<m2::isBST(&n8)<<"\n";
    return 0;
}
