#include <string>
#include <cassert>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

namespace m1{

int signature(const std::string & s)
{
    int r = 0;
    for(size_t i = 0;i < s.size();++i)
        r += int(s[i]) * s[i];
    return r;
}

//O(S^2)
bool is_permutation(const std::string & s1, const std::string & s2)
{
    if(s1.size() != s2.size())
        return false;
    size_t i = 0;
    for(;i < s1.size();++i)
        if(s1[i] != s2[i])
            break;
    if(i == s1.size())
        return true;   //equal
    for(;i < s1.size();++i){
        if(s1.find(s1[i]) == i){
            int n = std::count(s2.begin(), s2.end(), s1[i]);
            if(!n || n != std::count(s1.begin() + i, s1.end(), s1[i]))
                return false;
        }
    }
    return true;
}

class CNode
{
    std::string s_;
    int sig_;
public:
    CNode():sig_(0){}
    explicit CNode(const std::string & s):s_(s),sig_(signature(s)){}
    bool operator <(const CNode & a) const{
        return sig_ < a.sig_;
    }
    const std::string & str() const{return s_;}
    bool match(const CNode & n) const{
        if(sig_ != n.sig_)
            return false;
        return is_permutation(s_, n.s_);
    }
};

void printAnagram(const std::vector<std::string> & v)
{
    if(v.size() < 2)
        return;
    std::vector<CNode> vnode;
    //O(N*S)
    for(size_t i = 0;i < v.size();++i)
        vnode.push_back(CNode(v[i]));
    //O(N*logN)
    std::sort(vnode.begin(), vnode.end());
    size_t a = 0;
    //O(N*S^2)
    for(size_t i = 1;i < vnode.size();++i){
        if(vnode[a].match(vnode[i])){
            if(a + 1 == i)
                std::cout<<"{"<<vnode[a].str();
            std::cout<<","<<vnode[i].str();
        }else{
            if(a + 1 < i)
                std::cout<<"}\n";
            a = i;
        }
    }
    if(a + 1 < vnode.size())
        std::cout<<"}\n";
}

}//namespace m1

namespace m2{

//O(S)
std::string sort(const std::string & s)
{
    int c[256] = {0};
    for(size_t i = 0;i < s.size();++i)
        ++c[int(s[i])];
    std::string r;
    for(int i = 0;i < 256;++i)
        if(c[i])
            r.append(c[i], i);
    return r;
}

struct CNode
{
    CNode * next_[256];
    int idx_;
    std::string s_;
    CNode():idx_(-1){
        memset(next_, 0, sizeof next_);
    }
};

class CTrie
{
    std::list<CNode> nodes_;
    CNode head_;
public:
    CTrie():nodes_(1){} //for NULL node
    void insert(const std::string & s, const std::string & ss){
        CNode * cur = &head_;
        for(size_t i = 0;i < s.size();++i){
            assert(cur);
            int c = s[i];
            if(!cur->next_[c]){
                nodes_.push_back(CNode());
                cur->next_[c] = &nodes_.back();
            }
            cur = cur->next_[c];
        }
        assert(!nodes_.empty());
        cur->s_ = ss;
        cur->next_[0] = &nodes_.front();
    }
    bool find(const std::string & s, int *& n, std::string & ss){
        CNode * cur = &head_;
        for(size_t i = 0;i < s.size();++i){
            assert(cur);
            int c = s[i];
            if(!cur->next_[c])
                return false;
            cur = cur->next_[c];
        }
        n = &cur->idx_;
        ss = cur->s_;
        return cur->next_[0];   //mind partial match
    }
};

void printAnagram(const std::vector<std::string> & v)
{
    if(v.size() < 2)
        return;
    CTrie t;
    std::vector<std::vector<std::string> > vv;
    for(size_t i = 0;i < v.size();++i){
        std::string s = sort(v[i]);
        int * n = NULL;
        std::string ss;
        if(t.find(s, n, ss)){
            assert(n);
            if(*n < 0){
                *n = vv.size();
                vv.resize(*n + 1);
                vv[*n].push_back(ss);
            }
            assert(*n < int(vv.size()));
            vv[*n].push_back(v[i]);
        }else
            t.insert(sort(v[i]), v[i]);
    }
    for(size_t i = 0;i < vv.size();++i){
        std::cout<<"{";
        for(size_t j = 0;j < vv[i].size();++j){
            if(j)
                std::cout<<",";
            std::cout<<vv[i][j];
        }
        std::cout<<"}\n";
    }
}

}//namespace m2

int main()
{
    std::vector<std::string> v;
    v.push_back("star");
    v.push_back("rats");
    v.push_back("ice");
    v.push_back("cie");
    v.push_back("arts");

    m1::printAnagram(v);
    std::cout<<"---\n";
    m2::printAnagram(v);

}
