/* 
 * Problem: 75. Sort Colors [medium]
 * Source : https://leetcode.com/problems/sort-colors/description/
 * Solver : Baur Krykpayev
 * Date   : 06/21/2018
 */
 
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int l = 0, m = 0, r = nums.size()-1;
        
        while (m <= r)
        {
            if (nums[m] == 1) {m++;}
            else if (nums[m] == 0) 
            {
                swap(nums[m++], nums[l++]);
            }
            else
            {
                swap(nums[m], nums[r--]);
            }
        }
    }
};