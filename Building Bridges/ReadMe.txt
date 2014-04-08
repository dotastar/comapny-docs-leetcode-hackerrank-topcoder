Consider a 2-D map with a horizontal river passing through its center. 
There are n cities on the southern bank with x-coordinates a(1) ... a(n) 
and n cities on the northern bank with x-coordinates b(1) ... b(n). You 
want to connect as many north-south pairs of cities as possible with 
bridges such that no two bridges cross. When connecting cities, you can 
only connect city i on the northern bank to city i on the southern bank.


dozerg:
将city pairs按照x坐标排序，令T(i)表示前i个pair中，连接pair[i]后，能达到的最多bridge数，则有：
T(i) = MAX{T(j)} + 1, if j < i && pair[j].southern <= pair[i].southern
最终所求为 MAX{t(i)}, 1 <= i <= n