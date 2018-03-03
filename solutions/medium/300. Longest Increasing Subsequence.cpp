/* 
 * Problem: 300. Longest Increasing Subsequence[medium]
 * Source : https://leetcode.com/problems/longest-increasing-subsequence/description/
 * Solver : Baur Krykpayev
 * Date   : 3/3/2018
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        if (!nums.size()) {return 0;}
        int n = nums.size();
        int dp[n];
        
        for (int i = 0; i < n; i++){dp[i]=1;}

        for (int cur = 1; cur < n; cur++)
        {
            for (int i = 0; i < cur; i++)
            {
                if(nums[cur] > nums[i])
                {
                    dp[cur] = max(dp[cur], dp[i]+1);
                }
            }   
        }

        int ret = 0;
        
        for(int val: dp)
        {
            ret = (val > ret) ? val : ret;
        }
        
        return ret;
    }
};