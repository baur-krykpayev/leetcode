/* 
 * Problem: 747. Largest Number At Least Twice of Others [easy]
 * Source : https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/
 * Solver : Baur Krykpayev
 * Date   : 07/25/2018
 */

int dominantIndex(int* nums, int numsSize) 
{
    int first = INT_MIN;
    int ind = -1;
    int second = INT_MIN;
    
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > first)
        {
            first = nums[i];
            ind = i;
        }
    }
    
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != first && nums[i] > second)
        {
            second = nums[i];
        }
    }
    
    return (first >= 2*second) ? ind : -1;
}