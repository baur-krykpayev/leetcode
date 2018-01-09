/* 
 * Problem: 442. Find All Duplicates in an Array[medium]
 * Source : https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
 * Solver : Baur Krykpayev
 * Date   : 12/18/2017
 */

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        vector<int> ret;
        if (!nums.size()) {return ret;}

        for (int i = 0; i < nums.size(); i++)
        {
            int pos = abs(nums[i]) - 1;
            if (nums[pos] > 0)
            {
                nums[pos] -= 2*nums[pos];
            }
            else
            {
                ret.push_back(abs(nums[i]));
            }
        }
        
        return ret;
    }
};