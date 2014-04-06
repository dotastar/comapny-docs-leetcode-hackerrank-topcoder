#include "../inc.h"

int solve1(vector<int> & A)
{
    if (A.size() < 2)
        return 0;
    vector<size_t> idx(A.size());
    size_t ret = 0;
    for (size_t i = 1; i < A.size(); ++i){
        if (A[i] >= A[i - 1]){
            for (size_t j = 0; j <= idx[i - 1]; ++j){
                if (A[j] <= A[i]){
                    idx[i] = j;
                    break;
                }
            }
        } else{
            for (size_t j = idx[i - 1]; j <= i; ++j){
                if (A[j] <= A[i]){
                    idx[i] = j;
                    break;
                }
            }
        }
        ret = max(ret, i - idx[i]);
    }
    return ret;
}

//O(N^2)
int solve2(vector<int> & A)
{
    if (A.size() < 2)
        return 0;
    int h = A.size() - 1, t = h, r = 0;
    for (;h > 0;--t, --h){
        for (int i = 0; i < h; ++i){
            if (A[i] <= A[t]){
                h = i;
                break;
            }
        }
        r = max(r, t - h);
    }
    return r;
}

int solve3(vector<int> & A)
{
    if (A.size() < 2)
        return 0;
    size_t pre = 0, ret = 0;
    for (size_t i = 1; i < A.size(); ++i){
        if (A[i] > A[i - 1]){
            for (size_t j = 0; j <= pre; ++j){
                if (A[j] <= A[i]){
                    pre = j;
                    break;
                }
            }
        } else if(A[i] < A[i - 1]){
            for (size_t j = pre; j <= i; ++j){
                if (A[j] <= A[i]){
                    pre = j;
                    break;
                }
            }
        }
        ret = max(ret, i - pre);
    }
    return ret;
}

//O(N)
int solveIris(vector<int> & A)
{
    if (A.size() < 2)
        return 0;
    deque<int> lefti(1, 0);
    for (size_t i = 1; i < A.size(); ++i){
        if (A[i] < A[lefti.back()])
            lefti.push_back(i);
    }
    vector<int> righti(1, A.size() - 1);
    for (int i = A.size() - 2; i >= 0; --i){
        if (A[i] > A[righti.back()])
            righti.push_back(i);
    }
    int r = 0;
    while (!lefti.empty() && !righti.empty()){
        if (A[righti.back()] < A[lefti.front()])
            lefti.pop_front();
        if (!lefti.empty()){
            if (righti.back() < lefti.front()){
                do{
                    righti.pop_back();
                } while (!righti.empty() && righti.back() < lefti.front());
            } else{
                r = max(r, righti.back() - lefti.front());
                righti.pop_back();
            }
        }
    }
    return r;
}

//O(N), based on iris' solution
int solve4(vector<int> & A)
{
    if (A.size() < 2)
        return 0;
    deque<int> lefti(1, 0);
    for (size_t i = 1; i < A.size(); ++i){
        if (A[i] < A[lefti.back()])
            lefti.push_back(i);
    }
    vector<int> righti(1, A.size() - 1);
    for (int i = A.size() - 2; i >= 0; --i){
        if (A[i] > A[righti.back()])
            righti.push_back(i);
    }
    int r = 0;
    while (!lefti.empty() && !righti.empty()){
        if (lefti.front() > righti.back()){
            righti.pop_back();
        } else if (A[lefti.front()] <= A[righti.back()]){
            r = max(r, righti.back() - lefti.front());
            righti.pop_back();
        } else
            lefti.pop_front();
    }
    return r;
}

void getTest(vector<int> & A, int count, int range)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < count; ++i){
        int r = rand();
        r <<= 16;
        r += rand();
        r = (r % (2 * range + 1)) - range;
        A.push_back(r);
    }
}

int main()
{
#define solve   solve4
    {
        vector<int> seq{ 5, 3, 6, 3, 4, 2 };
        cout << solve(seq) << endl;
        cout << "---\n";
    }{
        vector<int> seq;
        getTest(seq, 20, 5);
        print2(seq);
        cout << solve(seq) << endl;
        cout << "---\n";
    }{
        vector<int> seq;
        for (int i = 0; i < 300000; ++i)
            seq.push_back(i);
        cout << "begin\n";
        cout << solve(seq) << endl;
        cout << "---\n";
    }{
        vector<int> seq;
        for (int i = 0; i < 300000; ++i)
            seq.push_back(200000 - i);
        cout << "begin\n";
        cout << solve(seq) << endl;
        cout << "---\n";
    }{
        vector<int> seq;
        getTest(seq, 300000, 1000000000);
        //print(seq);
        cout << "begin\n";
        cout << solve(seq) << endl;
        cout << "---\n";
    }
}