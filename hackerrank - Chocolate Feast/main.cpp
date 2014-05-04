#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t, n, c, m;
    cin >> t;
    while (t--){
        cin >> n >> c >> m;
        int answer = 0;
        // Computer answer
        n /= c;
        answer = n;
        while (n >= m){
            int add = n / m;
            answer += add;
            n = n % m + add;
        }

        cout << answer << endl;
    }
    return 0;
}