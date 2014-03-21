#include "..\inc.h"

class Solution {
public:
    //I & II
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > r;
        if(num.empty())
            return r;
        sort(num.begin(), num.end());
        r.push_back(num);
        if(num.size() == 1)
            return r;
        for(;;){
            int i = num.size() - 2;
            for(;i >= 0;--i)
                if(num[i] < num[i + 1])
                    break;
            if(i < 0)
                break;
            int j = num.size() - 1;
            for(;j > i;--j)
                if(num[i] < num[j])
                    break;
            assert(i < j);
            swap(num[i], num[j]);
            reverse(num, i + 1);
            r.push_back(num);
        }
    }
    void reverse(vector<int> &num, int from){
        for(int to = num.size() - 1;from < to;++from, --to)
            swap(num[from], num[to]);
    }

    void nextPermutation(vector<int> &num) {
        if(num.size() < 2)
            return;
        int i = num.size() - 2;
        for(;i >= 0;--i)
            if(num[i] < num[i + 1])
                break;
        if(i < 0){
            reverse(num, 0);
            return;
        }
        int j = num.size() - 1;
        for(;j > i;--j)
            if(num[j] > num[i])
                break;
        swap(num[i], num[j]);
        reverse(num, i + 1);
    }

    string getPermutation(int n, int k) {
        string r;
        if(n <= 0)
            return r;
        //calc (n-1)!
        int nn = 1;
        for(int i = 2;i < n;++i)
            nn *= i;
        //push char
        assert(k > 0);
        --k;
        vector<bool> used(n);
        for(int i = n - 1;i > 0;--i){
            int idx = k / nn;
            int j = 0, c = 0;
            for(;j < n;++j){
                if(used[j])
                    continue;
                if(++c > idx)
                    break;
            }
            r.push_back(j + '1');
            used[j] = true;
            k %= nn;
            nn /= i;
        }
        for(int i = 0;i < n;++i)
            if(!used[i])
                r.push_back(i + '1');
        return r;
    }
};


int main()
{
    cout<<Solution().getPermutation(3, 1)<<endl;
    cout<<Solution().getPermutation(3, 2)<<endl;
    cout<<Solution().getPermutation(3, 3)<<endl;
}