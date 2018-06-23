/* 
 * Problem: 163. Missing Ranges [medium]
 * Source : https://leetcode.com/problems/missing-ranges/description/
 * Solver : Baur Krykpayev
 * Date   : 06/22/2018
 */
 
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) 
    {
        vector<string> ret;

        for (int n : nums)
        {
            if (n == INT_MIN)
            {
                lower = n+1;
                continue;
            }
            
            if (lower < n-1)
            {
                ret.push_back(to_string(lower) + "->" + to_string(n-1));
            }
            else if (lower == n-1)
            {
                ret.push_back(to_string(lower));
            }
            
            if (n == INT_MAX) {return ret;}
            
            lower = n + 1;
        }
        
        if (lower < upper)
        {
            ret.push_back(to_string(lower) + "->" + to_string(upper));
        }
        else if (lower == upper)
        {
            ret.push_back(to_string(lower));
        }
        
        return ret;
    }
};