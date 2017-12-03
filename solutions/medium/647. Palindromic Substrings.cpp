/* 
 * Problem: 647. Palindromic Substrings[medium]
 * Source : https://leetcode.com/problems/palindromic-substrings/description/
 * Solver : Baur Krykpayev
 * Date   : 12/03/2017
 */
 
class Solution {
public:
    int countSubstrings(string s) 
    {
        int count = 0;
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
                
        for (int j = 0; j < s.length(); j++) 
        {    
            for (int i = 0; i < s.length() - j; i++) 
            {    
                if ((j < 3 || dp[i + 1][i + j - 1]) && s[i] == s[i+j])
                {
                    dp[i][i+j] = true;
                    count++;
                }
            }
        }  
        return count;
    }
};