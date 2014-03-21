#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <list>
#include <cassert>

class CNode
{
    CNode * next_[27];  //\0, a - z
public:
    CNode(){
        memset(next_, 0, sizeof next_);
    }
    CNode * next(char c){
        if(!c)
            return next_[0];
        if('a' <= c && c <= 'z')
            return next_[c - 'a' + 1];
        if('A' <= c && c <= 'Z')
            return next_[c - 'A' + 'a' + 1];
        return NULL;
    }
    const CNode * next(char c) const{
        if(!c)
            return next_[0];
        if('a' <= c && c <= 'z')
            return next_[c - 'a' + 1];
        if('A' <= c && c <= 'Z')
            return next_[c - 'A' + 'a' + 1];
        return NULL;
    }
    void next(char c, CNode * n){
        assert(n);
        if(c){
            assert('a' <= c && c <= 'z');
            next_[c - 'a' + 1] = n;
        }else
            next_[0] = n;
    }
    bool findWord(const char * w) const{
        assert(w);
        const CNode * n = next(*w);
        if(!n)
            return false;
        if(!*w)
            return true;
        return n->findWord(w + 1);
    }
};

class CTrie
{
    std::list<CNode> nodes_;
    CNode head_;
public:
    void addWord(const std::string & w){
        if(w.empty())
            return;
        CNode * cur = &head_;
        for(size_t i = 0;i < w.size();++i){
            CNode * n = cur->next(w[i]);
            if(!n){
                nodes_.push_back(CNode());
                n = &nodes_.back();
                cur->next(w[i], n);
            }
            cur = n;
        }
        nodes_.push_back(CNode());
        cur->next(0, &nodes_.back());
    }
    bool findWord(const std::string & w) const{
        if(w.empty())
            return false;
        return head_.findWord(w.c_str());
    }
};

void prepare(CTrie & t, const std::list<std::string> words)
{
    for(std::list<std::string>::const_iterator i = words.begin();i != words.end();++i)
        t.addWord(*i);
}

bool isValid(const CTrie & t, const std::string & str)
{
    std::istringstream iss(str);
    for(std::string w;(iss>>w);)
        if(!t.findWord(w))
            return false;
    return true;
}

int main()
{
    const char * words[] = {"this", "is", "what", "i", "say"};
    const char * strings[] = {
        "this is what i say",
        "this is not what i say",
        "this is th say"
    };

    std::list<std::string> w(words, words + sizeof words / sizeof words[0]);
    CTrie t;
    prepare(t, w);

    for(size_t i = 0;i < sizeof strings / sizeof strings[0];++i)
        std::cout<<isValid(t, strings[i])<<"\n";
    return 0;
}