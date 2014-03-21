#include <iostream>
#include <vector>
#include <cassert>

//O(R*S) solution, R for length of regx, S for lenght of str
class CNode
{
    int cnt_;
    char c_;
public:
    CNode():cnt_(0){}
    explicit CNode(char c):cnt_(1),c_(c){}
    bool setCnt(){
        if('.' == c_)
            return false;
        if(1 != cnt_)
            return false;
        cnt_ = -1;
        return true;
    }
    bool match(const char *& s) const{
        if('.' == c_){
            if(!s || '\0' == *s)
                return false;
            ++s;
            return true;
        }
        bool m = (s && *s == c_);
        if(m){
            ++s;
            return true;
        }
        return (cnt_ < 0);
    }
};

class CRegx
{
    std::vector<CNode> nodes_;
public:
    bool parse(const char * regx){
        nodes_.clear();
        if(!regx)
            return true;
        for(;*regx;++regx){
            if('.' == *regx){
                nodes_.push_back(CNode('.'));
            }else if('*' == *regx){
                if(nodes_.empty())
                    return false;
                if(!nodes_.back().setCnt())
                    return false;
            }else if('a' <= *regx && *regx <= 'z'){
                nodes_.push_back(CNode(*regx));
            }else
                return false;
        }
        return true;
    }
    bool match(const char * str) const{
        if(nodes_.empty())
            return NULL == str || '\0' == *str;
        for(size_t i = 0;i < nodes_.size();++i)
            if(!nodes_[i].match(str))
                return false;
        return true;
    }
};

bool isMatch1(const char * regx, const char * str)
{
    CRegx r;
    if(!r.parse(regx)){
        std::cerr<<"'"<<regx<<"' is not valid regex\n";
        return false;
    }
    return r.match(str);
}

//O(N) solution
bool isMatch2(const char * regx, const char * str)
{
    if(!regx || !*regx){
        return !str || !*str;
    }else if('.' == *regx){
        if(!str || !*str)
            return false;
        return isMatch2(regx + 1, str + 1);
    }else{
        assert('a' <= *regx && *regx <= 'z');
        if('*' == *(regx + 1)){
            if(isMatch2(regx + 2, str)) //so 'a*a' can match 'a'
                return true;
            if(*str != *regx)
                return false;
            return isMatch2(regx + 2, str + 1);
        }else{
            if(!str || *str != *regx)
                return false;
            return isMatch2(regx + 1, str + 1);
        }
    }
    return false;
}

int main()
{
    {
        std::cout<<isMatch1("a*", "")<<"\n";
        std::cout<<isMatch1(".", "")<<"\n";
        std::cout<<isMatch1("ab*", "a")<<"\n";
        std::cout<<isMatch1("a.", "ab")<<"\n";
        std::cout<<isMatch1("a", "a")<<"\n";
        std::cout<<isMatch1("a*a", "a")<<"\n";  //error
    }
    std::cout<<"---\n";
    {
        std::cout<<isMatch2("a*", "")<<"\n";
        std::cout<<isMatch2(".", "")<<"\n";
        std::cout<<isMatch2("ab*", "a")<<"\n";
        std::cout<<isMatch2("a.", "ab")<<"\n";
        std::cout<<isMatch2("a", "a")<<"\n";
        std::cout<<isMatch2("a*a", "a")<<"\n";
    }
}
