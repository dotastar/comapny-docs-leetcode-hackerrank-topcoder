#include "../inc.h"

class Solution {
public:
    int sqrt(int x) {
        assert(x >= 0);
        if(x < 2)
            return x;
        int r = x;
        for(;;){
            int t = ((unsigned int)x / r + r) / 2;
            if(t >= r)
                break;
            r = t;
        }
        return r;
    }
};

int main()
{
    cout<<Solution().sqrt(2147483647)<<endl;
    for(int i = 0;i <= 20;++i)
        cout<<i<<": "<<Solution().sqrt(i)<<endl;
}
