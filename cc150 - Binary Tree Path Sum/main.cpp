#include "../inc.h"

struct CPath
{
	int sum;
	vector<int> nodes;
	CPath() :sum(0){}
	void add(int v, bool front = false){
		sum += v;
		if (front)
			nodes.insert(nodes.begin(), v);
		else
			nodes.push_back(v);
	}
	void addRev(int v, bool front = false){
		sum += v;
		reverse(nodes.begin(), nodes.end());
		if (front)
			nodes.insert(nodes.begin(), v);
		else
			nodes.push_back(v);
	}
};

void printPath(const CPath & p)
{
	for (auto v : p.nodes)
		cout << v << ' ';
}

void findPath(TreeNode * root, const vector<CPath> & lsave, const vector<CPath> & rsave, int sum)
{
	sum -= root->val;
	for (const auto & p : lsave){
		if (p.sum == sum){
			printPath(p);
			cout << root->val << endl;
		}
	}
	//right side
	for (const auto & p : rsave){
		if (p.sum == sum){
			cout << root->val << ' ';
			printPath(p);
			cout << endl;
		}
	}
	//both sides
	for (const auto & pl : lsave){
		int left = sum - pl.sum;
		for (const auto & pr : rsave){
			if (pr.sum == left){
				printPath(pl);
				cout << root->val << ' ';
				printPath(pr);
				cout << endl;
			}
		}
	}
}

void help(TreeNode * root, vector<CPath> & psave, int sum, bool left)
{
	if (NULL == root)
		return;
	vector<CPath> lsave, rsave;
	help(root->left, lsave, sum, true);
	help(root->right, rsave, sum, false);
	if (sum == root->val)
		cout << root->val << endl;
	//fill psave
	psave.resize(1);
	psave.back().add(root->val);
	for (const auto & p : lsave){
		psave.push_back(p);
		if (left)
			psave.back().add(root->val);
		else
			psave.back().addRev(root->val, true);
	}
	for (const auto & p : rsave){
		psave.push_back(p);
		if (!left)
			psave.back().add(root->val, true);
		else
			psave.back().addRev(root->val);
	}
	findPath(root, lsave, rsave, sum);
}

void solve(TreeNode * root, int sum)
{
	if (NULL == root)
		return;
	vector<CPath> lsave, rsave;
	help(root->left, lsave, sum, true);
	help(root->right, rsave, sum, false);
	findPath(root, lsave, rsave, sum);
}

int main()
{
	{
		vector<TreeNode> v(7);
		v[0].val = 1;
		v[0].left = &v[1];
		v[0].right = &v[2];
		v[1].val = -1;
		v[1].left = &v[3];
		v[1].right = &v[4];
		v[2].val = 2;
		v[2].left = &v[5];
		v[2].right = &v[6];
		v[3].val = -2;
		v[4].val = -3;
		v[5].val = 1;
		v[6].val = -2;
		solve(&v[0], 0);
	}
	system("pause");
	return 0;
}
