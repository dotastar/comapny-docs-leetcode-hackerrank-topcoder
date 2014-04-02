#include "../inc.h"

//DP, O(N^2)
int solve1(const vector<int> & seq)
{
    if (seq.size() < 2)
        return seq.size();
    vector<int> ret(seq.size(), 1);
    int r = 1;
    for (size_t i = 1; i < seq.size(); ++i){
        for (size_t j = 0; j < i; ++j){
            if (seq[j] <= seq[i])
                ret[i] = max(ret[i], ret[j] + 1);
        }
        r = max(r, ret[i]);
    }
    return r;
}

//O(NlogN)
int solve2(const vector<int> & seq)
{
    if (seq.size() < 2)
        return seq.size();
    vector<int> lis_tail;   //index对应LIS长度，value对应最小tail值
    for (size_t i = 0; i < seq.size(); ++i){
        //find upper bound for seq[i] in lis_ret
        size_t f = 0, len = lis_tail.size();
        while (len > 0){
            size_t mid = len / 2;
            if (lis_tail[f + mid] <= seq[i]){
                f += mid + 1;
                len -= mid + 1;
            } else
                len = mid;
        }
        if (f < lis_tail.size())
            lis_tail[f] = seq[i];
        else
            lis_tail.push_back(seq[i]);
    }
    return lis_tail.size();
}

int main()
{
    {
        int arr[] = { 5,3,4,8,6,7 };
        vector<int> seq(arr, arr + sizeof arr / sizeof arr[0]);
        cout << solve1(seq)
            << " " << solve2(seq)
            << endl;
    }{
        int arr[] = { 5, 3, 4, 8, 6, 7, 1 };
        vector<int> seq(arr, arr + sizeof arr / sizeof arr[0]);
        cout << solve1(seq)
            << " " << solve2(seq)
            << endl;
    }{
        int arr[] = { 1, 6, 7, 8, 2, 3, 4, 5 };
        vector<int> seq(arr, arr + sizeof arr / sizeof arr[0]);
        cout << solve1(seq)
            << " " << solve2(seq)
            << endl;
    }

}