#include "../inc.h"

void solve(int a, int b, int x1, int k, int m)
{
	vector<int> save(1, x1);
	map<int, int> pos;
	pos[x1] = save.size();
	int s = x1;
	for (;; ){
		s = (a * s + b) % m;
		int & p = pos[s];
		if (!p){
			save.push_back(s);
			p = save.size();
		}else{
			s = p - 1;	//circle start index
			break;
		}
	}
	const int c = save.size() - s;	//circle length
	for (int e = --k + 4; k <= e; ++k){
		int i = s + (k - s) % c;
		cout << save[i] << endl;
	}
}

int main()
{
	solve(3, 2, 5, 1, 7);
	cout << "---\n";
	solve(1234, 5678, 123, 12345, 9876);
	system("pause");
}