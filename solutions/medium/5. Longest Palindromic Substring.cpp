/* 
 * Problem: 5. Longest Palindromic Substring[medium]
 * Source : https://leetcode.com/problems/longest-palindromic-substring/description/
 * Solver : Baur Krykpayev
 * Date   : 12/12/2017
 */
 
class Solution {
public:
    string longestPalindrome(string s) 
    {
        int start = 0;
        int end = 0;
        int len = 0;
        
        // odd
        for (int c = 0; c < s.length(); c++ )
        {
            int left = c;
            int right = c;
            
            while (0 <= left && right <= s.length()-1 )
            { 
                if (s[left] == s[right] && len < (right - left))
                {
                    len = right - left;
                    start = left;
                    end = right; 
                }
                else if (s[left] != s[right])
                {
                    break;
                }
                
                left--;
                right++;
            } 
        }
        
        // even
        for (int c = 1; c < s.length(); c++ )
        {
            int left = c-1;
            int right = c;
            
            while (0 <= left && right <= s.length()-1 )
            { 
                if (s[left] == s[right] && len < (right - left))
                {
                    len = right - left;
                    start = left;
                    end = right; 
                }
                else if (s[left] != s[right])
                {
                    break;
                }
                
                left--;
                right++;
            } 
        }
                
        string ret;
        for (int i = start; i < end + 1; i++)
        {
            ret += s[i];
        }
        return ret;
    }
};