#include "../inc.h"

class Solution {
public:
    struct Node{
        Node * next[256];    //0, ['a, 'z']
        Node(){memset(next, 0, sizeof next);}
        ~Node(){
            for(int i = 0;i < 256;++i)
                if(next[i])
                    delete next[i];
        }
        Node *& n(char c){
            return next[c];
        }
    };
    void insert(Node & head, const std::string & w) const{
        Node * cur = &head;
        for(size_t i = 0;i < w.size();++i){
            char c = w[i];
            if(!cur->n(c))
                cur->n(c) = new Node();
            cur = cur->n(c);
        }
        if(!cur->n(0))
            cur->n(0) = new Node();
    }
    bool has(Node & head, const std::string & w) const{
        Node * cur = &head;
        for(size_t i = 0;i < w.size();++i){
            char c = w[i];
            if(!cur->n(c))
                return false;
            cur = cur->n(c);
        }
        return (NULL != cur->n(0));
    }

    //I
    bool wordBreakI(string s, unordered_set<string> &dict) {
        //generate trie tree
        Node head;
        for(unordered_set<string>::const_iterator i = dict.begin();i != dict.end();++i)
            insert(head, *i);
        //search words
        return help(s, head);
    }
    //dfs
    //复杂度分析：
    //令T(n)为长为n的s的操作数，单词个数为c，平均长度为w，则有：
    //T(n) = c*(w+T(n-w))，即每次找到一个单词后，都可以减少n；但是如果后面失败，又要回溯继续找；最坏找c次；
    //     = c*(w+c*(w+T(n-2w))) = ... = w*(c + c^2 + c^3 + ... + c^x) + c^x * T(0)
    //其中，x = n / w
    //故最后的复杂度为: O(f) = O(w * c^(n/w + 1))
    bool help(const string & s, Node & head) const{
        if(has(head, s))
            return true;
        for(size_t i = 1;i < s.size();++i){
            if(!has(head, s.substr(i)))
                continue;
            if(help(s.substr(0, i), head))
                return true;
        }
        return false;
    }
    //df, O(S^2) time, O(D) space, D is the char count of dict
    bool wordBreakI2(string s, unordered_set<string> &dict) {
        if (s.empty())
            return true;
        //generate trie tree
        Node head;
        for (unordered_set<string>::const_iterator i = dict.begin(); i != dict.end(); ++i)
            insert(head, *i);
        //init state
        vector<bool> ret(s.size());
        //dp in reverse order
        for (size_t i = s.size() - 1; i < s.size(); --i){
            Node * cur = head.n(s[i]);
            for (size_t j = i + 1; cur && j < s.size(); cur = cur->n(s[j++]))
                if (cur->n(0) && ret[j])
                    break;
            ret[i] = (cur && cur->n(0));
        }
        return ret.front();
    }

    //II
    vector<string> wordBreakII(string s, unordered_set<string> &dict) {
        //generate trie tree
        Node head;
        for(unordered_set<string>::const_iterator i = dict.begin();i != dict.end();++i)
            insert(head, *i);
        //search words
        vector<string> ret;
        help(s, head, string(), ret);
        return ret;
    }
    void help(const string & s, Node & head, string suffix, vector<string> & ret) const{
        if(s.empty()){
            if(!suffix.empty())
                ret.push_back(suffix);
            return;
        }
        for(size_t i = 0;i < s.size();++i){
            if(!has(head, s.substr(i)))
                continue;
            string ss = s.substr(i);
            if(!suffix.empty()){
                ss += ' ';
                ss += suffix;
            }
            help(s.substr(0, i), head, ss, ret);
        }
    }
};

int main()
{
    {
        unordered_set<string> dict;
        dict.insert("a");
        cout << Solution().wordBreakI2("a", dict) << endl;
    }{
        unordered_set<string> dict;
        dict.insert("dog");
        dict.insert("s");
        dict.insert("gs");
        cout << Solution().wordBreakI2("dogs", dict) << endl;
    }{
        unordered_set<string> dict;
        dict.insert("aaaa");
        dict.insert("aa");
        cout << Solution().wordBreakI2("aaaaaaa", dict) << endl;
    }
}
