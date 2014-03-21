#include "..\inc.h"

class Solution {
public:
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
        int a[] = {2,1,5,6,2,3};
        vector<int> h(a, a + sizeof a / sizeof a[0]);
        cout<<Solution().largestRectangleArea(h)<<endl;
    }
    {
        int a[] = {2, 1, 3, 4, 2, 3};
        vector<int> h(a, a + sizeof a / sizeof a[0]);
        cout<<Solution().largestRectangleArea(h)<<endl;
    }
}