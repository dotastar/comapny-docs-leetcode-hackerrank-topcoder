#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int j = matrix[0].size() - 1;
        int f = 0, c = matrix.size();
        while(c > 0){
            int m = c / 2;
            if(matrix[f + m][j] < target){
                f += m + 1;
                c -= m + 1;
            }else
                c = m;
        }
        if(f >= int(matrix.size()))
            return false;
        j = 0;
        c = matrix[f].size();
        while(c > 0){
            int m = c / 2;
            if(matrix[f][j + m] < target){
                j += m + 1;
                c -= m + 1;
            }else
                c = m;
        }
        return (target == matrix[f][j]);
    }
};

int main(){}