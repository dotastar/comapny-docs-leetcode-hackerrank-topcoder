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

class Solution2 {
public:
    int largestRectangleArea(vector<int> &height) {
        int r = 0;
        vector<size_t> s;
        for(size_t i = 0;i <= height.size();++i){
            while(!s.empty() && (i >= height.size() || height[i] < height[s.back()])){
                const int h = s.back();
                s.pop_back();
                r = max<int>(r, height[h] * (s.empty() ? i : i - s.back() - 1));
            }
            s.push_back(i);
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