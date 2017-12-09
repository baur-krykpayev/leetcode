/* 
 * Problem: 55. Jump Game[medium]
 * Source : https://leetcode.com/problems/jump-game/description/
 * Solver : Baur Krykpayev
 * Date   : 12/09/2017
 */
 
class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int target = nums.size() - 1;
        for (int i = nums.size() - 2; i>-1; i--)
        {
            if (i+nums[i] >= target)
            {
                target = i;
            }
        }
        
        return (target <= 0); 
    }
};