2-D boxes stacking
类似下面的3D问题。


3-D boxes stacking
You are given a set of n types of rectangular 3-D boxes, where the i^th box 
has height h(i), width w(i) and depth d(i) (all real numbers). You want to 
create a stack of boxes which is as tall as possible, but you can only stack 
a box on top of another box if the dimensions of the 2-D base of the lower 
box are each strictly larger than those of the 2-D base of the higher box. 
Of course, you can rotate a box so that any side functions as its base. It 
is also allowable to use multiple instances of the same type of box

dozerg:
将所有box以及rotate之后的box，按照底面的长边进行从大到小排序，设为A[m]，m >= n；
令T(i)为A[1...i]中，以A[i]为顶的stack的最大高度，则有：
T(i) = MAX{T(j)} + A[i].height, if j < i && A[j].width > A[i].width && A[j].depth > A[i].depth
最终所求为 MAX{T(i)}, 1 <= i <= n



follow up:
This is the same problem as the example above, except here it is forbidden 
to use more than one instance of each type of box.

dozerg:
由于每个box最多有3种摆法（长宽高分别作为高度，且长>=宽），故使用每个box都有3种可能的最大高度
令T(i)表示使用前i-1个box，且把第i个box放在最顶上，能达到的最大高度（3个数值，以及3对长宽），则有：
T(i) = MAX{T(j)} + Height(i), if T(j)的长和宽 > i的长宽；Height(i)有3个值；