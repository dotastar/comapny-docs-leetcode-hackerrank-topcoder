#include <cassert>
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <sstream>

int gcd(int a, int b)
{
    assert(a > 0 && b > 0);
    while((a %= b))
        std::swap(a, b);
    return b;
}

template<class Iter>
int gcd(Iter first, Iter last)
{
    int r = 0;
    for(;first != last && 1 != r;++first)
        if(!r)
            r = *first;
        else
            r = gcd(r, *first);
    return r;
}

//O(X * Y) for Y is row len, and X is column len
template<int M, int N>
int calcGcdSlow(const int (&m)[M][N], int x1, int y1, int x2, int y2)
{
    assert(0 <= x1 && x1 <= x2 && x2 < M);
    assert(0 <= y1 && y1 <= y2 && y2 < N);
    int r = 0;
    for(int i = x1;i <= x2 && 1 != r;++i)
        for(int j = y1;j <= y2 && 1 != r;++j)
            if(!r)
                r = m[i][j];
            else
                r = gcd(r, m[i][j]);
    return r;
}

//O(X * log Y) for Y is row len, and X is column len
class CNode
{
    typedef std::list<CNode> __Nodes;
public:
    CNode():parent_(NULL),left_(NULL),right_(NULL),len_(0){}
    template<int N>
    CNode(int s, int l, const int (&a)[N])
        : parent_(NULL)
        , left_(NULL)
        , right_(NULL)
        , start_(s)
        , len_(l)
    {
        gcd_ = gcd(a + s, a + s + l);
    }
    template<int N>
    void buildSub(const int (&a)[N], __Nodes & nodes){
        if(len_ <= 1)
            return;
        int l = len_ / 2;
        nodes.push_back(CNode(start_, l, a));
        setLeft(nodes.back());
        nodes.back().buildSub(a, nodes);
        nodes.push_back(CNode(start_ + l, len_ - l, a));
        setRight(nodes.back());
        nodes.back().buildSub(a, nodes);
    }
    void setLeft(CNode & n){
        n.parent_ = this;
        left_ = &n;
    }
    void setRight(CNode & n){
        n.parent_ = this;
        right_ = &n;
    }
    int calcGcd(int y1, int y2) const{
        assert(y1 <= y2);
        assert(y1 < start_ + len_);
        assert(start_ <= y2);
        if(y1 <= start() && end() <= y2 + 1)
            return gcd_;
        assert(len_ > 1 && left_ && right_);
        if(y2 < left_->end())
            return left_->calcGcd(y1, y2);
        if(y1 >= right_->start())
            return right_->calcGcd(y1, y2);
        return gcd(left_->calcGcd(y1, y2), right_->calcGcd(y1, y2));
    }
    std::string toString() const{
        std::ostringstream oss;
        oss<<"("<<start()<<","<<end()<<","<<gcd_<<")";
        return oss.str();
    }
    CNode * left() const{return left_;}
    CNode * right() const{return right_;}
    int start() const{return start_;}
    int end() const{return start_ + len_;}
private:
    CNode * parent_;
    CNode * left_;
    CNode * right_;
    int start_, len_;
    int gcd_;
};

class CTree
{
    typedef std::list<CNode> __Nodes;
public:
    template<int N>
    void build(const int (&a)[N]){
        nodes_.push_back(CNode(0, N, a));
        nodes_.front().buildSub(a, nodes_);
    }
    int calcGcd(int y1, int y2) const{
        assert(!nodes_.empty());
        return nodes_.front().calcGcd(y1, y2);
    }
    std::string toString() const{
        assert(!nodes_.empty());
        std::vector<const CNode *> lvl;
        lvl.push_back(&nodes_.front());
        std::ostringstream oss;
        while(!lvl.empty()){
            std::vector<const CNode *> tmp;
            for(size_t i = 0;i < lvl.size();++i){
                oss<<lvl[i]->toString()<<" ";
                if(lvl[i]->left())
                    tmp.push_back(lvl[i]->left());
                if(lvl[i]->right())
                    tmp.push_back(lvl[i]->right());
            }
            oss<<"\n";
            lvl.swap(tmp);
        }
        return oss.str();
    }
private:
    __Nodes nodes_;
};

template<int M, int N>
class CGcdInfo
{
public:
    void process(const int (&m)[M][N]){
        trees_.resize(M);
        for(int i = 0;i < M;++i)
            trees_[i].build(m[i]);
    }
    int calcGcd(int x1, int y1, int x2, int y2) const{
        assert(0 <= x1 && x1 <= x2 && x2 < M);
        assert(0 <= y1 && y1 <= y2 && y2 < N);
        assert(!trees_.empty());
        int r = 0;
        for(int i = x1;i <= x2 && 1 != r;++i){
            int g = trees_[i].calcGcd(y1, y2);
            if(!r)
                r = g;
            else
                r = gcd(r, g);
        }
        return r;
    }
    std::string toString() const{
        std::ostringstream oss;
        for(size_t i = 0;i < trees_.size();++i)
            oss<<trees_[i].toString()<<"\n";
        return oss.str();
    }
private:
    std::vector<CTree> trees_;
};

template<int M, int N>
int calcGcdOpt(const CGcdInfo<M, N> & opt, int x1, int y1, int x2, int y2)
{
    return opt.calcGcd(x1, y1, x2, y2);
}

int main()
{
    const int matrix[4][5] = {
        {2400, 6400, 6887300, 79200, 257300},
        {3464700, 566600, 68467300, 793500, 2554600},
        {34684600, 5635300, 786300, 79468400, 3572500},
        {3479500, 56795700, 7467300, 7548900, 2275500},
    };
    {
        std::cout<<calcGcdSlow(matrix, 1, 0, 3, 4)<<"\n";
    }{
        CGcdInfo<4, 5> info;
        info.process(matrix);
        //std::cout<<info.toString();
        std::cout<<calcGcdOpt(info, 1, 0, 3, 4)<<"\n";
    }
    return 0;
}
