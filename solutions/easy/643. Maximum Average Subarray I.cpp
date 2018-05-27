/* 
 * Problem: 643. Maximum Average Subarray I [easy]
 * Source : https://leetcode.com/problems/maximum-average-subarray-i/description/
 * Solver : Baur Krykpayev
 * Date   : 5/27/2018
 */

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        int sum = 0;
        int m = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if ( i >= k)
            {
                m = max(m, sum);
                sum -= nums[i-k];       
            }
            sum += nums[i];
        }
        
        return (double)max(m, sum)/k;
    }
};