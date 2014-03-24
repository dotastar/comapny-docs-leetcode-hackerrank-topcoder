#include <vector>

using namespace std;

class Solution {
public:
    //O(N*N)
    int maxArea1(vector<int> &height) {
        int r = 0;
        for(size_t i = 0;i < height.size();++i){
            for(size_t j = i + 1;j < height.size();++j){
                int c = (j - i) * min(height[i], height[j]);
                if(c > r)
                    r = c;
            }
        }
        return r;
    }
    //O(N)
    int maxArea2(vector<int> &height) {
        int r = 0;
        int i = 0, j = height.size() - 1;
        int p = 0;
        for(bool n = true;i < j;){
            if(n){
                p = min(height[i], height[j]);
                int c = (j - i) * p;
                if(c > r)
                    r = c;
            }
            if(height[i] < height[j]){
                n = (p < height[++i]);
            }else if(height[i] > height[j]){
                n = (height[--j] > p);
            }else{
                ++i,--j;
                n = (p < height[i] && p < height[j]);
            }
        }
        return r;
    }
};

int main(){}