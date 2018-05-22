/* 
 * Problem: 821. Shortest Distance to a Character [easy]
 * Source : https://leetcode.com/problems/shortest-distance-to-a-character/description/
 * Solver : Baur Krykpayev
 * Date   : 5/22/2018
 */

class Solution {
public:
    vector<int> shortestToChar(string S, char C) 
    {
        vector<int> ret;
        vector<int> cIndex; 
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] == C)
            {
                cIndex.push_back(i);
            }
        }
        
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] == C)
            {
                ret.push_back(0);
            }
            else
            {
                int m = INT_MAX;
                for (int ind : cIndex)
                {
                    m = min(m, abs(ind-i));
                }
                ret.push_back(m);
            }
        }
        
        return ret;
    }
};