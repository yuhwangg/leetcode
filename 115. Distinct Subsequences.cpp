/*115. Distinct Subsequences 不同的子序列
 
Given a string s and a string t, count the number of distinct subsequences of t in s.

A subsequence of a string is a new string which is formed from the original string by deleting some 
(can be none) of the characters without disturbing the relative positions of the remaining characters. 
(ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Example 1:
Input: S = "rabbbit", T = "rabbit"
Output: 3
Explanation:

As shown below, there are 3 ways you can generate "rabbit" from S.
(The caret symbol ^ means the chosen letters)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^

Example 2:
Input: S = "babgbag", T = "bag"
Output: 5
Explanation:

As shown below, there are 5 ways you can generate "bag" from S.
(The caret symbol ^ means the chosen letters)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^


看到有关字符串的子序列或者配准类的问题，首先应该考虑的就是用动态规划Dynamic Programming来求解，这个应成为条件反射。
而所有DP问题的核心就是找出递推公式，想这道题就是递推一个二维的dp数组，下面我们从题目中给的例子来分析，这个二维dp数组应为：


  Ø r a b b b i t
Ø 1 1 1 1 1 1 1 1
r 0 1 1 1 1 1 1 1
a 0 0 1 1 1 1 1 1
b 0 0 0 1 2 3 3 3
b 0 0 0 0 1 3 3 3
i 0 0 0 0 0 0 3 3
t 0 0 0 0 0 0 0 3 

首先，若原字符串和子序列都为空时，返回1，因为空串也是空串的一个子序列。若原字符串不为空，而子序列为空，也返回1，
因为空串也是任意字符串的一个子序列。而当原字符串为空，子序列不为空时，返回0，因为非空字符串不能当空字符串的子序列。
理清这些，二维数组dp的边缘便可以初始化了，下面只要找出递推式，就可以更新整个dp数组了。我们通过观察上面的二维数组可以发现，
当更新到dp[i][j]时，dp[i][j] >= dp[i][j - 1] 总是成立，再进一步观察发现，当 T[i - 1] == S[j - 1] 时，
dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1]，若不等， dp[i][j] = dp[i][j - 1]，所以，综合以上，递推式为：

dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0)

根据以上分析，可以写出代码如下：*/

 
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.size(), n = s.size();
        int dp[m+1][n+1];
        for (int i = 1; i <= m; i++){ 
            dp[i][0] = 0; 
        }
        for (int i = 0; i <= n; i++) {
            dp[0][i] = 1;   
        } 
 
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (t[i-1] == s[j-1] ){
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                }else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
};




