#include "../inc.h"

bool valid(int i, int j, int size)
{
    return (0 <= i && i < size && 0 <= j && j < size);
}

int index(int i, int j, int size)
{
    assert(valid(i, j, size));
    return (i + j * size);
}

long long solve(int size, pair<int, int> start, pair<int, int> end, int numMoves)
{
    if (size < 2)
        return 1;
    const int di[] = {-1, -1, -1, 0, 0, 1, 1, 1, -2, -2, 2, 2, -1, -1, 1, 1};
    const int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1, -1, 1, -1, 1, -2, 2, -2, 2};
    vector<long long> matrix(size * size);
    matrix[index(start.first, start.second, size)] = 1;
    vector<long long> tmp(matrix.size());
    for (int k = 0; k < numMoves; ++k){
        for (size_t idx = 0; idx < matrix.size(); ++idx){
            if (matrix[idx]){
                const int i = idx % size;
                const int j = idx / size;
                for (size_t ii = 0; ii < sizeof di / sizeof di[0]; ++ii)
                    if (valid(i + di[ii], j + dj[ii], size))
                        tmp[index(i + di[ii], j + dj[ii], size)] += matrix[idx];
            }
        }
        matrix.swap(tmp);
        fill(tmp.begin(), tmp.end(), 0);
    }
    return matrix[index(end.first, end.second, size)];
}

int main()
{
    cout << solve(3, { 0, 0 }, { 1, 0 }, 1) << endl;
    cout << solve(3, { 0, 0 }, { 1, 2 }, 1) << endl;
    cout << solve(3, { 0, 0 }, { 2, 2 }, 1) << endl;
    cout << solve(3, { 0, 0 }, { 0, 0 }, 2) << endl;
    cout << solve(100, { 0, 0 }, { 0, 99 }, 50) << endl;
}