http://www.careercup.com/question?id=5685788633202688

Suppose we are given a set L of n line segments in the plane, where the endpoints of each 
segment lie on the unit circle x^2 + y^2 = 1, and all 2n endpoints are distinct. Describe 
and analyze an algorithm to compute the largest subset of L in which no pair of segments 
intersects.

dozerg:
假设有n条线段，起点和终点都在单位圆周上，且各不相同，设计算法求出不相交的最多线段集合。

解：
将所有顶点转换成极坐标系下的(angle, radius)，则所有radius=1。
则n条线段可用n个(angle1, angle2)来表示，注意统一顺时针或者逆时针的顺序，且处理大于180度的情况；
这样问题转化为“Movie Scheduling Problem”，解法如下：
将n条线段按照angle2进行排序，采用贪心算法，总是选取angle2最小的线段，并剔除交叉的线段；再选angle2最小的线段，再剔除交叉线段；直到n条线段处理完成；
最后得到的就是不相交的最多线段集合。
注意：
圆是首位相接的，所以如果有线段横跨０度，则需要特殊处理。
