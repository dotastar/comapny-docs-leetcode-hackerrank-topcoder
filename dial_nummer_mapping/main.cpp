#include "../inc.h"

vector<string> solve(string s)
{
    const char * kMap[9] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PQR", "STU", "VWX", "YZ"};
    //collect digits
    vector<int> digits;
    vector<int> seq;
    {
        set<int> t;
        for(size_t i = 0;i < s.size();++i){
            int d = s[i] - '1';
            if(0 <= d && d < sizeof kMap / sizeof kMap[0]){
                t.insert(d);
                seq.push_back(d);
            }
        }
        digits.resize(t.size());
        copy(t.begin(), t.end(), digits.begin());
    }
    vector<string> r;
    if(digits.empty())
        return r;
    //iterate index
    const vector<string> map(kMap, kMap + sizeof kMap / sizeof kMap[0]);
    vector<int> idx(digits.size());
    for(;;){
        //gen result
        string t;
        for(size_t i = 0;i < seq.size();++i){
            int ii = seq[i];
            for(size_t j = 0;j < digits.size();++j){
                if(digits[j] == ii){
                    t.push_back(map[ii][idx[j]]);
                    break;
                }
            }
        }
        r.push_back(t);
        //next
        int i = idx.size() - 1;
        for(;i >= 0;--i){
            if(++idx[i] < map[digits[i]].size())
                break;
            idx[i] = 0;
        }
        if(i < 0)
            break;
    }
    return r;
}

int main()
{
    print(solve("112"));
    print(solve("99"));
    print(solve("11299"));
    print(solve("112299"));
}
