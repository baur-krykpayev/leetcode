/* 
 * Problem: 139. Word Break[medium]
 * Source : https://leetcode.com/problems/word-break/description/
 * Solver : Baur Krykpayev
 * Date   : 02/10/2018
 */
 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> hash;
        for(auto &word : wordDict){hash.insert(word);}
        vector<bool> dp (s.size()+1, false);
        dp[0] = true;
        
        for (int i = 1; i < s.length()+1; i++)
        {
            for (int j = i-1; j>=0; j--)
            {
                if (dp[j])
                {
                    if (hash.count(s.substr(j, i-j)))
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];   
    }
};