/* 
 * Problem: 33. Search in Rotated Sorted Array [medium]
 * Source : https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 * Solver : Baur Krykpayev
 * Date   : 06/15/2018
 */
 
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int l = 0;
        int r = nums.size()-1;
    
        while(l < r)
        {
            int mid = l + (r-l)/2;
            if (nums[r] < nums[mid])
            {
                l = mid+1;
            }
            else
            {
                r = mid;
            }
        }
        
        int shift = l;
        l = 0; r = nums.size()-1;
        
        while (l <= r)
        {
            int mid = (l + (r-l)/2); 
            int ind = (mid+shift) % nums.size();
            if (nums[ind] == target){return ind;}
            else if (nums[ind] < target)
            {
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        
        return -1;
    }
};