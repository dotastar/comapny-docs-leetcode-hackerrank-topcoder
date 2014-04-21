#include <vector>
#include <map>

using namespace std;

// you can also use includes, for example:
// #include <algorithm>
int solution(vector<int> &A) {
    // write your code in C++98
    vector<bool> save(A.size());
    map<int, int> dup;  //val -> idx
    for (size_t i = 0; i < A.size(); ++i){
        map<int, int>::iterator wh = dup.find(A[i]);
        if (dup.end() == wh){
            dup[A[i]] = i;
        } else{
            save[i] = save[wh->second] = true;
        }
    }
    for (size_t i = 0; i < save.size(); ++i){
        if (!save[i])
            return A[i];
    }
    return -1;
}

