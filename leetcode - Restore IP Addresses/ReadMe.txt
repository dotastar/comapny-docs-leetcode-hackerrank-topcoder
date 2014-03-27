Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

递归的将数字串分成四个部分，每个部分满足0<=p<=255。要注意一些边界case，比如010是没有意思的，“0.10.010.1”。