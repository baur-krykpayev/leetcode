/* 
 * Problem: 485. Max Consecutive Ones [easy]
 * Source : https://leetcode.com/problems/max-consecutive-ones/description/
 * Solver : Baur Krykpayev
 * Date   : 5/14/2018
 */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int cnt = 0;
        int temp = 0;
        for (int n : nums)
        {
            if (!n)
            {
                cnt = max(cnt, temp);
                temp = 0;
            }
            else
            {
                temp++;
            }
        }
        
        return max(cnt,temp);
    }
};