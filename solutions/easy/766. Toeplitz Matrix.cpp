/* 
 * Problem: 766. Toeplitz Matrix [easy]
 * Source : https://leetcode.com/problems/toeplitz-matrix/description/
 * Solver : Baur Krykpayev
 * Date   : 5/24/2018
 */

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) 
    {
        int row = matrix.size();
        int col = matrix[0].size();
        
        for (int r = 1; r < row; r++)
        {
            for (int c = 1; c < col; c++)
            {
                if (matrix[r][c] != matrix[r-1][c-1])
                {
                    return false;
                }
            }
        } 
        return true;
    }
};