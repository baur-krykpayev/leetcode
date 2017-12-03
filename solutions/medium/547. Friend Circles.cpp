/* 
 * Problem: 547. Friend Circles[medium]
 * Source : https://leetcode.com/problems/friend-circles/description/
 * Solver : Baur Krykpayev
 * Date   : 12/03/2017
 */
 
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) 
    {
        int count = 0;
        vector<bool> visited(M[0].size(), false);
        
        for (int i = 0; i < M[0].size(); i++)
        {  
            if (!visited[i])
            {
                dfs(i, visited, M);
                count++;
            }
        }
        
        return count;
    }

private:
    
    // helper depth first search function
    void dfs(int i, vector<bool> &visited, vector<vector<int>>& M)
    {
        for (int j = 0; j < M[0].size(); j++)
        {
            if (M[i][j] == 1 && !visited[j]) 
            {
                visited[j] = true;
                dfs(j, visited, M);
            }
        }
    }
};