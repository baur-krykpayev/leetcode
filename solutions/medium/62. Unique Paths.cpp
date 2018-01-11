/* 
 * Problem: 62. Unique Paths [medium]
 * Source : https://leetcode.com/problems/unique-paths/description/
 * Solver : Baur Krykpayev
 * Date   : 01/11/2018
 */
 
class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        int hash[m][n];
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0) 
                {
                    hash[i][j] = 1;
                }
                else
                {
                    hash[i][j] = hash[i][j-1] + hash[i-1][j];
                }
            }
        }
        
        return hash[m-1][n-1];
    }
};