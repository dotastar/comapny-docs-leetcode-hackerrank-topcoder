#include "..\inc.h"

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int r = 0;
        for(size_t i = 0;i < matrix.size();++i){
            vector<int> height;
            for(size_t j = 0;j < matrix[i].size();++j){
                int h = 0;
                for(;i + h < matrix.size() && '1' == matrix[i + h][j];++h);
                height.push_back(h);
            }
            r = max(r, largestRectangleArea(height));
        }
        return r;
    }
    //Largest Rectangle in Histogram
    int largestRectangleArea(vector<int> &height) {
        size_t r = 0, i = 0;
        for(vector<int> s;i <= height.size();)
            if(s.empty() || (i < height.size() && height[s.back()] < height[i])){
                s.push_back(i++);
            }else{
                int h = height[s.back()];
                s.pop_back();
                r = max(r, h * (s.empty() ? i : i - s.back() - 1));
            }
        return r;
    }
};

int main()
{
    {
        vector<vector<char> > m(1, vector<char>(1, '1'));
        cout<<Solution().maximalRectangle(m)<<endl;
    }
}