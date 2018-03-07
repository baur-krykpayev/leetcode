/* 
 * Problem: 377. Combination Sum IV [medium]
 * Source : https://leetcode.com/problems/combination-sum-iv/description/
 * Solver : Baur Krykpayev
 * Date   : 3/7/2018
 */

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        if(!nums.size()) {return 0;}
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= target; i++)
        {
            int temp = 0;
            for (int num = 0; num < nums.size(); num++)
            {
                int ind = i - nums[num];
                if (ind >= 0)
                {
                    temp += dp[ind];    
                }
            }
            dp[i] = temp;
        }
        
        return dp[target];
    }
};