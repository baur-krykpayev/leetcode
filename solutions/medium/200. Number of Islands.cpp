/* 
 * Problem: 200. Number of Islands[medium]
 * Source : https://leetcode.com/problems/number-of-islands/description/
 * Solver : Baur Krykpayev
 * Date   : 12/17/2017
 */

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        if (!grid.size()) {return 0;}
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));
        int count = 0;
        
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    dfs(grid, visited, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
    
private:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j)
    {        
        visited[i][j] = true;
        
        if (i != grid.size()-1 && grid[i+1][j] == '1' && !visited[i+1][j])
        {
            dfs(grid, visited, i+1, j);
        }

        if (j != grid[0].size()-1 && grid[i][j+1] == '1' && !visited[i][j+1])
        {
            dfs(grid, visited, i, j+1);
        }
        
        if (i && grid[i-1][j] == '1' && !visited[i-1][j])
        {
            dfs(grid, visited, i-1, j);
        }

        if (j && grid[i][j-1] == '1' && !visited[i][j-1])
        {
            dfs(grid, visited, i, j-1);
        }
    }
};