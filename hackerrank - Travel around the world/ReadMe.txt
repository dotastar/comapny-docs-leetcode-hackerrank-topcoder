https://www.hackerrank.com/contests/w2/challenges/travel-around-the-world

There are N cities and N directed roads in Steven’s world. The cities are numbered from 0 to N - 1. Steven can travel from city i to city (i + 1) % N, ( 0-> 1 -> 2 -> …. -> N - 1 -> 0).

Steven wants to travel around the world by car. The capacity of his car’s fuel tank is C gallons. There are a[i] gallons he can use at the beginning of city i and the car takes b[i] gallons to travel from city i to (i + 1) % N.

How many cities can Steven start his car from so that he can travel around the world and reach the same city he started?

Note

The fuel tank is initially empty.

Input Format
The first line contains two integers (separated by a space): city number N and capacity C.
The second line contains N space-separated integers: a[0], a[1], … , a[N - 1].
The third line contains N space-separated integers: b[0], b[1], … , b[N - 1].

Output Format
The number of cities which can be chosen as the start city.

Constraints

2 ≤ N ≤ 10^5 
1 ≤ C ≤ 10^18
1 ≤ a[i], b[i] ≤ 10^9

Sample Input

3 3
3 1 2
2 2 2
Sample Output

2
Explanation

Steven starts from city 0, fills his car with 3 gallons of fuel, and use 2 gallons of fuel to travel to city 1. His fuel tank now has 1 gallon of fuel. 
On refueling 1 gallon of fuel at city 1, he then travels to city 2 by using 2 gallons of fuel. His fuel tank is now empty.
On refueling 1 gallon of fuel at city 2, he then travels back to city 0 by using 2 gallons of fuel.

Here is the second possible solution.
Steven starts from city 2, fill his car with 2 gallons, and travels to city 0. 
On refueling 3 gallons of fuel from city 0, he then travels to city 1, and exhausts 2 gallons of fuel. His fuel tank contains 1 gallon of fuel now. He can then refuel 1 gallon of fuel at City 1, and increase his car’s fuel to 2 gallons and travel to city 2.

However, Steven cannot start from city 1, because he is given only 1 gallon of fuel, but travelling to city 2 requires 2 gallons.

Hence the answer 2.



dozerg:
最简单的方法，自然是把每个城市作为起点，遍历是否能环游，Solution1，复杂度O(N^2)。

Solution2是O(N)的算法，思想如下：
令G(i)表示在城市i时，加油之前，油箱里的最少油量，不包括A[i]；
令M(i)表示在城市i时，加油之后，油箱里的最少油量；

则有：M(i) = G(i+1) + B[i]；
解释：
显然，因为到(i+1)时必须剩余G(i+1)的油量，而从i到(i+1)消耗B[i]的油量，故从i出发时油箱里最少要有(G(i+1) + B[i])的油量。
如果M[i] > C，则不可能环游所有城市；

还有：G(i) = MAX{M(i) - A[i], 0}
解释：
既然加油后需要有M(i)油量，则加油前只要剩余(M(i) - A[i])就行了，并且不能小于0；
如果G(i) == 0，则说明可以从i开始空油箱环游所有城市，即可以从i开始环游。

那么剩余的问题就是，初始G(i)怎么取。
其实可以从任意城市i开始，假定G(i+1)=0，依次计算出G(i), G(i-1), G(i-2), ..., G(i+1)，
然后再来一轮，这次使用真正的G(i+1)。
如果发现第二轮的G(i+1)和第一轮的一样，说明已经得到了最终的所有G(i)，不用再继续了。
最后看看多少个G(i)==0，就是最终结果。

全部计算可以在2轮遍历内完成，时间复杂度O(N)。
