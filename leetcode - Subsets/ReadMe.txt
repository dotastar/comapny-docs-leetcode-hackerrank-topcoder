I
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

II
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]



answered Oct 26, 2013 by coldz:
Here is the answer I found from old discuss forum for SUBSETS I:

vector<vector<int> > subsets(vector<int> &S) {
    sort(S.begin(), S.end());
    vector<vector<int> > v(1);
    for(int i = 0; i < S.size(); ++i) {
        int j = v.size();
        while(j-- > 0) {
            v.push_back(v[j]);
            v.back().push_back(S[i]);
        }
    }
    return v;
}
The above answer just need small modification to handle problem SUBSETS II.

if a number from S is the first one of the numbers with the same value, it can be used to extend all previous subsets and create new non-duplicate subsets.

if a number from S is a duplicated number of some value, it cannot be used to extend all previous subsets. Only part of them. The idea is that this number should help make some different subsets than its predecessor. So it only needs to extend subsets which contains its predecessor.

e.g. [ 1 2 2]

[ ]

[1]

[1 2] [2]

// now predecessor is the first 2, we will only extend subsets which already contains the first 2, go no further...

[1 2 2] [2 2]

    //answer for SUBSETS II
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> result(1);
        int oldval=S[0];
        int oldj=0;
        for(int i=0; i<S.size(); i++){
            int temp=oldj;
            if(S[i]!=oldval){
                oldval=S[i]; temp=0;
            }
            int j=result.size();
            oldj=j;
            while(j-->temp){
                //note temp here help avoid creating duplicate subsets
                result.push_back(result[j]);
                result.back().push_back(S[i]);
            }
        }
        return result;
    } 