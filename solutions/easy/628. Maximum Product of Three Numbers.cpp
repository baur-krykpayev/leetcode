/* 
 * Problem: 628. Maximum Product of Three Numbers [easy]
 * Source : https://leetcode.com/problems/maximum-product-of-three-numbers/description/
 * Solver : Baur Krykpayev
 * Date   : 06/28/2018
 */
 
class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int first = nums[0] * nums[1] * nums[n-1] ;
        int last  = nums[n-1] * nums[n-2] * nums[n-3];    
        return max(first, last);
    }
};