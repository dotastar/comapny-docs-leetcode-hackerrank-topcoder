#include "../inc.h"

class Solution {
public:
    //O(N * logN)
    int longestConsecutive1(vector<int> &num) {
        if(num.size() < 2)
            return num.size();
        sort(num.begin(), num.end());
        int r = 1, c = 1;
        for(size_t i = 1;i < num.size();++i){
            if(num[i - 1] == num[i])
                continue;
            if(num[i - 1] + 1 == num[i]){
                if(++c > r)
                    r = c;
            }else
                c = 1;
        }
        return r;
    }
    //O(N)
    int longestConsecutive2(vector<int> &num) {
        if(num.size() < 2)
            return num.size();
        unordered_map<int, bool> m;     //num -> used
        for(size_t i = 0;i < num.size();++i)
            m[num[i]] = false;
        int r = 0;
        for(unordered_map<int, bool>::iterator it = m.begin();it != m.end();++it){
            if(it->second)
                continue;
            it->second = true;  //used
            int r1 = 1;
            for(;;++r1){
                cout<<"r1: "<<(it->first - r1)<<endl;
                unordered_map<int, bool>::iterator wh = m.find(it->first - r1);
                if(wh == m.end())
                    break;
                wh->second = true;
            }
            int r2 = 1;
            for(;;++r2){
                cout<<"r2: "<<(it->first + r2)<<endl;
                unordered_map<int, bool>::iterator wh = m.find(it->first + r2);
                if(wh == m.end())
                    break;
                wh->second = true;
            }
            r1 += r2 - 1;
            if(r1 > r)
                r = r1;
        }
        return r;
    }
};

int main()
{
    vector<int> n;
    n.push_back(0);
    n.push_back(-1);
    cout<<Solution().longestConsecutive2(n)<<endl;
}
