Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

dozerg:
��S(i)={MAX1, MAX2}��ʾ������A[0, i)�ĳ˻��е�2��ֵ�����У�
MAX1��ʾ����ֵ������������
MAX2��ʾ����ֵ���ĸ�������

����״̬ת�����̣�
if A[i] >= 0:
  S(i+1) = {
    MAX1 = max(A[i], S(i).MAX1 * A[i]),
    MAX2 = S(i).MAX2 * A[i],
  };
else if A[i] < 0:
  S(i+1) = {
    MAX1 = S(i).MAX2 * A[i],
	MAX2 = min(A[i], S(i).MAX1 * A[i]),
  }

S(1) = {A[0], A[0]}
����MAX1�е����ֵ����������