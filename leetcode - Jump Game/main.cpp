#include <vector>

using namespace std;

class Solution {
public:
    //O(N^2) time, O(N) space
    bool canJump1(int A[], int n) {
        if(n < 2)
            return true;
        vector<int> save(n, -1);
        save[0] = 1;
        return help(A, n - 1, save);
    }
    bool help(int A[], int d, vector<int> & save){
        if(save[d] >= 0)
            return (save[d] == 1);
        save[d] = 0;
        for(int i = 1;i <= d;++i){
            if(A[d - i] < i)
                continue;
            if(help(A, d - i, save)){
                save[d] = 1;
                return true;
            }
        }
        return false;
    }
    //O(N) time, O(1) space
    bool canJump2(int A[], int n) {
        int m = 0;
        for(int i = 0;i <= m && i < n;++i){
            int r = i + A[i];
            if(r > m)
                m = r;
        }
        return m >= n - 1;
    }

    int jump(int A[], int n) {
        int r = 0;
        int p = 0;
        int m = 0;
        for(int i = 0;m < n - 1;++r,p = m){
            for(;i <= p;++i){
                int d = i + A[i];
                if(d > m)
                    m = d;
            }
            if(m <= p)
                return -1;  //cannot proceed
        }
        return r;
    }
};

int main(){}