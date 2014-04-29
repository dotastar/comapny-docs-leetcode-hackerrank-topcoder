#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int patition(vector<int> & A, size_t from, size_t to, size_t idx){
    assert(from <= idx && idx < to);
    if (to - from < 2)
        return A[idx];
    size_t p = to - 1, t = from;
    for (size_t i = from; i < p; ++i)
    if (A[i] < A[p])
        swap(A[t++], A[i]);
    swap(A[t], A[p]);
    if (idx == t)
        return A[t];
    if (idx < t)
        return patition(A, from, t, idx);
    return patition(A, t + 1, to, idx);
}

int median(vector<int> & A){
    return patition(A, 0, A.size(), A.size() / 2);
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    cout << median(A) << endl;
    return 0;
}