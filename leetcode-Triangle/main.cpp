#include "../inc.h"

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.empty())
            return 0;
        vector<int> v(triangle.back()); //triangle.back().size() == triangle.size()
        for(int i = triangle.size() - 2;i >= 0;--i){
            vector<int> t(v.size() - 1);
            for(size_t j = 0;j < t.size();++j)
                t[j] = triangle[i][j] + min(v[j], v[j + 1]);
            v.swap(t);
        }
        assert(!v.empty());
        return v[0];
    }
};

int main()
{
}
