You are given an integer K, and a sorted array as an 
input which has been rotated about an unknown pivot. 
For example, 4 5 6 7 8 9 1 2 3. 
We need to write a function which should return the 
index of K in the array, if K is present, else return -1.


PrincessMaja:
Actually, you can do a little simpler than that. 
You don't actually need the pivot index. We just 
need to compare the mid element with rightmost and 
leftmost elements. If mid element is larger than 
leftmost element, bottom half of the array is 
properly sorted. In this case, we have a plain 
binary search (if element we are searching for 
is between leftmost and middle element, look at 
the lower half of the array; otherwise look at 
the upper half of the array).
If mid element is smaller than leftmost element, 
upper half of the array is sorted. Accordingly, 
we look if the given element is at the upper of 
lower part.

int search(int A[], int N, int key) {
  int left = 0;
  int right = N - 1;
 
  while (left <= right) {
 
    int mid = left + ((right-left) / 2);
    if (A[mid] == key) return mid;
 
    // the bottom half is sorted
    if (A[left] <= A[mid]) {
      if (A[left] <= key && key < A[mid])
        right = mid -1;
      else
        left = mid+1;
    }
    // the upper half is sorted
    else {
      if (A[mid] < key && key <= A[right])
        left = mid+1;
      else
        right = mid-1;
    }
  }
  return -1;
}


4 5 6 7 8 9 1 2 3
9
left  0 5
right 8 5
mid   4 6