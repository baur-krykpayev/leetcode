/* 
 * Problem: 238. Product of Array Except Self [medium]
 * Source : https://leetcode.com/problems/product-of-array-except-self/description/
 * Solver : Baur Krykpayev
 * Date   : 2/20/2018
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> ret(nums.size(), 1);
        
        for (int i = 1; i < nums.size(); i++)
        {
            ret[i] = ret[i-1]*nums[i-1];
        }
        
        int temp = 1;
        for (int i = nums.size()-1; i > 0; i--)
        {
            temp *= nums[i]; 
            ret[i-1] *= temp;
        }
        
        return ret;
    }
};