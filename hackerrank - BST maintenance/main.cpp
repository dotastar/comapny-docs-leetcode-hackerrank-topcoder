#include "../inc.h"

struct CTreeDistance
{
    CTreeDistance(size_t n) :root(NULL), sum(0){
        dis.reserve(n);
    }
    ~CTreeDistance(){ delete root; }
    void add(int val){
        //insert tree
        TreeNode * prev = NULL;
        if (!root){
            root = new TreeNode(val);
        }else
            prev = insertTree(root, val);
        //calc distance
        vector<int> cur(dis.size());
        if (prev){
            const size_t pidx = idx(prev->val);
            for (size_t i = 0; i < dis.size(); ++i){
                cur[i] = disOf(i, pidx) + 1;    //---
                sum += cur[i];
            }
        }
        cur.push_back(0);   //self -> self
        //update
        val2idx[val] = dis.size();
        dis.resize(dis.size() + 1);
        dis.back().swap(cur);
    }
    long long distanceSum() const{ return sum; }
private:
    static TreeNode * insertTree(TreeNode * root, int val){
        assert(root);
        if (val < root->val){
            if (root->left)
                return insertTree(root->left, val);
            root->left = new TreeNode(val);
        } else{
            if (root->right)
                return insertTree(root->right, val);
            root->right = new TreeNode(val);
        }
        return root;
    }
    size_t idx(int val) const{
        map<int, size_t>::const_iterator wh = val2idx.find(val);
        assert(wh != val2idx.end());
        return wh->second;
    }
    int disOf(size_t i, size_t j) const{
        if (i < j)
            swap(i, j);
        assert(i < dis.size());
        assert(j < dis[i].size());
        return dis[i][j];
    }
    //fields
    TreeNode * root;
    long long sum;
    vector<vector<int> > dis;
    map<int, size_t> val2idx;
};

void solve(const vector<int> & A)
{
    if (A.empty())
        return;
    CTreeDistance t(A.size());
    for (size_t i = 0; i < A.size(); ++i){
        t.add(A[i]);
        cout << t.distanceSum() << endl;
    }
}

void test()
{
    solve({ 4, 7, 3, 1, 8, 2, 6, 5 });
    {
        vector<int> A;
        for (int i = 1; i <= 100000; ++i)
            A.push_back(i);
        random_shuffle(A.begin(), A.end());
        cout << "---\n";
        solve(A);
    }
}

int main()
{
    test(); return 0;
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    solve(A);
}
