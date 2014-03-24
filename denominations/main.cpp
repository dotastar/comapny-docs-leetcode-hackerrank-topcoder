#include "../inc.h"

namespace m1{
    bool hasDuplicate(const std::vector<int> & vec)
    {
        for(size_t i = 0;i < vec.size();++i)
            for(size_t j = i + 1;j < vec.size();++j)
                if(vec[i] == vec[j])
                    return true;
        return false;
    }

    int sum(const std::vector<int> & donoms, const std::vector<int> & cnt)
    {
        assert(!donoms.empty() && donoms.size() == cnt.size());
        int ret = 0;
        for(size_t i = 0;i < cnt.size();++i)
            ret += donoms[i] * cnt[i];
        return ret;
    }

    void print(const std::vector<int> & donoms, const std::vector<int> & cnt)
    {
        assert(!donoms.empty() && donoms.size() == cnt.size());
        int c = 0;
        for(size_t i = 0;i < cnt.size();++i){
            if(c)
                std::cout<<" + ";
            std::cout<<donoms[i]<<"*"<<cnt[i];
            ++c;
        }
        std::cout<<"\n";
    }

    int findWays1(int amount, const std::vector<int> & donoms)
    {
        assert(!hasDuplicate(donoms));
        std::vector<int> cnt(donoms.size());
        int ret = 0;
        for(;;){
            int s = sum(donoms, cnt);
            if(s >= amount){
                if(s == amount){
                    ++ret;
                    print(donoms, cnt);
                }
                int i = cnt.size() - 1;
                for(;i > 0;--i)
                    if(cnt[i] > 0)
                        break;
                if(i > 0){
                    cnt[i] = 0;
                    ++cnt[i - 1];
                }else
                    break;
            }else
                ++cnt.back();
        }
        return ret;
    }

    //Chiharu on December 18, 2013 from careercup
    int count(int sum, const std::vector<int> & coins)
    {
        int size = coins.size();
        std::vector<int> table(sum+1);
        table[0] = 1;
        for (int i=0; i<size; i++) {
            for (int j=coins[i]; j<=sum; j++) {
                table[j] += table[j-coins[i]];
            }
        }
        return table[sum];
    }
}

namespace m2{
    void help(const vector<int> & a, vector<int> & ret, size_t to, int n)
    {
        if(n <= 0){
            if(!n){
                for(size_t i = 0;i < ret.size();++i)
                    cout<<ret[i]<<' ';
                cout<<endl;
            }
            return;
        }
        size_t old = ret.size();
        for(size_t i = 0;i < to;++i){
            assert(a[i] > 0);
            ret.resize(old);
            ret.push_back(a[i]);
            help(a, ret, i + 1, n - a[i]);
        }
    }

    void solve(const vector<int> & a, int n)
    {
        if(!n)
            return;
        assert(n > 0);
        vector<int> ret;
        help(a, ret, a.size(), n);
    }
}

int main()
{
    {
        const int d[] = {1, 2, 3};
        std::vector<int> don(d, d + sizeof d / sizeof d[0]);
        std::cout<<m1::findWays1(5, don)<<"\n";
        std::cout<<m1::count(5, don)<<"\n";

        m2::solve(don, 5);
    }
}
