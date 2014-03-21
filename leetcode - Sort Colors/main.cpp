#include <iostream>

class Solution {
public:
    void sortColors(int A[], int n) {
        if(n <= 1)
            return;
        int h = 0, t = n - 1;
        for(;h < n && 0 == A[h];++h);
        for(;t >= h && 2 == A[t];--t);
        for(int i = h;i <= t;){
            if(0 == A[i]){
                if(i == h)
                    ++i,++h;
                else{
                    A[i] = A[h];
                    A[h++] = 0;
                }
            }else if(2 == A[i]){
                if(i == t)
                    --i,--t;
                else{
                    A[i] = A[t];
                    A[t--] = 2;
                    for(;t >= i && 2 == A[t];--t);
                }
            }else
                ++i;
        }
    }
};

int main()
{
    int a[] = {0,2,0};
    Solution().sortColors(a, sizeof a / sizeof a[0]);
    for(size_t i = 0;i < sizeof a / sizeof a[0];++i)
        std::cout<<a[i]<<' ';
    std::cout<<"\n";
}