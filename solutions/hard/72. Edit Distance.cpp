/* 
 * Problem: 72. Edit Distance [hard]
 * Source : https://leetcode.com/problems/edit-distance/description/
 * Solver : Baur Krykpayev
 * Date   : 07/04/2018
 */
 
class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int rows = word1.length()+1;
        int cols = word2.length()+1;
        vector<vector<int>> dp (rows, vector<int> (cols, 0));
        
        for (int r = 0; r < rows; r++) {dp[r][0] = r;}
        for (int c = 0; c < cols; c++) {dp[0][c] = c;}
        
        for (int r = 1; r < rows; r++) 
        {
            for (int c = 1; c < cols; c++)
            {
                if (word1[r-1] == word2[c-1])
                {
                    dp[r][c] = dp[r-1][c-1];
                }
                else
                {
                    dp[r][c] = min(dp[r-1][c-1], min(dp[r-1][c],dp[r][c-1]))+1;
                }
            }
        }
        
        
        return dp[rows-1][cols-1];
    }
};