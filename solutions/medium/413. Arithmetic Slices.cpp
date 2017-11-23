/* 
 * Problem: 413. Arithmetic Slices[medium]
 * Source : https://leetcode.com/problems/arithmetic-slices/description/
 * Solver : Baur Krykpayev
 * Date   : 11/23/2017
 */
 
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) 
    {
        int dp = 0;
        int ret = 0;
        if (A.size() < 3){return 0;}
        
        for (int i = 2; i < A.size(); i++)
        {
            if (A[i] -  A[i-1] == A[i-1] - A[i-2])
            {
                dp++;
                ret += dp;
            }
            else
            {
                dp = 0;
            }
        }
        
        return ret;
    }
};