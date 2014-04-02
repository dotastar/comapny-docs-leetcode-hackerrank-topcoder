#include "../inc.h"

int solve(const vector<vector<int> > & apples)
{
    if (apples.empty() || apples[0].empty())
        return 0;
    vector<int> ret(apples[0].size());
    for (size_t i = 0; i < apples.size(); ++i){
        for (size_t j = 0; j < apples[i].size(); ++j){
            if (j > 0)
                ret[j] = max(ret[j], ret[j - 1]);
            ret[j] += apples[i][j];
        }
    }
    return ret.back();
}

int main()
{

}