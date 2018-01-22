/* 
 * Problem: 73. Set Matrix Zeroes[medium]
 * Source : https://leetcode.com/problems/set-matrix-zeroes/discuss/
 * Solver : Baur Krykpayev
 * Date   : 1/22/2018
 */
 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        vector<vector<int>> result = matrix;
        
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int k = 0; k < matrix[0].size(); k++)
            {
                if(!result[i][k])
                {
                    for (int c = 0; c < matrix[0].size(); c++)
                    {
                        matrix[i][c] = 0;
                    } 
                    
                    for (int c = 0; c < matrix.size(); c++)
                    {
                        matrix[c][k] = 0;
                    } 
                }
            }
        }
    }
};