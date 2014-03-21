#include "../inc.h"

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        struct Node{
            int idx_;
            Node * next_[27];   //NULL + 'a' to 'z'
            Node(int i = -1):idx_(i){memset(next_, 0, sizeof next_);}
            ~Node(){
                for(int i = 0;i < 27;++i)
                    delete next_[i];
            }
            Node *& n(char c){return next_[c ? c - 'a' + 1 : 0];}
        };
        vector<int> r;
        if(S.empty())
            return r;
        map<string, int> cnt;
        for(size_t i = 0;i < L.size();++i)
            ++cnt[L[i]];
        //construct trie tree
        Node root;
        size_t len = 0;
        for(size_t i = 0;i < L.size();++i){
            const string & s = L[i];
            len += s.size();
            Node * cur = &root;
            for(size_t j = 0;j < s.size();++j){
                if(!cur->n(s[j]))
                    cur->n(s[j]) = new Node();
                cur = cur->n(s[j]);
            }
            cur->idx_ = i;
        }
        //search
        if(len > S.size())
            return r;
        vector<bool> bs;
        for(size_t i = 0;i <= S.size() - len;++i){
            map<string, int> m;
            bool fail = false;
            for(size_t j = 0;!fail && j < L.size();++j){
                Node * cur = &root;
                for(size_t k = 0;k < L[0].size();++k){
                    char c = S[i + j * L[0].size() + k];
                    if(!cur->n(c)){
                        fail = true;
                        break;
                    }
                    cur = cur->n(c);
                }
                if(!fail){
                    assert(cur->idx_ >= 0);
                    const string & s = L[cur->idx_];
                    int & c = m[s];
                    if(++c > cnt[s]){
                        fail = true;
                        break;
                    }
                }
            }
            if(!fail)
                r.push_back(i);
        }
        return r;
    }
};

int main()
{
    {
        vector<string> L;
        L.push_back("abc");
        L.push_back("bcd");
        L.push_back("cde");
        string S = "abcdcdeabccdebcd";
        print(Solution().findSubstring(S, L));
    }{
        vector<string> L;
        L.push_back("aaa");
        L.push_back("aaa");
        L.push_back("aaa");
        string S = "aaaaaaaaaaaaaa";
        print(Solution().findSubstring(S, L));
    }
}
