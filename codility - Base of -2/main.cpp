#include "../inc.h"

// you can also use includes, for example:
// #include <algorithm>
vector<int> solution(const vector<int> &A) {
    // write your code in C++98
    vector<int> b(1);
    //VAL*(-2)
    b.insert(b.end(), A.begin(), A.end());
    //VAL/2
    /*
    Formulars:
    1. ...01... / 2 = ...11...
    2. ...011... / 2 = ...100...
    so:
    3. ...0111... / 2 = ...0110... / 2 + ...0001... / 2 = ...1000... + ...0011... = ...1011...
    4. ...01111... / 2 = ...011... / 2 + ...00011... / 2 = ...10000... + ...00100... = ...10100...
    and so on.
    */
    for (size_t i = 1; i < b.size(); ++i){
        if(!b[i])
            continue;
        b[i - 1] = 1;
        if(i + 1 < b.size() && b[i + 1]) {
            b[i] = b[i + 1] = 0;
        }
    }
    //rm tailing 0s
    while(!b.empty() && !b.back())
        b.pop_back();
    return b;
}

int main()
{
    {
        vector<int> A{ 1, 0, 0, 1, 1 };
        print(solution(A));
    }{
        vector<int> A{1, 0, 0, 1, 1, 1};
        print(solution(A));
    }{
        vector<int> A;
        genArray(A, 1000, 0, 1);
        print(solution(A));
    }

}
