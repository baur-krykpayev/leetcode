/* 
 * Problem: 213. House Robber II[medium]
 * Source : https://leetcode.com/problems/house-robber-ii/description/
 * Solver : Baur Krykpayev
 * Date   : 3/5/2018
 */

class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if (!nums.size()) {return 0;}
        if (nums.size() == 1) {return nums[0];}
        
        int max_prev = 0;
        int max_cur_one = 0;

        for (int i = 0; i < nums.size()-1; i++)
        {
            int temp = max_cur_one;
            max_cur_one = max(temp, max_prev+nums[i]);
            max_prev = temp;
        }
        
        max_prev = 0;
        int max_cur_two = 0;
        
        for (int i = 1; i < nums.size(); i++)
        {
            int temp = max_cur_two;
            max_cur_two = max(temp, max_prev+nums[i]);
            max_prev = temp;
        }
        
        return max(max_cur_one, max_cur_two);
    }
};