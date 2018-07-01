/* 
 * Problem: 361. Bomb Enemy [medium]
 * Source : https://leetcode.com/problems/bomb-enemy/description/
 * Solver : Baur Krykpayev
 * Date   : 07/01/2018
 */
 
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) 
    {        
        int ans = 0;
        if (!grid.size()) {return ans;}
        
        int rows = grid.size();
        int cols = grid[0].size();
    
        vector<int> upper(cols, 0);
        
        for (int r = 0; r < rows; r++)
        {
            int left = 0;
            for (int c = 0; c < cols; c++)
            {
                char cell = grid[r][c];
                
                if (cell == 'E')
                {
                    left++;
                    upper[c]++;
                }
                else if (cell == 'W')
                {
                    left = 0;
                    upper[c] = 0;
                }
                else // cell == '0'
                {
                    int i = c+1;
                    int right = 0;
                    while (i < cols && grid[r][i] != 'W')
                    {
                        if (grid[r][i] == 'E'){right++;}
                        i++;    
                    }
                    
                    i = r+1;
                    int bottom = 0;
                    
                    while (i < rows && grid[i][c] != 'W')
                    {
                        if (grid[i][c] == 'E'){bottom++;}
                        i++;    
                    }
                    
                    ans = max(ans, left + upper[c] + right + bottom);
                }
            }
        }
        
        return ans;
    }
};