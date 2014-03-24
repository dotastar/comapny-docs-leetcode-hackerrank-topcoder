A k-palindrome is a string which transforms into a palindrome on removing at most k characters. 

Given a string S, and an interger K, print "YES" if S is a k-palindrome; otherwise print "NO". 
Constraints: 
S has at most 20,000 characters. 
0<=k<=30 

Sample Test Case#1: 
Input - abxa 1 
Output - YES 
Sample Test Case#2: 
Input - abdxa 1 
Output - No


But we can improve it by using edit distance algorithm. Here is the algo with edit distance:
It has time complexity O(n^2).

public static boolean isKPalindrome(String source, int k){
    return k == editDistance(source)/2;
}
 
public static int editDistance(String source){
    int n= source.length();
    int[][] distance=new int[n+1][n+1];
    for(int i=0;i<=n;i++){
        distance[i][0]=i;
    }
    for(int j=0;j<=n;j++){
        distance[0][j]=j;
    }
    for(int j=1;j<=n;j++){
      for(int i=1;i<=n;i++){
        if(source.charAt(i-1)==source.charAt(n-1-(j-1))){
            distance[i][j]=distance[i-1][j-1];
        }
        else{
            distance[i][j]= Math.min((distance[i-1][j]+1),(distance[i][j-1]+1));
        }
      }
    }
    return(distance[n][n]);
  }
 
 
public static void main(String[] args) {
    System.out.println(isKPalindrome("abaxbabax", 2));
}