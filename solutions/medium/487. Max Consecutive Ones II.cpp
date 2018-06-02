/* 
 * Problem: 487. Max Consecutive Ones II [medium]
 * Source : https://leetcode.com/problems/max-consecutive-ones-ii/description/
 * Solver : Baur Krykpayev
 * Date   : 6/1/2018
 */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int final = 0, prev = 0, cur = 0;
        int found = false;
        
        for (int b : nums)
        {
            if (!b)
            {   found = true;
                final = max(final, cur+prev+1);
                prev = cur;
                cur = 0;
            }
            else
            {
                cur++;
            }
        }
        
        final = (found) ? max(final, cur+prev+1) :cur;
        
        return final;
    }
};