/* 
 * Problem: 81. Search in Rotated Sorted Array II [medium]
 * Source : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
 * Solver : Baur Krykpayev
 * Date   : 06/16/2018
 */
 
class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
        int l = 0;
        int r = nums.size()-1;
        int m = 0;
        
        while (l <= r)
        {
            m = l + (r-l)/2;
            
            if (nums[m] == target || nums[l] == target || nums[r] == target) {return true;}
            if (nums[m] == nums[l] && nums[m] == nums[r]) {l++; r--;}
            else if (nums[l] <= nums[m])
            {
                if (nums[l] < target && target < nums[m])
                {
                    r = m-1;
                }
                else {l = m+1;}
            }
            else
            {
                if (nums[m] < target && target < nums[r])
                {
                    l = m+1;
                }
                else {r = m-1;}
            }
        }
        
        return false;
    }
};