/* 
 * Problem: 724. Find Pivot Index [easy]
 * Source : https://leetcode.com/problems/find-pivot-index/description/
 * Solver : Baur Krykpayev
 * Date   : 07/27/2018
 */

int pivotIndex(int* nums, int numsSize) 
{
    if (numsSize < 2) {return -1;}
    
    int total = 0;
    
    for (int i = 0; i < numsSize; i++)
    {
        total += *(nums+i);
    }
    
    int cur_sum = 0;
    
    for (int i = 0; i < numsSize; i++)
    {
        if (cur_sum == total - cur_sum - nums[i])
        {
            return i;
        }
        cur_sum += nums[i];
    }
    
    return -1;
}