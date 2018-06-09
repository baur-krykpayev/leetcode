/* 
 * Problem: 128. Longest Consecutive Sequence [hard]
 * Source : https://leetcode.com/problems/longest-consecutive-sequence/description/
 * Solver : Baur Krykpayev
 * Date   : 6/9/2018
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if (!nums.size()) {return 0;}
        sort(nums.begin(), nums.end());
        int ret = 1;
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i-1])
            {
                if(!i || nums[i] == nums[i-1]+1)
                {
                    cnt++;
                }
                else
                {
                    ret = max(ret, cnt);
                    cnt = 1;
                }
            }
        }
        
        return max(ret, cnt);
    }
};