/* 
 * Problem: 48. Rotate Image[medium]
 * Source : https://leetcode.com/problems/rotate-image/description/
 * Solver : Baur Krykpayev
 * Date   : 2/17/2018
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        
        for (int i = 0; i < n/2; i++)
        {
            int start = i;
            int end = n-i-1;
            for (int k = start; k < end; k++)
            {
                swap(matrix[start][k], matrix[start+end-k][start]);
                swap(matrix[start+end-k][i], matrix[end][start+end-k]);
                swap(matrix[end][start+end-k], matrix[k][end]);
            }
        }
    }
};