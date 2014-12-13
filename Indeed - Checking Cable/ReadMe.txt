Time limit : 2sec / Stack limit : 256MB / Memory limit : 256MB
Question
Your task is to connect N computers with cables that can communicate in both directions and to check if those computers can actually interact with each other.
Your work will follow the two instructions shown below:
1.	make A B time
?	Connect Computer A and Computer B with a cable.
?	This cable will become unavailable when the value is bigger than time seconds. If the value equals to time seconds, the cable is still available.
?	Multiple cables may be connected between aforementioned Computer A and B.
2.	check A B time
?	Predict if computer A and B can communicate within time seconds with the connected cable(s).
?	Computer A and B may be connected through other computers.
?	If Computer A and B can communicate, output YES in one string. If they can¡¯t, output NO in one string.
?	The cables that are connected by all the make instructions existing after particular check instruction are not available in time series.
The instructions will be processed in the descending order of input.
Determine if Computer A and B are able to communicate every time there is check instruction. If they can communicate, please output YES in one string. If not, output NO in one string.
________________________________________
Input
Input will be given in the following format from Standard Input:
N Q
S1 A1 B1 time1
:
SQ AQ BQ timeQ
1.	On the first string, N(2¨QN¨Q20), an integer which shows the number of computers, and Q(1¨QQ¨Q500), another integer which shows the number of the instructions, will be given with a half-width break.
2.	From the second string to the N?th string, you will be given instructions.
?	1¨QAk , Bk¨QN and 1¨Qtimek¨Q10^4 are guaranteed.
?	There are only two kinds of Sk: make or check.
Output
Determine if Computer A and B are able to communicate every time there is check instruction. If they can communicate, please output YES in one string. If not, output NO in one string.
Also, make sure to insert a line break at the end of the output.
________________________________________
Input Example # 1
3 5
make 1 2 1000
check 1 3 500
make 3 2 2000
check 1 3 500
check 1 3 1500
Output Example #1
NO
YES
NO
________________________________________
Input Example #2
4 11
make 1 2 2000
make 2 3 3000
make 3 4 2500
check 1 4 1500
check 1 3 2000
check 1 3 2500
make 1 4 3000
check 1 3 2500
check 1 3 3000
make 2 4 3000
check 1 3 3000
Output Example #2
YES
YES
NO
YES
NO
YES
