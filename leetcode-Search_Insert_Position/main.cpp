class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(n <= 0)
            return 0;
        int f = 0, c = n;
        while(c){
            int m = c / 2;
            if(A[f + m] < target){
                f += m + 1;
                c -= m + 1;
            }else
                c = m;
        }
        return f;
    }
};

int main()
{
}
