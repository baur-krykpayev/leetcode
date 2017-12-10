/* 
 * Problem: 228. Summary Ranges[medium]
 * Source : https://leetcode.com/problems/summary-ranges/description/
 * Solver : Baur Krykpayev
 * Date   : 12/09/2017
 */
 
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<string> ret;
        int start, end;
        bool newRound = true;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (newRound)
            {
                start = nums[i];
                newRound = false;
            }
            
            end = nums[i];
            
            if (nums[i]+1 != nums[i+1])
            {
                ret.push_back((start == end) ? to_string(start) : to_string(start) + "->" + to_string(end));
                newRound = true;
            }   
        }
                
        return ret;
    }
};