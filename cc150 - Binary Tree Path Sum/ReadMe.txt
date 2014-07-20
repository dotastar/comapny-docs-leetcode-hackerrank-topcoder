4.8
You are given a binary tree in which each node contains a value. Design an algorithm 
to print all paths which sum up to a given value. Note that it can be any path in the tree 
- it does not have to start at the root.



dozerg:
for each node N:
1. consider left sub tree (rooted by N.left), all possible root started paths and sums: lsave;
2. and consider right sub tree (rooted by N.right), all possible root started paths and sums: rsave;

then seach paths that contain N but not N's parent that sum to the given value.
1. only N;
2. from lsave to N;
3. from N to rsave;
4. from lsave to N to rsave;

if found, print the path (be careful of the rsave segment's order).

then move to N's children and repeat the process.

since lsave and rsave computation is effective from leaf to root, 
so I use recursion to reach the leaf,
and compute the crossing leaf path first.
then in the backtrace process, I compute the parent node's lsave and rsave (based on its' children's lsave and rsave),
and compute the crossing parent path.
and backtrace to the root finally.

Complexity:
each node is visited only once.
for each node, the lsave size is equal to left sub tree nodes, and rsave size is equal to right sub tree nodes, which is O(N);
so the combination is O(N^2).
so the total complexity is:
O(N/2 * N/2 + 2 * N/4 * N/4 + 4 * N/8 * N/8 + ...) =
O(N^2 * (1/4 + 1/8 + 1/16 + ...)) = 
O(N^2 /2) = 
O(N^2)



 