/*
给一个矩阵，从左上角开始，循环沿着“右，左下，左，上”4个方向前进，不能重复访问元素，打印被访问的元素。
例如：
1, 2, 3, 4, 5, 
6, 7, 8, 9, 10, 
11, 12, 13, 14, 15
访问结果是：
1，2，3，4，5，9，13，12，11，6，7，8
*/


#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int W, H;
set<pair<int, int> > VIS;
vector<int> RET;
const int DX[] = { 1, -1, -1, 0 };
const int DY[] = { 0, 1, 0, -1 };

size_t index(int x, int y)
{
	return (x + y * W);
}

bool move(int & x, int & y, int d)
{
	int xx = x + DX[d];
	int yy = y + DY[d];
	if (xx < 0 || W <= xx || yy < 0 || H <= yy)
		return false;
	if (VIS.count(make_pair(xx, yy)) > 0)
		return false;
	x = xx;
	y = yy;
	VIS.insert(make_pair(x, y));
	return true;
}

int walk(int & x, int & y, int d, const vector < int > & matrix)
{
	int ret = 0;
	for (;move(x, y, d);++ret)
		RET.push_back(matrix[index(x, y)]);
	return ret;
}

vector < int > convertMatrix(int width, int height, vector < int > matrix) {
	if (matrix.empty())
		return RET;
	W = width;
	H = height;
	int x = 0, y = 0;
	VIS.insert(make_pair(x, y));
	RET.push_back(matrix[index(x, y)]);
	for (;;){
		int step = 0;
		for (int i = 0; i <4; ++i)
			step += walk(x, y, i, matrix);
		if (!step)
			break;
	}
	return RET;
}

int test()
{


	vector<int> m{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	vector<int> res = convertMatrix(5, 3, m);
	for (size_t res_i = 0; res_i < res.size(); res_i++) {
		cout << res[res_i] << " ";
	}
	system("pause");
	return 0;
}


int main1() {

	return test();

	vector < int > res;
	int _width;
	cin >> _width;

	int _height;
	cin >> _height;

	vector<int> _matrix;
	int _matrix_item;
	for (int _matrix_i = 0; _matrix_i<_width * _height; _matrix_i++) {
		cin >> _matrix_item;
		_matrix.push_back(_matrix_item);
	}

	res = convertMatrix(_width, _height, _matrix);
	for (int res_i = 0; res_i < res.size(); res_i++) {
		cout << res[res_i] << " ";
	}
	return 0;
}
