/* 
 * Problem: 64. Minimum Path Sum[medium]
 * Source : https://leetcode.com/problems/minimum-path-sum/description/
 * Solver : Baur Krykpayev
 * Date   : 12/10/2017
 */
 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {             
                if(i == 0 && j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (i == 0)
                {
                    dp[i][j] = dp[i][j-1]; 
                }
                else if (j == 0)
                {
                    dp[i][j] = dp[i-1][j]; 
                }
                else
                {
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j]);
                }
               
                dp[i][j] += grid[i][j];
            }
        }
            
        return dp[rows-1][cols-1];     
        
    }
};