/* 
 * Problem: 35. Search Insert Position [easy]
 * Source : https://leetcode.com/problems/search-insert-position/description/
 * Solver : Baur Krykpayev
 * Date   : 07/28/2018
 */

int searchInsert(int* nums, int numsSize, int target) 
{
    int l = 0;
    int r = numsSize-1;
    
    while (l <= r)
    {
        int mid  = l + (r-l)/2;
        
        if (nums[mid] < target)
        {
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }
    
    return l;
}