You have a set of n integers each in the range 0 �� K. Partition these integers
into two subsets such that you minimize |S1 �C S2|, where S1 and S2 denote the 
sums of the elements in each of the two subsets. Return the value of |S1 �C S2|.


dozerg:
��T(i, j)��ʾǰi������ĳ���Ӽ��ĺ��ܷ�Ϊj������״̬ת�����̣�
T(i, j) = true, if j == 0;
        = true, if T(i-1, j) = true;
		= true, if T(i-1, j-Ai) = true
		= false, otherwise
�����������ת���ɣ�
��S=SUM(Ai)���ҵ���ӽ�S/2��j��ʹ��T(n, j)=1������Ϊ|S/2 - j|��
