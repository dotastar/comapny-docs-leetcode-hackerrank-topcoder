I
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

II
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
对于除出现一次之外的所有的整数，其二进制表示中每一位1出现的次数是3的整数倍，将所有这些1清零，剩下的就是最终的数。
用ones记录到当前计算的变量为止，二进制1出现“1次”（mod 3 之后的 1）的数位。
用twos记录到当前计算的变量为止，二进制1出现“2次”（mod 3 之后的 2）的数位。
当ones和twos中的某一位同时为1时表示二进制1出现3次，此时需要清零。即用二进
制模拟三进制计算。最终ones记录的是最终结果。


给定一个包含n个整数的数组，有一个整数x出现b次，一个整数y出现c次，
其他所有的数均出现a次，其中b和c均不是a的倍数，找出x和y.