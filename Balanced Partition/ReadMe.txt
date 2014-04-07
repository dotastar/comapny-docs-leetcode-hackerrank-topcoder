You have a set of n integers each in the range 0 … K. Partition these integers
into two subsets such that you minimize |S1 – S2|, where S1 and S2 denote the 
sums of the elements in each of the two subsets. Return the value of |S1 – S2|.


dozerg:
令T(i, j)表示前i个数的某个子集的和能否为j，则有状态转换方程：
T(i, j) = true, if j == 0;
        = true, if T(i-1, j) = true;
		= true, if T(i-1, j-Ai) = true
		= false, otherwise
所求问题可以转换成：
令S=SUM(Ai)，找到最接近S/2的j，使得T(n, j)=1，则结果为|S/2 - j|。
