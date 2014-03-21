#include "../inc.h"

class Node
{
public:
    Node(){memset(next_, 0, sizeof next_);}
    ~Node(){
        for(int i = 0;i < 27;++i)
            delete next_[i];
    }
    Node * next(char c) const{
        assert(!c || ('a' <= c && c <= 'z'));
        return (!c ? next_[0] : next_[c - 'a' + 1]);
    }
    void next(char c, Node * n){
        assert(!c || ('a' <= c && c <= 'z'));
        if(!c)
            next_[0] = n;
        else
            next_[c - 'a' + 1] = n;
    }
private:
    Node * next_[27];   //NULL + a-z
};

bool dfs(const Node * cur, vector<int> & charset, const Node * root)
{
    assert(cur);
    if(cur->next(0)){
        bool e = true;
        for(size_t i = 0;e && i < charset.size();++i)
            if(charset[i])
                e = false;
        if(e)
            return true;
        vector<int> t(charset);
        if(dfs(root, t, root))
            return true;
    }
    for(size_t i = 0;i < charset.size();++i){
        if(!charset[i])
            continue;
        Node * c = cur->next(i + 'a');
        if(c){
            vector<int> t(charset);
            --t[i];
            if(dfs(c, t, root))
                return true;
        }
    }
    return false;
}

void uniform(string & w)
{
    sort(w.begin(), w.end());
    return;
    vector<int> charset(26); //a-z
    for(size_t i = 0;i < w.size();++i){
        assert('a' <= w[i] && w[i] <= 'z');
        ++charset[w[i] - 'a'];
    }
    w.clear();
    for(int i = 0;i < 26;++i)
        if(charset[i] > 0)
            w.append(charset[i], 'a' + i);
}

bool solve(const string & chars, const vector<string> & dict)
{
    if(chars.empty())
        return true;
    if(dict.empty())
        return false;
    //construct Trie
    Node trie;
    for(size_t i = 0;i < dict.size();++i){
        string word = dict[i];
        if(word.empty())
            continue;
        uniform(word);
        Node * cur = &trie;
        for(size_t j = 0;j < word.size();++j){
            char c = word[j];
            assert(cur);
            if(!cur->next(c))
                cur->next(c, new Node);
            cur = cur->next(c);
        }
        if(!cur->next(0))   //word end
            cur->next(0, new Node);
    }
    //sort chars
    vector<int> charset(26); //a-z
    for(size_t i = 0;i < chars.size();++i){
        assert('a' <= chars[i] && chars[i] <= 'z');
        ++charset[chars[i] - 'a'];
    }
    //dfs
    return dfs(&trie, charset, &trie);

}

int main()
{
    if(0){
        const char * d[] = {"hello", "world", "is", "my", "first", "program"};
        vector<string> dict(d, d + sizeof d / sizeof d[0]);
        cout<<solve("iifrsst", dict)<<endl;
    }
    if(0){
        const char * d[] = {"hello", "world", "is", "my", "first", "program"};
        vector<string> dict(d, d + sizeof d / sizeof d[0]);
        cout<<solve("eiifrsst", dict)<<endl;
    }
    {
        vector<string> dict;
        ifstream inf("save.txt");
        for(string w;!inf.eof();){
            if(!getline(inf, w))
                break;
            dict.push_back(w);
        }

        cout<<solve("dfjdnfnendndjaendangezef", dict)<<endl;
        //cout<<solve("avoidthisyyrpomptoksenoughwritingaboutwritingcodehthecodeitselfmuchmoreinterestingma", dict)<<endl;
    }
}
