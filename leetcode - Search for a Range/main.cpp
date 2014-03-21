#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> r(2, -1);
        int f = 0, c = n;
        while(c > 0){
            int m = c / 2;
            if(A[f + m] < target){
                f += m + 1;
                c -= m + 1;
            }else
                c = m;
        }
        if(A[f] != target)
            return r;
        r[0] = f;
        c = n - f;
        while(c > 0){
            int m = c / 2;
            if(!(target < A[f + m])){
                f += m + 1;
                c -= m + 1;
            }else
                c = m;
        }
        r[1] = f - 1;
        return r;
    }
    //or search target and (target + 1)
};

int main(){}