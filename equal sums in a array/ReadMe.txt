http://www.careercup.com/question?id=5652354158297088

You're given an array of integers(eg [3,4,7,1,2,9,8]) Find the index of values that satisfy A+B = C+D, where A,B,C & D are integers values in the array. 

Eg: Given [3,4,7,1,2,9,8] array 
The following 
3+7 = 1+9 satisfies A+B=C+D 
so print (0,2,3,5)


dozerg:
use hash map to record the sum of two pair and find two pairs which has the same sum. Time is O(n^2)