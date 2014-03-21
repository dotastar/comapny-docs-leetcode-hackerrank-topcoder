#include "..\inc.h"

class Solution {
public:
    //O(N) time
    double findMedianSortedArrays1(int A[], int m, int B[], int n) {
        assert(m >= 0 && n >= 0);
        int len = m + n;
        assert(len > 0);
        int clen = (len - 1) / 2;
        double v1, v2;
        for(int i = 0, j = 0, k = 0;(i < m || j < n) && k <= clen + 1;++k){
            int v;
            if(j >= n || (i < m && A[i] < B[j]))
                v = A[i++];
            else
                v = B[j++];
            if(k == clen)
                v1 = v;
            else if(k == clen + 1)
                v2 = v;
        }
        return (len & 1 ? v1 : (v1 + v2) / 2);
    }
    //O(logN)
    double findMedianSortedArrays2(int A[], int m, int B[], int n) {
        int *AA, *BB, mm, nn;
        if(m < n){
            AA = A;
            BB = B;
            mm = m;
            nn = n;
        }else{
            AA = B;
            BB = A;
            mm = n;
            nn = m;
        }
        return help(AA, mm, BB, nn);
    }
    double help(int A[], int m, int B[], int n){
        assert(m <= n);
        if(!m){
            return me(B, n);
        }else if(1 == m){
            if(1 == n)
                return me(A[0], B[0]);
            else if(n & 1)
                return me(A[0], B[n / 2 - 1], B[n / 2], B[n / 2 + 1]);
            return me(A[0], B[n / 2 - 1], B[n / 2]);
        }else if(2 == m){
            if(2 == n){
                return me(max(A[0], B[0]), min(A[1], B[1]));
            }else if(n & 1)
                return me(B[n / 2], max(A[0], B[n / 2 - 1]), min(A[1], B[n / 2 + 1]));
            return me(B[n / 2 - 1], B[n / 2], max(A[1], B[n / 2 - 2]), min(A[0], B[n / 2 + 1]));
        }
        double a = me(A, m);
        double b = me(B, n);
        if(a < b)
            return help(A + (m - 1) / 2, m / 2 + 1, B, n - (m - 1) / 2);
        return help(A, m / 2 + 1, B + (m - 1) / 2, n - (m - 1) / 2);
    }
    double me(int * A, int m){
        assert(m > 0);
        return (m & 1 ? double(A[m / 2]) : me(A[m / 2 - 1], A[m / 2]));
    }
    double me(double v1, double v2){
        return (v1 + v2) / 2;
    }
    double me(double v1, double v2, double v3){
        if(v1 > v2)
            swap(v1, v2);
        if(v2 > v3)
            swap(v2, v3);
        return max(v1, v2);
    }
    double me(double v1, double v2, double v3, double v4){
        double v[4] = {v1, v2, v3, v4};
        sort(v, v + 4);
        return (v[1] + v[2]) / 2;
    }
};

int main()
{
    {
        int A[] = {1,3,7,8};
        int B[] = {2,4,5,6};
        cout<<Solution().findMedianSortedArrays2(A, sizeof A / sizeof A[0], B, sizeof B / sizeof B[0])<<endl;
        //4.5
    }{
        int A[] = {1,2,6,7};
        int B[] = {3,4,5,8};
        cout<<Solution().findMedianSortedArrays2(A, sizeof A / sizeof A[0], B, sizeof B / sizeof B[0])<<endl;
        //4.5
    }{
        int A[] = {900};
        int B[] = {5, 8, 10, 20};
        cout<<Solution().findMedianSortedArrays2(A, sizeof A / sizeof A[0], B, sizeof B / sizeof B[0])<<endl;
        //10
    }{
        int A[] = {1,2};
        int B[] = {1,2};
        cout<<Solution().findMedianSortedArrays2(A, sizeof A / sizeof A[0], B, sizeof B / sizeof B[0])<<endl;
        //1.5
    }{
        int A[] = {1,2,3};
        int B[] = {4,5,6};
        cout<<Solution().findMedianSortedArrays2(A, sizeof A / sizeof A[0], B, sizeof B / sizeof B[0])<<endl;
        //3.5
    }{
        int A[] = {1,2,3,4,5};
        int B[] = {1,5,6,7};
        cout<<Solution().findMedianSortedArrays2(A, sizeof A / sizeof A[0], B, sizeof B / sizeof B[0])<<endl;
        //4
        cout<<Solution().findMedianSortedArrays2(A, 0, B, 1)<<endl;
        //1
    }
}