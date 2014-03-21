#include "../inc.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size() < num2.size())
            num1.swap(num2);
        if(num2.empty())
            return "0";
        string r;
        for(size_t i = 0;i < num2.size();++i)
            help(r, i, num1, *(num2.rbegin() + i) - '0');
        //rm '0' in tail
        while(!r.empty() && 0 == *r.rbegin())
            r.resize(r.size() - 1);
        if(r.empty())
            return "0";
        //reverse & add '0'
        for(size_t i = 0, j = r.size() - 1;i < j;++i,--j)
            swap(r[i], r[j]);
        for(size_t i = 0;i < r.size();++i)
            r[i] += '0';
        return r;
    }
    void help(string & r, size_t h, const string & num, int m){
        for(size_t i = 0;i < num.size();++i){
            int v = m * (*(num.rbegin() + i) - '0');
            if(h + i < r.size()){
                r[h + i] += v;
            }else
                r.push_back(v);
        }
        assert(!r.empty());
        for(size_t i = 0;i < r.size() - 1;++i)
            if(r[i] >= 10){
                r[i + 1] += r[i] / 10;
                r[i] %= 10;
            }
        if(*r.rbegin() >= 10){
            int v = *r.rbegin() / 10;
            *r.rbegin() %= 10;
            r.push_back(v);
        }
    }
};

int main()
{
    cout<<Solution().multiply("123", "456")<<endl;
    cout<<Solution().multiply("123", "0")<<endl;
}
