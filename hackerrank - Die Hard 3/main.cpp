#include <iostream>
#include <algorithm>

using namespace std;

//WRONG!
bool solve(int a, int b, int c){
	if (a < b)
		swap(a, b);
	if (c > a)
		return false;
	if (c == a || c == b || c == a % c)
		return true;
	if (c % b == 0)  //N jugs of b
		return true;
	if ((a + c) % b == 0)    //N jugs of b, plus a
		return true;
	if ((a - c) % b == 0)    //N jugs of b, plus a
		return true;
	return false;
}

int main(){
	int T;
	for (cin >> T; T > 0; --T){
		int a, b, c;
		cin >> a >> b >> c;
		if (solve(a, b, c))
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
	return 0;
}