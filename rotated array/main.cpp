#include <iostream>

template<int N>
int findPivot(const int (&a)[N])
{
    int p = N / 2, s = 0;
    while(s < p){
        if(a[s] <= a[p]){
            s = p;
            p = (s + N) / 2;
        }else
            p = (s + p) / 2;
    }
    return p + 1;
}

template<int N>
int findIn(const int (&a)[N], int k)
{
    int p = findPivot(a);
    int s = 0, i = N / 2;
    while(s < i){
        int ss = (p + s) % N;
        int ii = (p + i) % N;
        if(a[ii] == k)
            return ii;
        else if(a[ii] < k){
            s = i;
            i = (s + N) / 2;
        }else
            i = (s + i) / 2;
    }
    int ss = (p + s) % N;
    if(k == a[ss])
        return ss;
    return -1;
}

int main()
{
    const int a[] = {4, 5, 6, 7, 8, 9, 1, 2, 3};
    std::cout<<findIn(a, 1)<<"\n";
    std::cout<<findIn(a, 9)<<"\n";
    std::cout<<findIn(a, 8)<<"\n";
    std::cout<<findIn(a, 10)<<"\n";
    std::cout<<findIn(a, 0)<<"\n";
}