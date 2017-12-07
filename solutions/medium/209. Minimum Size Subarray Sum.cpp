/* 
 * Problem: 209. Minimum Size Subarray Sum[medium]
 * Source : https://leetcode.com/problems/minimum-size-subarray-sum/description/
 * Solver : Baur Krykpayev
 * Date   : 12/07/2017
 */
 
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        int start = 0;
        int sum = 0;
        int dif = INT_MAX;
    
        for ( int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            while (sum >= s)
            {              
                dif = (dif > i-start) ? i-start : dif;
                sum -= nums[start];
                start++;
            }
        } 
        
        return (dif == INT_MAX) ? 0 : dif+1;     
    }
};