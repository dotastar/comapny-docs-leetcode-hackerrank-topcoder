#include "../inc.h"

// you can also use includes, for example:
// #include <algorithm>
vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++98
    vector<vector<int> > cnt;
    vector<int> v(4);
    for (size_t i = 0; i < S.size(); ++i){
        switch (S[i]){
            case 'A':++v[0]; break;
            case 'C':++v[1]; break;
            case 'G':++v[2]; break;
            default:++v[3];
        }
        cnt.push_back(v);
    }
    v.clear();
    v.resize(4);
    vector<int> ret;
    for (size_t i = 0; i < P.size(); ++i){
        const vector<int> & v2 = cnt[Q[i]];
        const vector<int> & v1 = (P[i] > 0 ? cnt[P[i] - 1] : v);
        for (int j = 0; j < 4; ++j){
            if (v2[j] > v1[j]){
                ret.push_back(j + 1);
                break;
            }
        }
    }
    return ret;
}

int main(){}