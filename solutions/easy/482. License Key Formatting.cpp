/* 
 * Problem: 482. License Key Formatting [easy]
 * Source : https://leetcode.com/problems/license-key-formatting/description/
 * Solver : Baur Krykpayev
 * Date   : 06/21/2018
 */
 
class Solution {
public:
    string licenseKeyFormatting(string S, int K) 
    {
        string ret;

        for (int i = S.length()-1; i >= 0; i--)
        {
            if (S[i] != '-')
            {
                if (ret.length()%(K+1) == K)
                {
                     ret += '-';
                }
                
                ret += toupper(S[i]);
            }
        }
        
        reverse(ret.begin(), ret.end());
        
        return ret;
    }
};