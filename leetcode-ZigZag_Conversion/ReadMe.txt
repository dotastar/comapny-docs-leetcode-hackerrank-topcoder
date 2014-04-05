The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".


dozerg:
令R为行数，C = 2R - 2
则有：
Row 0: Index % C == 0
Row 1: Index % C == 1 or C - 1
Row 2: Index % C == 2 or C - 2
...
Row (R-1): Index % C == R - 1