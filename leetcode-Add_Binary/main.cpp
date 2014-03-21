#include "../inc.h"

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size())
            a.swap(b);
        if(b.empty())
            return a;
        //reverse a
        for(size_t i = 0, j = a.size() - 1;i < j;++i, --j)
            swap(a[i], a[j]);
        //add b
        for(size_t i = 0;i < b.size();++i){
            char c = b[b.size() - 1 - i];
            for(size_t j = i;'1' == c && j < a.size();++j){
                if('0' == a[j]){
                    a[j] = '1';
                    c = '0';
                }else
                    a[j] = '0';
            }
            if('1' == c)
                a.push_back('1');
        }
        //reverse a again
        for(size_t i = 0, j = a.size() - 1;i < j;++i, --j)
            swap(a[i], a[j]);
        return a;
    }
};

int main()
{
    cout<<Solution().addBinary("11101", "1101")<<endl;
}
