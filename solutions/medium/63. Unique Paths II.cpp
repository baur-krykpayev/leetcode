/* 
 * Problem: 63. Unique Paths II[medium]
 * Source : https://leetcode.com/problems/unique-paths-ii/description/
 * Solver : Baur Krykpayev
 * Date   : 02/03/2018
 */
 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        int hash[rows][cols];
        int step = 1;
        
        //go over top
        for (int c = 0; c < cols; c++)
        {   
            if (obstacleGrid[0][c])
            {
                step = 0;
            }
            hash[0][c] = step;
        }
        
        // go over left
        step = 1;
        for (int r = 0; r < rows; r++)
        {   
            if (obstacleGrid[r][0])
            {
                step = 0;
            }
            hash[r][0] = step;
        }
        
        for (int r = 1; r < rows; r++)
        {
            for (int c = 1; c < cols; c++)
            {
                if (!obstacleGrid[r][c])
                {
                    if(!hash[r-1][c] && !hash[r][c-1])
                    {
                        hash[r][c] = 0;
                    }
                    else if(!hash[r-1][c])
                    {
                        hash[r][c] = hash[r][c - 1];    
                    }
                    else if (!hash[r][c-1])
                    {
                        hash[r][c] = hash[r - 1][c];    
                    }
                    else 
                    {
                        hash[r][c] = hash[r][c-1] + hash[r-1][c];
                    }
                }
                else
                {
                    hash[r][c] = 0;
                }
            }
        }

        return hash[rows - 1][cols - 1];      
    }
};