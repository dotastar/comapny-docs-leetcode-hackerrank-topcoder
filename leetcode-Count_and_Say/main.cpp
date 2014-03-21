#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string r("1");
        while(n-- > 1){
            string t;
            int c = 1;
            for(size_t i = 1;i < r.size();++i){
                if(r[i] == r[i - 1]){
                    ++c;
                }else{
                    t.push_back('0' + c);
                    t.push_back(r[i - 1]);
                    c = 1;
                }
            }
            t.push_back('0' + c);
            t.push_back(*r.rbegin());
            t.swap(r);
        }
        return r;
    }
};

int main()
{
    cout<<Solution().countAndSay(1)<<endl;
    cout<<Solution().countAndSay(2)<<endl;
    cout<<Solution().countAndSay(3)<<endl;
    cout<<Solution().countAndSay(4)<<endl;
    cout<<Solution().countAndSay(5)<<endl;
}
