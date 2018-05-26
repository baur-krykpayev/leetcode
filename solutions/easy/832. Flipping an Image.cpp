/* 
 * Problem: 832. Flipping an Image [easy]
 * Source : https://leetcode.com/problems/flipping-an-image/description/
 * Solver : Baur Krykpayev
 * Date   : 5/26/2018
 */

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) 
    {
        int rows = A.size();
        int cols = A[0].size();
        
        for (int row = 0; row < rows; row++)
        {
            int l = 0; int r = cols-1;
            while (l <= r)
            {
                A[row][l] ^= 1;
                if (l != r){A[row][r] ^= 1;}
                swap(A[row][l++], A[row][r--]);
            }
        }
        
        return A;
    }
};