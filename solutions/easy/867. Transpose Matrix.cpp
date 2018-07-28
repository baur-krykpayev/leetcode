/* 
 * Problem: 867. Transpose Matrix [easy]
 * Source : https://leetcode.com/problems/transpose-matrix/description/
 * Solver : Baur Krykpayev
 * Date   : 07/28/2018
 */

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) 
    { 
        int rows = A[0].size();
        int cols = A.size();
        vector<vector<int>> ans(rows, vector<int> (cols, 0));
        
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                ans[r][c] = A[c][r];
            }
        }
        
        return ans;
    }
};