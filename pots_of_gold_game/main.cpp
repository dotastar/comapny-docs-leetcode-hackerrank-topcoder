#include "../inc.h"

/*
    A(n) = A(1, n) means A's result to pick from n pots {p1, p2, ... , pn};
    B(n) = B(1, n) means B's result to pick from n pots {p1, p2, ... , pn};

    we have:
    A(1) = p1;
    B(1) = 0;

    A(2) = max(p1, p2);
    B(2) = min(p1, p2);

    A(n) = max(p1+B(2,n), B(1,n-1)+pn)
    B(n) = SUM - A(n)
*/

class Solution
{
    typedef map<pair<size_t, size_t>, int> __Map;
public:
    Solution(const int * arr, size_t len){
        assert(arr);
        pots_.assign(arr, arr + len);
    }
    int A() const{return A(0, pots_.size());}
    int B() const{return B(0, pots_.size());}
private:
    int A(size_t from, size_t len) const{
        assert(from < pots_.size() && from + len <= pots_.size());
        if(!len)
            return 0;
        if(1 == len)
            return pots_[from];
        if(2 == len)
            return max(pots_[from], pots_[from + 1]);
        int & r = storeA_[make_pair(from, len)];
        if(r > 0)
            return r;
        int r1 = pots_[from] + B(from + 1, len - 1);
        int r2 = B(from, len - 1) + pots_[from + len - 1];
        return (r = max(r1, r2));
    }
    int B(size_t from, size_t len) const{
        assert(from < pots_.size() && from + len <= pots_.size());
        if(len < 2)
            return 0;
        if(2 == len)
            return min(pots_[from], pots_[from + 1]);
        bool pick1st = false;
        return SUM(from, len) - A(from, len);
    }
    int SUM(size_t from, size_t len) const{
        assert(from < pots_.size() && from + len <= pots_.size());
        int r = 0;
        for(size_t i = 0;i < len;++i)
            r += pots_[from + i];
        return r;
    }
    vector<int> pots_;
    mutable __Map storeA_;
};

int main()
{
    {
        const int arr[] = {1};
        Solution s(arr, sizeof arr / sizeof arr[0]);
        cout<<s.A()<<", "<<s.B()<<endl;
    }{
        const int arr[] = {1, 2};
        Solution s(arr, sizeof arr / sizeof arr[0]);
        cout<<s.A()<<", "<<s.B()<<endl;
    }{
        const int arr[] = {1, 3, 1};
        Solution s(arr, sizeof arr / sizeof arr[0]);
        cout<<s.A()<<", "<<s.B()<<endl;
    }{
        const int arr[] = {2, 4, 7, 1, 2, 1};
        Solution s(arr, sizeof arr / sizeof arr[0]);
        cout<<s.A()<<", "<<s.B()<<endl;
    }{
        const int arr[] = {
            2, 4, 7, 1, 2, 1, 3,4,5,6,
            2,3,4,1, 1, 2, 1, 3,4,5,6,
            2,3,4,1, 1, 2, 1, 3,4,5,6,
            2,3,4,1, 1, 2, 1, 3,4,5,6,
            2,3,4,1, 1, 2, 1, 3,4,5,6,
            2,3,4,1, 1, 2, 1, 3,4,5,6,
        };
        Solution s(arr, sizeof arr / sizeof arr[0]);
        cout<<s.A()<<", "<<s.B()<<endl;
    }
}
