/* 
 * Problem: 540. Single Element in a Sorted Array[medium]
 * Source : https://leetcode.com/problems/single-element-in-a-sorted-array/description/
 * Solver : Baur Krykpayev
 * Date   : 12/18/2017
 */

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int l = 0;
        int r = nums.size()-1;
        int mid;
        
        while (l != r-1 && l != r)
        {
            mid = l + (r-l)/2;
            
            if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
            {
                return nums[mid];
            }
            
            if (mid%2)
            {
                if (nums[mid] == nums[mid-1]) {l = mid+1;}
                else{r = mid-1;}
            }
            else
            {
                if (nums[mid] == nums[mid-1]) {r = mid;}
                else{l = mid;}
            }
        }
        
        return nums[r];
    }
};