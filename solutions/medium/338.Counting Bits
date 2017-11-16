/* 
 * Problem: 338. Counting Bits [medium]
 * Source: https://leetcode.com/problems/counting-bits/description/
 * Solver: Baur Krykpayev
 * Date  : 11/16/2017
 */
 
class Solution {
public:
    vector<int> countBits(int num) 
    {
        vector <int> dp;
        dp.push_back(0);
        
        for (int index = 1; index < num+1; index++)
        {
            int bits = index/2;
            
            if (index%2)
            {
                dp.push_back(dp[bits] + 1);
            }
            else
            {
                dp.push_back(dp[bits]);
            }
        }
        
        return dp;
    }
};