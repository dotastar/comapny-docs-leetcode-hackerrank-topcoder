#include <iostream>

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <= 1 || n <= 1)
            return 1;
        --m;
        --n;
        //C(m, n + m)
        double r = 1;
        for(int i = 1;i <= n;++i){
            r *= (m + i);
            r /= i;
        }
        return int(r);
    }

};

int main()
{
    std::cout<<Solution().uniquePaths(1, 1)<<"\n";
    std::cout<<Solution().uniquePaths(2, 2)<<"\n";
    std::cout<<Solution().uniquePaths(3, 3)<<"\n";
    std::cout<<Solution().uniquePaths(3, 7)<<"\n";
}
