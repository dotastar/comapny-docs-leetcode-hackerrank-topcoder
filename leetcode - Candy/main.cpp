#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int c = 1, r = c;
        int t = 0, i = 1;
        for(;i < int(ratings.size());++i){
            if(ratings[i - 1] < ratings[i]){
                if(c > 1 && t < i - 1){
                    r -= (c - 1) * (i - t - 1);
                    c = 1;
                }
                r += ++c;
                t = i;
            }else if(ratings[i - 1] == ratings[i]){
                if(c > 1 && t < i - 1)
                    r -= (c - 1) * (i - t - 1);
                t = i;
                c = 1;
                ++r;
            }else{
                if(c > 1){
                    r += --c;
                }else
                    r += 1 + i - t;
            }
        }
        if(c > 1 && t < i - 1)
            r -= (c - 1) * (i - t - 1);
        return r;
    }
};

int main()
{
}