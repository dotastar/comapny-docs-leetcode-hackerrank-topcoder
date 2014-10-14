#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int c = 1, r = c;
        int t = 0, i = 1;
        for(;i < int(ratings.size());++i){
            if(ratings[i - 1] < ratings[i]){        //当前rate更高
                if(c > 1 && t < i - 1){     //整体降低[t, i-1]的人的数量
                    r -= (c - 1) * (i - t - 1);
                    c = 1;
                }
                r += ++c;
                t = i;
            }else if(ratings[i - 1] == ratings[i]){ //rate一样
                if(c > 1 && t < i - 1)       //整体降低[t, i-1]的人的数量
                    r -= (c - 1) * (i - t - 1);
                t = i;
                c = 1;
                ++r;
            }else{      //当前rate更低
                if(c > 1){
                    r += --c;   //递减当前的数量，后面有可能的时候，再整体降低
                }else
                    r += 1 + i - t; //如果前一个已经是1，则整体升高[t, i]的人的数量
            }
        }
        if(c > 1 && t < i - 1)     //整体降低[t, end]的人的数量
            r -= (c - 1) * (i - t - 1);
        return r;
    }
};

class Solution {
public:
    int candy(vector<int> &ratings) {
        if (ratings.empty())
            return 0;
        size_t h = 0;
        int c = 1, r = c;
        for (size_t i = 1; i <= ratings.size(); ++i){
            if (ratings.size() <= i){
                if (h + 1 < i && 1 < c)
                    r -= (i - h - 1) * (c - 1);
            } else if (ratings[i - 1] <= ratings[i]){
                if (h + 1 < i && 1 < c){
                    r -= (i - h - 1) * (c - 1);
                    c = 1;
                }
                if (ratings[i - 1] < ratings[i])
                    ++c;
                else
                    c = 1;
                r += c;
                h = i;
            } else{
                r += --c;
                if (0 == c){
                    c = 1;
                    r += i - h + 1;
                }
            }
        }
        return r;
    }
};

int main()
{
}