#include <vector>
#include <cassert>
#include <iostream>

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


int main()
{
    {
        const int d[] = {1, 2, 3};
        std::vector<int> don(d, d + sizeof d / sizeof d[0]);
        std::cout<<findWays1(5, don)<<"\n";
        std::cout<<count(5, don)<<"\n";
    }
}
