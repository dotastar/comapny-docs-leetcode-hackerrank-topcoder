Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.


dozerg:
�㷨���Ӷȷ�����
����k��list��ƽ��ÿ��list����Ϊn��
T(n, k) = T(2n, k/2) + nk   //ÿ�κϲ���list����Ϊ2n������Ϊk/2���ϲ������н���nk�β���
        = T(4n, k/4) + 2nk
        = ...
        = T(kn, 1) + log(k)*nk
��N=nkΪnode��������ô���ո��Ӷ�Ϊ��O(N * logK)
