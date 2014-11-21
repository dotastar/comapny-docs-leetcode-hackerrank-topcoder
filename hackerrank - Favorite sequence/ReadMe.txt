Johnny, like every mathematician, has his favorite sequence of distinct natural numbers. Let¡¯s call this sequence M. Johnny was very bored, so he wrote down N copies of the sequence M in his big notebook. One day, when Johnny was out, his little sister Mary erased some numbers from every copy of M and then threw the notebook out onto the street. You just found it. Can you reconstruct the sequence? 

In the input there are N sequences of natural numbers representing the N copies of the sequence M after Mary¡¯s prank. In each of them all numbers are distinct. Your task is to construct the shortest sequence S that might have been the original M. If there are many such sequences, return the lexicographically smallest one. It is guaranteed that such a sequence exists.

Note 
Sequence A[1¡­n] is lexicographically less than sequence B[1¡­n] if and only if there exists 1¡Üi¡Ün such that for all 1¡Üj<i,A[j]=B[j]  and  A[i]<B[i].

Input Format

In the first line, there is one number N denoting the number of copies of M. 
This is followed by K 
and in next line a sequence of length K representing one of sequences after Mary's prank. All numbers are separated by a single space.

Constraints 
1¡ÜN¡Ü10^3 
2¡ÜK¡Ü10^3 
All values in one sequence are distinct numbers in range [1,10^6].

Output Format

In one line, write the space-separated sequence S - the shortest sequence that might have been the original M. If there are many such sequences, return the lexicographically smallest one.

Sample Input

2
2
1 3
3
2 3 4
Sample Output

 1 2 3 4
Explanation

You have 2 copies of the sequence with some missing numbers: [1,3] and [2,3,4]. There are two candidates for the original sequence M:[1,2,3,4] and [2,1,3,4], where the first one is lexicographically least.