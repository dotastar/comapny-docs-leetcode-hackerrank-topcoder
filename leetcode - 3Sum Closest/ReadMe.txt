Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
   
   
   
The idea is the same as in the 3SUM question. Sort the array, and in O(n2) time find the closest value.
public int threeSumClosest(int[] num, int target) {
  Arrays.sort(num);
  int minDiff = Integer.MAX_VALUE;
  int bestSum = 0;

  for(int i = 0; i < num.length-2; i++){
    int j = i+1;
    int k = num.length-1;

    while(j < k){
      int sum = num[i] + num[j] + num[k];
      if(Math.abs(sum-target) < minDiff){
        minDiff = Math.abs(sum-target);
        bestSum = sum;
      } 

      if(sum > target) k--;
      else j++;
    }
  }
  return bestSum;
}