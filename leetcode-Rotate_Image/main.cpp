#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        for(size_t n = 0;n < matrix.size() - n;++n){
            size_t len = matrix.size() - 2 * n;
            for(size_t i = 0;i < len - 1;++i){
                size_t x = n, y = n + i;
                int t = matrix[x][y];
                matrix[x][y] = matrix[x + len - 1 - i][y - i];
                x += len - 1 - i;
                y -= i;
                matrix[x][y] = matrix[x + i][y + len - 1 - i];
                x += i;
                y += len - 1 - i;
                matrix[x][y] = matrix[x - len + 1 + i][y + i];
                x += -len + 1 + i;
                y += i;
                matrix[x][y] = t;
            }
        }
    }
};

int main()
{
}
