Given n non-negative integers representing an elevation map where the width of 
each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped. 
Thanks Marcos for contributing this image!



对于任何一个坐标，检查其左右的最大坐标，然后相减就是容积。所以，
1. 从左往右扫描一遍，对于每一个坐标，求取左边最大值。
2. 从右往左扫描一遍，对于每一个坐标，求最大右值。
3. 再扫描一遍，求取容积并加和。
#2和#3可以合并成一个循环，


follow up:
如果我是面试官的话，在这里可以加一个变形。不求所有容积，而是求容积中的最大值。
这样就类似于Container With Most Water，但是又有不同的地方。这题里面每一个坐标本身是占体积的。
所以从两边往中间扫的时候，根本不知道中间坐标共占用了多少体积。