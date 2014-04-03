#include "../inc.h"

long long encode(int a, int b, int c, int d)
{
    if (a > c)
        swap(a, c);
    if (b > d)
        swap(b, d);
    long long r = (a & 0xFF);
    r = (r << 8) + (b & 0xFF);
    r = (r << 8) + (c & 0xFF);
    r = (r << 8) + (d & 0xFF);
    return r;
}

long long solve(int width, int height, const vector<string> & bad)
{
    if (width < 1 || height < 1)
        return 0;
    set<long long> block;   //a<<24 + b<<16 + c<<8 + d
    for (size_t i = 0; i < bad.size(); ++i){
        istringstream iss(bad[i]);
        int a, b, c, d;
        iss >> a >> b >> c >> d;
        block.insert(encode(a, b, c, d));
    }
    vector<long long> ret(width + 1);
    ret[0] = 1;
    for (int j = 0; j <= height; ++j){
        for (int i = 0; i <= width; ++i){
            if (j > 0 && block.count(encode(i, j - 1, i, j)) > 0)
                ret[i] = 0;
            if (i > 0 && block.count(encode(i - 1, j, i, j)) == 0)
                ret[i] += ret[i - 1];
        }
    }
    return ret.back();
}

int main()
{
    cout << solve(6, 6, { "0 0 0 1", "6 6 5 6" }) << endl;
    cout << solve(1, 1, {}) << endl;
    cout << solve(35, 31, {}) << endl;
    cout << solve(2, 2, { "0 0 1 0", "1 2 2 2", "1 1 2 1" }) << endl;
}