#include "../inc.h"

int solve(const vector<int> & array)
{
    if(array.size() < 2)
        return array.size();
    vector<bool> v(array.size());
    int r = 0;
    for(size_t i = 0;i < array.size();++i){
        if(v[i])
            continue;
        vector<int> s(array.size());
        int c = 1;
        for(;!s[i];++c){
            s[i] = c;
            v[i] = true;
            i = array[i];
            assert(0 <= i && i < array.size());
        }
        c -= s[i];
        if(c > r)
            r = c;
    }
    return r;
}

int main()
{
    {
        int a[] = {3, 2, 1, 4, 0};
        vector<int> arr(a, a + sizeof a / sizeof a[0]);
        cout<<solve(arr)<<endl;
    }
    {
        int a[] = {3, 2, 1, 4, 0, 5, 5, 8, 3};
        vector<int> arr(a, a + sizeof a / sizeof a[0]);
        cout<<solve(arr)<<endl;
    }
}
