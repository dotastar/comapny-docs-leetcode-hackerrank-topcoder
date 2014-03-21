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
        return cur->n(0);
    }

    //I
    bool wordBreak(string s, unordered_set<string> &dict) {
        //generate trie tree
        Node head;
        for(unordered_set<string>::const_iterator i = dict.begin();i != dict.end();++i)
            insert(head, *i);
        //search words
        return help(s, head);
    }
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

    //II
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
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
                ss.append(' ');
                ss += suffix;
            }
            help(s.substr(0, i), head, ss, ret);
        }
    }
};
