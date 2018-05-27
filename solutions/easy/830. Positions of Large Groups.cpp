/* 
 * Problem: 830. Positions of Large Groups [easy]
 * Source : https://leetcode.com/problems/positions-of-large-groups/description/
 * Solver : Baur Krykpayev
 * Date   : 5/26/2018
 */

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) 
    {
        vector<vector<int>> ret;
        if (S.length() == 0) {return ret;}
        int start = 0;
        int end = 0;
        
        while (end < S.length())
        {
            if (S[start] == S[end])
            {
                end++;
            }
            else
            {
                if (end - start >= 3)
                {
                    ret.push_back({start, end-1});
                }
                start = end;
            }
        }
        
        if (end - start >= 3)
        {
            ret.push_back({start, end-1});
        }
        
        return ret;
    }
};