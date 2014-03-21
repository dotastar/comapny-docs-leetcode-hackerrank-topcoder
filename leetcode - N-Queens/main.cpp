#include <vector>
#include <string>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > r;
        if(n < 1)
            return r;
        vector<int> v;
        help(n, v, r);
    }
    void help(int n, vector<int> & v, vector<vector<string> > & r){
        assert(int(v.size()) <= n);
        if(v.size() == n){
            vector<string> vs;
            for(int i = 0;i < n;++i){
                string s(v[i], '.');
                s.push_back('Q');
                s.resize(n, '.');
                vs.push_back(s);
            }
            r.push_back(vs);
            return;
        }
        int old = v.size();
        for(int i = 0;i < n;++i){
            v.resize(old);
            bool valid = true;
            for(int j = 0;j < old;++j){
                if(v[j] == i){
                    valid = false;
                    break;
                }
                if(v[j] + old == i + j){
                    valid = false;
                    break;
                }
                if(v[j] + j == old + i){
                    valid = false;
                    break;
                }
            }
            if(valid){
                v.push_back(i);
                help(n, v, r);
            }
        }
    }

    int totalNQueens1(int n) {
        if(n < 1)
            return 0;
        int r = 0;
        vector<int> v;
        help(n, v, r);
    }
    void help(int n, vector<int> & v, int & r){
        assert(int(v.size()) <= n);
        if(v.size() == n){
            ++r;
            return;
        }
        int old = v.size();
        for(int i = 0;i < n;++i){
            v.resize(old);
            bool valid = true;
            for(int j = 0;j < old;++j){
                if(v[j] == i){
                    valid = false;
                    break;
                }
                if(v[j] + old == i + j){
                    valid = false;
                    break;
                }
                if(v[j] + j == old + i){
                    valid = false;
                    break;
                }
            }
            if(valid){
                v.push_back(i);
                help(n, v, r);
            }
        }
    }
    int totalNQueens2(int n) {
        if(n < 1)
            return 0;
        assert(n < 32);
        int r = 0;
        unsigned int full = (1 << n) - 1;
        help(0, 0, 0, full, r);
        return r;
    }
    void help(unsigned int row, unsigned int ld, unsigned int rd, unsigned int full, int & r){
        if(row == full){
            ++r;
            return;
        }
        unsigned int pos = full & (~(row | ld | rd));
        while(pos){
            unsigned int m = pos & (pos - 1);
            unsigned int p = pos ^ m;           //or p = pos & (-pos);
            help(row | p, (ld | p) >> 1, (rd | p) << 1, full, r);
            pos = m;
        }
    }
};

int main()
{
    for(int i = 1;;++i)
        cout<<Solution().totalNQueens2(i)<<", ";
    cout<<endl;
}

//1, 0, 0, 2, 10, 4, 40, 92, 352