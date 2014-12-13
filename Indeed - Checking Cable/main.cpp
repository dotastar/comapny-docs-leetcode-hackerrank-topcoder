#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

vector<vector<int> > matrix;

void init(int n)
{
	assert(0 < n);
	matrix.resize(n);
	for (size_t i = 0; i < matrix.size(); ++i)
		matrix[i].resize(i, -1);
}

int mget(int a, int b)
{
	if (a == b)
		return -2;
	if (a < b)
		swap(a, b);
	assert(0 <= b && a < int(matrix.size()));
	return matrix[a][b];
}

void mset(int a, int b, int v)
{
	if (a == b)
		return;
	if (a < b)
		swap(a, b);
	assert(0 <= b && a < int(matrix.size()));
	matrix[a][b] = v;
}

int mmin(int a, int b)
{
	if (a < 0)
		return b;
	if (b < 0)
		return a;
	return min(a, b);
}

int mmin(int a, int b, int c)
{
	return mmin(a, mmin(b, c));
}

int mmax(int a, int b)
{
	if (a < 0)
		return b;
	if (b < 0)
		return a;
	return max(a, b);
}

void make(int a, int b, int d)
{
	mset(a, b, mmax(d, mget(a, b)));
	const int n = matrix.size();
	for (int i = 0; i < n; ++i){
		const int ia = mget(i, a);
		if (-1 == ia)
			continue;
		for (int j = 0; j < n; ++j){
			if (j == i)
				continue;
			const int jb = mget(j, b);
			if (-1 == jb)
				continue;
			int ij = mmin(d, ia, jb);
			mset(i, j, mmax(mget(i, j), ij));
		}
	}
}

void check(int a, int b, int t)
{
	int d = mget(a, b);
	if (-2 == d)
		d = 0;
	if (d < 0 || t > d)
		cout << "NO\n";
	else
		cout << "YES\n";
}

void show()
{
	for (size_t i = 0; i < matrix.size(); ++i){
		for (size_t j = 0; j < matrix[i].size(); ++j)
			cout << matrix[i][j] << ' ';
		cout << endl;
	}
}

void solve()
{
	int n, t;
	cin >> n>>t;
	if (n <= 1)
		return;
	init(n);
	while (t--){
		string ins;
		int a, b, d;
		cin >> ins >> a >> b >> d;
		if ("check" == ins){
			check(a - 1, b - 1, d);
		}
		else{
			make(a - 1, b - 1, d);
			//show();
		}
	}
}

int main()
{
	solve();
	return 0;
}