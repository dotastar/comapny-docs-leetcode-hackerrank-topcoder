#include "../inc.h"

// you can also use includes, for example:
// #include <algorithm>
int solution(vector<int> &A) {
    // write your code in C++98
    if (A.size() < 3)
        return 0;
    size_t h = 0, t = 1;
    double sum = A[0] + A[1];
    double ave = sum / 2;
    int r = h;
    for (;;){
        if (t - h > 1){
            if (A[h] > ave || t + 1 >= A.size() || A[t + 1] > ave){
                sum -= A[h++];
            } else
                sum += A[++t];
        } else{
            if (++t >= A.size())
                break;
            sum += A[t];
        }
        double a = sum / (t - h + 1);
        if (a < ave){
            ave = a;
            r = h;
        }
    }
    return r;
}

int main()
{
    {
        vector<int> A{ 4, 2, 2, 5, 1, 5, 8 };
        //cout << solution(A) << endl;
    }{
        vector<int> A{ 8, 5, 1, 5, 2, 2, 4 };
        cout << solution(A) << endl;
    }

}