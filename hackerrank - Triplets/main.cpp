#include "../inc.h"

class Solution1
{
    struct MyHash{
        size_t operator ()(const tuple<unsigned int, unsigned int, unsigned int> & t) const{
            return (get<0>(t) ^ get<1>(t) ^ get<2>(t));
        }
    };
public:
    //O(N^3)
    int solve(const vector<unsigned int> & A){
        unordered_set<tuple<unsigned int, unsigned int, unsigned int>, MyHash> save;
        for (size_t i = 0; i < A.size(); ++i){
            for (size_t j = i + 1; j < A.size(); ++j){
                if (A[i] >= A[j])
                    continue;
                for (size_t k = j + 1; k < A.size(); ++k){
                    if (A[j] >= A[k])
                        continue;
                    save.insert(make_tuple(A[i], A[j], A[k]));
                }
            }
        }
        return save.size();
    }
};

struct Solution2
{
    typedef unordered_map<long long, int> __BIT;
    typedef unordered_map<unsigned int, vector<int>> __Pairs;
    long long solve(const vector<unsigned int> & A){
        calcX(A);
        calcY(A);
        return getRet();
    }
private:
    void calcX(const vector<unsigned int> & A){
        __BIT bit;
        unordered_set<unsigned int> rep;
        for (size_t i = 0; i < A.size(); ++i){
            if (0 == rep.count(A[i])){
                addVal(bit, A[i]);
                rep.insert(A[i]);
            }
            pairs[A[i]].push_back(getSmaller(bit, A[i]));
        }
    }
    void calcY(const vector<unsigned int> & A){
        __BIT bit;
        unordered_set<unsigned int> rep;
        for (size_t i = A.size() - 1; i < A.size(); --i){
            unsigned int v = 0xFFFFFFFFu - A[i];
            if (0 == rep.count(A[i])){
                addVal(bit, v);
                rep.insert(A[i]);
            }
            pairs[A[i]].push_back(getSmaller(bit, v));
        }
    }
    long long getRet(){
        long long ret = 0;
        for (__Pairs::const_iterator it = pairs.begin(); it != pairs.end(); ++it){
            const vector<int> & v = it->second;
            if (2 == v.size()){
                ret += (long long)(v[0]) * v[1];
            } else{
                assert(4 == v.size());  //xi, xj, yj, yi
                ret += (long long)(v[0]) * v[3] + (long long)(v[1]) * v[2] - (long long)(v[0]) * v[2];
            }
        }
        return ret;
    }
    //BIT operations
    void addVal(__BIT & bit, unsigned int v){
        long long i(v);
        for (++i; i <= 0x100000000ll; i += i & (-i))
            ++bit[i];
    }
    int getSmaller(__BIT & bit, unsigned int v){
        int ret = 0;
        for (long long i(v); i; i -= i & (-i)){
            __BIT::const_iterator wh = bit.find(i);
            if (wh != bit.end())
                ret += wh->second;
        }
        return ret;
    }
    __Pairs pairs;
};

typedef Solution2 Solution;

void test()
{
    cout << Solution().solve({ 1, 1, 2, 2, 3, 4 }) << endl; //4
    cout << Solution().solve({ 1, 2, 3, 1, 2, 3 }) << endl; //1
    cout << Solution().solve({ 4, 10, 3, 14, 10, 13 }) << endl; //3
}

int main()
{
    test(); return 0;
    int n;
    cin >> n;
    vector<unsigned int> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    cout << Solution().solve(A) << endl;
    return 0;
}