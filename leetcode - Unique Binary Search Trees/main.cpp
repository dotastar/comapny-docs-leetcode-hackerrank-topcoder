/*

class Solution {
public:
    int numTrees(int n) {
        vector<int> v(n + 1, 0);
        v[0] = v[1] = 1;
        for(int i = 2;i <= n;++i)
            for(int j = 0;j < i;++j)
                v[i] += v[i - 1 - j] * v[j];
        return v[n];
    }
    int numTrees2(int n) {
        double np = 1;
        for(int i = 2;i <= n;++i)
            np *= i;
        double n2p = np;
        for(int i = n + 1;i <= 2 * n;++i)
            n2p *= i;
        return n2p / np / np / (n + 1);
    }
};
*/

int main(){}
