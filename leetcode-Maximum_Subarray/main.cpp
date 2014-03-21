class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n <= 0)
            return 0;
        int c = A[0];
        int r = c;
        for(int i= 1;i < n;++i){
            if(c <= 0){
                c = A[i];
            }else{
                c += A[i];
                if(c < 0)
                    c = 0;
            }
            if(c > r)
                r = c;
        }
        return r;
    }
    int maxSubArray(int A[], int n) {
    }
};
