#include "..\inc.h"

//dic: input dictionary
//return: string of length 26, each char represents replacement of character from 'a' to 'z'
string solve(const vector<string> & dic)
{
    assert(!dic.empty());
    //calc chars' new order
    vector<set<char> > comp(26);
    for(size_t i = 0;i < dic.size() - 1;++i){
        const string & s1 =dic[i];
        const string & s2 =dic[i + 1];
        for(size_t j = 0;j < s1.size();++j){
            assert(j < s2.size());
            if(s1[j] == s2[j])
                continue;
            char c1 = s1[j], c2 = s2[j];
            assert('a' <= c1 && c1 <= 'z');
            assert('a' <= c2 && c2 <= 'z');
            comp[c2 - 'a'].insert(c1);
            break;
        }
    }
    //get new seq
    string ret;
    for(int c = 0;c < 26;++c){
        for(size_t i = 0;i < comp.size();++i){
            set<char> & s = comp[i];
            if(s.size() > ret.size())
                continue;
            if(ret.empty()){    //replace for 'a'
                ret.push_back(i + 'a');
                break;
            }
            if(1 > s.count(*ret.rbegin()))  //the next char must be larger than the last char of ret
                continue;
            bool ok = true;
            for(set<char>::const_iterator it = s.begin();it != s.end();++it){
                if(string::npos == ret.find(*it)){  //all chars less than the next char must be in ret
                    ok = false;
                    break;
                }
            }
            if(ok){
                ret.push_back(i + 'a');
                s.clear();
                break;
            }
        }
    }
    return ret;
}

//fname: input file contains words of random order
//dic: sorted dictionary with some characters replaced
void test(const char * fname, const string & replace, vector<string> & dic)
{
    //read words and modify the invalid chars if neccessary
    assert(fname);
    ifstream inf(fname);
    if(!inf.is_open()){
        cerr<<"cannot open file '"<<fname<<"'\n";
        return;
    }
    srand(int(time(0)));
    for(string w;!inf.eof();w.clear()){
        if(!(inf>>w)){
            cerr<<"cannot read file '"<<fname<<"'\n";
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
        dic.push_back(w);
    }
    cout<<"dictionary size: "<<dic.size()<<endl;
    //sort
    sort(dic.begin(), dic.end());
    //replace chars
    assert(replace.size() == 26);
    for(size_t i = 0;i < dic.size();++i){
        string & s = dic[i];
        for(size_t j = 0;j < s.size();++j)
            s[j] = replace[s[j] - 'a'];
    }
}


int main()
{
    const string replace = "asdfghjklzxcvbnmqwertyuiop";
    vector<string> dic;
    test("test.txt", replace, dic);
    string ret = solve(dic);
    cout<<"replace = "<<replace<<endl
        <<"ret     = "<<ret<<endl;
}