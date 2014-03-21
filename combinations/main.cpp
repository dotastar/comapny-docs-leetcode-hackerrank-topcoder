#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

namespace m1{
    int sum(const std::vector<int> & cnt)
    {
        int r = 0;
        for(size_t i = 0;i < cnt.size();++i)
            r += (i + 1) * cnt[i];
        return r;
    }

    void print(const std::vector<int> & cnt)
    {
        std::cout<<"{";
        int p = 0;
        for(size_t i = 0;i < cnt.size();++i)
            for(int c = 0;c < cnt[i];++c){
                if(p++)
                    std::cout<<",";
                std::cout<<(i + 1);
            }
        std::cout<<"}";
    }

    void printCombins(int n)
    {
        std::cout<<"{";
        if(n > 1){
            std::vector<int> cnt(n - 1);
            for(int c = 0;;){
                const int s = sum(cnt);
                if(s >= n){
                    if(s == n){
                        if(c++)
                            std::cout<<",";
                        print(cnt);
                    }
                    int i = cnt.size() - 1;
                    while(i > 0 && !cnt[i])
                        --i;
                    if(!i)
                        break;
                    cnt[i] = 0;
                    ++cnt[i - 1];
                }else
                    ++cnt.back();
            }
        }
        std::cout<<"}\n";
    }
}

namespace m2{
    void help(int n, vector<int> & a, int m)
    {
        if(!n){
            for(size_t i = 0;i < a.size();++i)
                cout<<a[i]<<' ';
            cout<<endl;
            return;
        }else if(n > 0){
            size_t old = a.size();
            for(int i = 1;i < m;++i){
                a.resize(old);
                a.push_back(i);
                help(n - i, a, i + 1);
            }
        }
    }

    void solve(int n)
    {
        vector<int> a;
        help(n, a, n);
        cout<<endl;
    }
}

int main()
{
    m1::printCombins(4);
    m1::printCombins(5);
    cout<<"---\n";
    m2::solve(4);
    m2::solve(5);
    m2::solve(6);
}
