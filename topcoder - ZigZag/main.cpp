#include "../inc.h"

//DP, O(N^2)
int solve(const vector<int> & seq)
{
    if (seq.size() < 3)
        return seq.size();
    vector<int> inc(seq.size(), 1), dec(seq.size(), 1);   //increasing seq len & decreasing seq len
    for (size_t i = 1; i < seq.size(); ++i){
        for (size_t j = 0; j < i; ++j){
            if (seq[i] < seq[j]){
                dec[i] = max(dec[i], inc[j] + 1);
            } else if (seq[i] > seq[j]){
                inc[i] = max(inc[i], dec[j] + 1);
            }
        }
    }
    return max(inc.back(), dec.back());
}

int main()
{
    {
        vector<int> seq{ 1, 7, 4, 9, 2, 5 };
        cout << solve(seq) << endl;
    }{
        vector<int> seq{ 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };
        cout << solve(seq) << endl;
    }{
        vector<int> seq{ 10 };
        cout << solve(seq) << endl;
    }{
        vector<int> seq{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        cout << solve(seq) << endl;
    }{
        vector<int> seq{ 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 };
        cout << solve(seq) << endl;
    }{
        vector<int> seq{ 374, 40, 854, 203, 203, 156, 362, 279, 812, 955,
            600, 947, 978, 46, 100, 953, 670, 862, 568, 188,
            67, 669, 810, 704, 52, 861, 49, 640, 370, 908,
            477, 245, 413, 109, 659, 401, 483, 308, 609, 120,
            249, 22, 176, 279, 23, 22, 617, 462, 459, 244 };
        cout << solve(seq) << endl;
    }
}