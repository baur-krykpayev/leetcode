/* 
 * Problem: 162. Find Peak Element[medium]
 * Source : https://leetcode.com/problems/find-peak-element/description/
 * Solver : Baur Krykpayev
 * Date   : 12/08/2017
 */
 
class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int l = 0;
        int r = nums.size() - 1 ;
        int mid;
        
        while (l < r)
        {
            mid = l + (r - l)/2;
            
            if (nums[mid] > nums[mid + 1])
            {
                r = mid;
            }
            else if (nums[mid] < nums[mid + 1])
            {
                l = mid + 1;
            }
        }
        
        return l;
    }
};