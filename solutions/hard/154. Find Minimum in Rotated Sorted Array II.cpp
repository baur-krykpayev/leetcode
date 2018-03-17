/* 
 * Problem: 154. Find Minimum in Rotated Sorted Array II[medium]
 * Source : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 * Solver : Baur Krykpayev
 * Date   : 3/16/2018
 */

class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        if (nums.size() < 2){nums[0];}
        
        int left = 0;
        int right  = nums.size()-1;
        
        while (left < right)
        {
            if (nums[left] < nums[right])
            {
                return nums[left];
            }
            
            int mid = left + (right-left)/2;
            
            if (nums[mid] > nums[right])
            {
                left =  mid + 1;
            }
            else if (nums[mid] < nums[right])
            {
                right = mid;
            }
            else
            {
                right--;
            }
        }
        
        return nums[left];
    }
};