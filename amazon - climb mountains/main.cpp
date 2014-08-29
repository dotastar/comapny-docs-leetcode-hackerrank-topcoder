/*
一个人想从A地点到B地点，但是中间有若干坐矩形的山，用（start，to，height）描述。求这个人需要走多长的距离，才能到B。
补充：给出的start，to可能重叠；B等于最后一座山的to。
例如：
给定3坐山，分别是（1，3，2）（2，4，4）（6，7，5）
那么需要走的距离是25。（自己画图算）
*/

#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;


int main()
{
	int t;
	cin >> t;
	map <int, vector<pair<int, bool> > > ops;
	while (t--){
		int f, t, h;
		cin >> f >> t >> h;
		ops[f].push_back(make_pair(h, true));
		ops[t].push_back(make_pair(h, false));
	}
	multiset<int> heights;
	long long ret = 0;
	int x = 0, h = 0;
	for (const auto & p : ops){
		ret += p.first - x;
		x = p.first;
		for (const auto & s : p.second){
			if (s.second)
				heights.insert(s.first);
			else{
				auto wh = heights.find(s.first);
				if (wh != heights.end())
					heights.erase(wh);
			}
		}
		int nh = (heights.empty() ? 0 : *heights.rbegin());
		h -= nh;
		if (h < 0)
			h = -h;
		ret += h;
		h = nh;
	}
	cout << ret << endl;

	system("pause");
	return 0;
}