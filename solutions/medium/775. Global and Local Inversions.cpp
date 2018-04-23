/* 
 * Problem: 775. Global and Local Inversions [medium]
 * Source : https://leetcode.com/problems/global-and-local-inversions/description/
 * Solver : Baur Krykpayev
 * Date   : 4/23/2018
 */

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) 
    {
        for (int i = 0; i < A.size(); i++)
        {
            if (abs(A[i] - i) > 1){return false;}
        }
        
        return true;
    }
};