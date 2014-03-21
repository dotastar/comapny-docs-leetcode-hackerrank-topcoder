#include <iostream>
#include <map>

//O(N log N)
template<int N>
bool hasSum(const int (&a)[N], int k)
{
    std::map<int, int> m;
    for(int i = 0;i < N;++i)
        ++m[a[i]];
    for(int i = 0;i < N;++i){
        std::map<int, int>::const_iterator wh = m.find(k - a[i]);
        if(wh != m.end()){
            if(wh->first != a[i])
                return true;
            else if(wh->second > 1)
                return true;
        }
    }
    return false;
}

//use hash map to get O(N) complexity

int main()
{
    const int a[] = {3,2,4,5,1,6,5};
    std::cout<<hasSum(a, 12)<<"\n";
    std::cout<<hasSum(a, 11)<<"\n";
    std::cout<<hasSum(a, 10)<<"\n";
}