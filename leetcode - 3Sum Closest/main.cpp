#include "..\inc.h"

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int r, d = -1;
        for(int i = 0;i < int(num.size());++i)
            for(int j = i + 1;j < int(num.size());++j)
                for(int k = j + 1;k < int(num.size());++k){
                    int s = num[i] + num[j] + num[k];
                    int dd = (s > target ? s - target : target - s);
                    if(!dd)
                        return target;
                    if(d < 0 || dd < d){
                        d = dd;
                        r = s;
                    }
                }
        return r;
    }
};

int main(){}