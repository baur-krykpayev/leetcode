/* 
 * Problem: 343. Integer Break[medium]
 * Source : https://leetcode.com/problems/integer-break/description/
 * Solver : Baur Krykpayev
 * Date   : 2/17/2018
 */

class Solution {
public:
    int integerBreak(int n) 
    {
        vector<int> dp(2,1);
        for (int i = 2; i <= n; i++)
        {
            int cur_max = 0;
            for (int j = 1; j <= i/2; j++)
            {
                int temp = max(j, dp[j]) * max(i-j, dp[i-j]);
                if (temp > cur_max) {cur_max = temp;}
            }
            dp.push_back(cur_max);
        }
        return dp[n];
    }
};