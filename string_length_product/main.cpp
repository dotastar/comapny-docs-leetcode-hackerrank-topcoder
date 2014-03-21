#include "../inc.h"

int help(const string & s)
{
    int r = 0;
    for(size_t i = 0;i < s.size();++i) {
        assert('a' <= s[i] && s[i] <= 'z');
        r |= (1 << (s[i] - 'a'));
    }
    return r;
}

struct CInfo
{
    int len_;
    int index_;
    CInfo():len_(0),index_(-1){}
};

struct CLenComp
{
    bool operator ()(const pair<int, CInfo> & p1, const pair<int, CInfo> & p2) const{
        return p1.second.len_ < p2.second.len_;
    }
};

//idx1, idx2: used to track the string index, debug only
int solve(const vector<string> & dict, int & idx1, int & idx2)
{
    //calc max length for all charset bits
    map<int, CInfo> bits2len;
    for(size_t i = 0;i < dict.size();++i){
        if(dict[i].empty())
            continue;
        CInfo & j = bits2len[help(dict[i])];
        if(j.len_ < dict[i].size()){
            j.len_ = dict[i].size();
            j.index_ = i;
        }
    }
    if(bits2len.size() < 2)
        return 0;
    //sort by length
    vector<pair<int, CInfo> > len2bits;   //[bits, len]
    copy(bits2len.begin(), bits2len.end(), back_inserter(len2bits));
    sort(len2bits.begin(), len2bits.end(), CLenComp());
    //iterate len2bits
    int r = 0;
    for(int i = len2bits.size() - 1, e = 0;i >= e;--i){
        for(int j = i - 1;j >= e;--j){
            if(0 == (len2bits[i].first & len2bits[j].first)){
                int ri = len2bits[i].second.len_ * len2bits[j].second.len_;
                if(ri > r){
                    r = ri;
                    idx1 = len2bits[i].second.index_;
                    idx2 = len2bits[j].second.index_;
                }
                e = max(j, e);
            }
        }
    }

    return r;
}

void genTest(const char * fname, vector<string> & r)
{
    ifstream inf(fname);
    if(!inf.is_open()){
        cerr<<"cannot open file '"<<fname<<"'\n";
        return;
    }
    srand(time(NULL));
    for(string w;!inf.eof();){
        if(!(inf>>w)){
            cerr<<"read file '"<<fname<<"' error\n";
            return;
        }
        if(w.empty())
            continue;
        for(size_t i = 0;i < w.size();++i){
            if('A' <= w[i] && w[i] <= 'Z')
                w[i] += 'a' - 'A';
            if('a' <= w[i] && w[i] <= 'z')
                continue;
            w[i] = rand() % 26 + 'a';
        }
        r.push_back(w);
    }
}

int main()
{
    vector<string> dict;
    genTest("test.txt", dict);
    cout<<"dict size: "<<dict.size()<<endl;
    do{   //save to file
        ofstream outf("save.txt");
        if(!outf.is_open()){
            cerr<<"cannot open 'save.txt'\n";
            break;
        }
        for(size_t i = 0;i < dict.size();++i)
            outf<<dict[i]<<'\n';
    }while(false);
    //solve
    int idx1, idx2;
    cout<<"product: "<<solve(dict, idx1, idx2)<<endl;
    cout<<"strings at pos: "<<idx1<<", "<<idx2<<endl;
    cout<<dict[idx1]<<endl;
    cout<<dict[idx2]<<endl;
}
