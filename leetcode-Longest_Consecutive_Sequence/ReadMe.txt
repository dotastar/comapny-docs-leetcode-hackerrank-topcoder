Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.


Solution:
Since it requires O(n) solution, normal sort won't be work here. Hash probably is the best choice.
3 Steps:
1. create the hashmap to hold <num, index>
2. scan the num vector from left to right, for each num
               i, check whether num -1 is in the map  (loop)
              ii, check whether num+1 is in the map  (loop)
3. track the sequence length during scanning.