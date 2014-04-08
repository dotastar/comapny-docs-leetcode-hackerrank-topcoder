2-D boxes stacking
���������3D���⡣


3-D boxes stacking
You are given a set of n types of rectangular 3-D boxes, where the i^th box 
has height h(i), width w(i) and depth d(i) (all real numbers). You want to 
create a stack of boxes which is as tall as possible, but you can only stack 
a box on top of another box if the dimensions of the 2-D base of the lower 
box are each strictly larger than those of the 2-D base of the higher box. 
Of course, you can rotate a box so that any side functions as its base. It 
is also allowable to use multiple instances of the same type of box

dozerg:
������box�Լ�rotate֮���box�����յ���ĳ��߽��дӴ�С������ΪA[m]��m >= n��
��T(i)ΪA[1...i]�У���A[i]Ϊ����stack�����߶ȣ����У�
T(i) = MAX{T(j)} + A[i].height, if j < i && A[j].width > A[i].width && A[j].depth > A[i].depth
��������Ϊ MAX{T(i)}, 1 <= i <= n



follow up:
This is the same problem as the example above, except here it is forbidden 
to use more than one instance of each type of box.

dozerg:
����ÿ��box�����3�ְڷ�������߷ֱ���Ϊ�߶ȣ��ҳ�>=������ʹ��ÿ��box����3�ֿ��ܵ����߶�
��T(i)��ʾʹ��ǰi-1��box���Ұѵ�i��box������ϣ��ܴﵽ�����߶ȣ�3����ֵ���Լ�3�Գ��������У�
T(i) = MAX{T(j)} + Height(i), if T(j)�ĳ��Ϳ� > i�ĳ���Height(i)��3��ֵ��