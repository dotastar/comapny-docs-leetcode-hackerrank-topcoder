#include "../inc.h"

class Solution {
public:
    int findMin(vector<int> &num) {
        return help(num, 0, num.size());
    }
    int help(const vector<int> & num, size_t from, size_t len){
        assert(len);
        if (1 == len)
            return num[from];
        else if (2 == len)
            return min(num[from], num[from + 1]);
        const int mid = len / 2;
        if (num[from] < num[from + mid]){
            if (num[from + mid] < num[from + len - 1])
                return num[from];
            return help(num, from + mid + 1, len - mid - 1);
        }
        return help(num, from + 1, mid);
    }
};

class SolutionII {
public:
    int findMin(vector<int> &num) {
        return help(num, 0, num.size());
    }
    int help(const vector<int> & num, size_t from, size_t len){
        assert(len);
        if (1 == len)
            return num[from];
        else if (2 == len)
            return min(num[from], num[from + 1]);
        const int mid = len / 2;
        if (num[from] < num[from + mid]){
            if (num[from + mid] <= num[from + len - 1])
                return num[from];
            return help(num, from + mid + 1, len - mid - 1);
        } else if (num[from] == num[from + mid]){
            if (num[from + mid] > num[from + len - 1])
                return help(num, from + mid + 1, len - mid - 1);
            return min(help(num, from, mid), help(num, from + mid, len - mid));
        }
        return help(num, from + 1, mid);
    }
};

int main()
{
    //I
    {
        vector<int> A{ 10, 20, 30, 40 };
        cout << Solution().findMin(A) << endl;
    }{
        vector<int> A{ 20, 30, 40, 10 };
        cout << Solution().findMin(A) << endl;
    }{
        vector<int> A{ 30, 40, 10, 20 };
        cout << Solution().findMin(A) << endl;
    }{
        vector<int> A{ 40, 10, 20, 30 };
        cout << Solution().findMin(A) << endl;
    }
    //II
    cout << "---\n";
    {
        vector<int> A{ 10, 10, 10, 10 };
        cout << SolutionII().findMin(A) << endl;
    }{
        vector<int> A{ 20, 20, 20, 20, 20, 20, 30, 40, 10 };
        cout << SolutionII().findMin(A) << endl;
    }{
        vector<int> A{ 20, 20, 20, 30, 40, 10, 20, 20, 20, 20 };
        cout << SolutionII().findMin(A) << endl;
    }{
        vector<int> A{ 40, 40, 40, 40, 40, 10, 20, 30, 40, 40 };
        cout << SolutionII().findMin(A) << endl;
    }
    return 0;
}