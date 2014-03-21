#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int first = -1;
        for(size_t i = 0;i < matrix.size() && first < 0;++i){
            for(size_t j = 0;j < matrix[i].size();++j)
                if(!matrix[i][j]){
                    first = i;
                    break;
                }
        }
        if(first < 0)
            return;
        for(size_t i = first + 1;i < matrix.size();++i){
            bool z = false;
            for(size_t j = 0;j < matrix[i].size();++j){
                if(!matrix[i][j]){
                    z = true;
                    matrix[first][j] = 0;
                }
            }
            if(!z)
                continue;
            for(size_t j = 0;j < matrix[i].size();++j)
                matrix[i][j] = 0;
        }
        for(size_t j = 0;j < matrix[first].size();++j){
            if(matrix[first][j])
                continue;
            for(size_t i = 0;i < matrix.size();++i)
                matrix[i][j] = 0;
        }
        for(size_t j = 0;j < matrix[first].size();++j)
            matrix[first][j] = 0;
    }
};

int main(){}

