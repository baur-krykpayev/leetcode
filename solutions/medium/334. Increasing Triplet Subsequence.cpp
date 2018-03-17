/* 
 * Problem: 334. Increasing Triplet Subsequence[medium]
 * Source : https://leetcode.com/problems/increasing-triplet-subsequence/description/
 * Solver : Baur Krykpayev
 * Date   : 3/17/2018
 */

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        int a = INT_MAX;
        int b = INT_MAX;
        
        for (int num : nums)
        {
            if (num <= a)
            {
                a = num;
            }
            else if (num <= b)
            {
                b = num;
            }
            else
            {
                return true;
            }
            
        }
        
        return false;
    }
};