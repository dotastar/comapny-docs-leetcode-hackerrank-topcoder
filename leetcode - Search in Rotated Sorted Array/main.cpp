class Solution {
public:
    int searchI(int A[], int n, int target) {
        int f = 0, c = n;
        while(c > 0){
            int m = c / 2;
            if(target == A[f + m])
                return f + m;
            if(A[f] <= A[f + m]){
                if(A[f] <= target && target < A[f + m])
                    c = m;
                else{
                    f += m + 1;
                    c -= m + 1;
                }
            }else{
                if(A[f + m] < target && target <= A[f + c - 1]){
                    f += m + 1;
                    c -= m + 1;
                }else
                    c = m;
            }
        }
        return -1;
    }
    int searchII(int A[], int n, int target) {
        for(int i = 0;i < n;++i)
            if(A[i] == target)
                return true;
        return false;
    }
};

int main(){}

/*
3,1
3
f 0
c 2
m 1
*/