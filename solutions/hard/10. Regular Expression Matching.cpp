/* 
 * Problem: 10. Regular Expression Matching [hard]
 * Source : https://leetcode.com/problems/regular-expression-matching/description/
 * Solver : Baur Krykpayev
 * Date   : 07/03/2018
 */
 
class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int rows = s.length();
        int cols = p.length();
        vector<vector<bool>> dp(rows+1, vector<bool> (cols+1, false));
        dp[0][0] = true;
        
        for (int c = 1; c < cols+1; c++)
        {
            if (p[c-1] == '*')
            {
                dp[0][c] = dp[0][c-2];    
            }
        }
        
        for(int r = 1; r < rows+1; r++)
        {
            for(int c = 1; c < cols+1; c++)
            {
                if (p[c-1] == '*')
                {
                    if (s[r-1] == p[c-2] || p[c-2] == '.')
                    {
                        dp[r][c] = dp[r-1][c];
                    }
                    
                    if (c > 1 && dp[r][c-2])
                    {
                        dp[r][c] = true;    
                    }
                }
                else if (s[r-1] == p[c-1] || p[c-1] == '.')
                {
                    dp[r][c] = dp[r-1][c-1];
                }
            }
        }
        
        return dp[rows][cols];
    }
};