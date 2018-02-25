/* 
 * Problem: 152. Maximum Product Subarray[medium]
 * Source : https://leetcode.com/problems/maximum-product-subarray/description/
 * Solver : Baur Krykpayev
 * Date   : 2/25/2018
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int ret = INT_MIN;
        int front = 1;
        int back  = 1;
        
        for (int i = 0; i < nums.size(); i++)
        {
            front *= nums[i] ;
            back *= nums[nums.size() - 1 -i];
            ret = max(ret, max(front, back));
            if (!front) {front = 1;}
            if (!back) {back = 1;}
        }
        
        return ret;
    }
};