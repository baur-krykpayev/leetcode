/* 
 * Problem: 153. Find Minimum in Rotated Sorted Array[medium]
 * Source : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 * Solver : Baur Krykpayev
 * Date   : 3/6/2018
 */

class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        if (!nums.size()) {return 0;}
        int m = nums[0];
        
        for (int i = 1; i < nums.size(); i++)
        {
            if (m > nums[i])
            {
                m = nums[i];
            }
        }
        
        return m;
    }
};