/* 
 * Problem: 695. Max Area of Island [easy]
 * Source : https://leetcode.com/problems/max-area-of-island/description/
 * Solver : Baur Krykpayev
 * Date   : 06/16/2018
 */
 
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        rows = grid.size(); cols = grid[0].size();
        vector<vector<bool>> visited (rows, vector<bool>(cols, false));
        int ret = 0;    
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                ret = max(ret, dfs(i, j, grid, visited));
            }
        }
        
        return ret;
    }
    
private:
    int rows = 0;
    int cols = 0;
    
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols || !grid[r][c] || visited[r][c])
        {
            return 0;
        }
            
        visited[r][c] = true;
        return (dfs(r+1, c, grid, visited) +
                dfs(r-1, c, grid, visited) +
                dfs(r, c+1, grid, visited) +
                dfs(r, c-1, grid, visited) + 1);
    }
};