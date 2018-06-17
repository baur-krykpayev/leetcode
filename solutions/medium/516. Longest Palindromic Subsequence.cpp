/* 
 * Problem: 516. Longest Palindromic Subsequence [medium]
 * Source : https://leetcode.com/problems/longest-palindromic-subsequence/description/
 * Solver : Baur Krykpayev
 * Date   : 06/16/2018
 */
 
class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        if (!s.length()){return 0;}
        int n = s.length();
        vector<vector<int>> dp (n, vector<int> (n,1));
        
        for (int l = 1; l < n; l++)
        {
            for (int r = 0; r < n-l; r++)
            {
                if (s[r] == s[r+l])
                {
                    dp[r][r+l] = (l==1) ? 2 : 2 + dp[r+1][r+l-1]; 
                }
                else
                {
                    dp[r][r+l] = max(dp[r+1][r+l], dp[r][r+l-1]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};