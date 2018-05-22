/* 
 * Problem: 416. Partition Equal Subset Sum [medium]
 * Source : https://leetcode.com/problems/partition-equal-subset-sum/description/
 * Solver : Baur Krykpayev
 * Date   : 5/21/2018
 */

class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int s = 0; for(int n : nums) {s += n;}

        if (s%2){return false;} s/=2;
        
        vector<bool> dp(s+1, false);
        dp[0] = true;

        for (int n : nums)
        {
            for (int i = s; i > 0; i--)
            {
                if (i >= n)
                {
                    dp[i] = dp[i] || dp[i-n];    
                }
            }
        }
        
        return dp[s];
    }
};