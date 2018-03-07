/* 
 * Problem: 91. Decode Ways [medium]
 * Source : https://leetcode.com/problems/decode-ways/description/
 * Solver : Baur Krykpayev
 * Date   : 3/7/2018
 */

class Solution {
public:
    int numDecodings(string s) 
    {
        if (!s.length()) {return 0;}
        vector<int> dp(s.length()+1, 0);
        
        dp[0] = 1;
        dp[1] = (s[0] == '0') ? 0 : 1;
        
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == '0') {dp[i] = 0;}
            
            if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))
            {
                dp[i+1] = dp[i] + dp[i-1]; 
            }
            else
            {
                dp[i+1] = dp[i];
            }
        }
        
        return dp[s.length()];
    }
};