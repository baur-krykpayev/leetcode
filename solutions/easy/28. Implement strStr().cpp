/* 
 * Problem: 28. Implement strStr() [easy]
 * Source : https://leetcode.com/problems/implement-strstr/description/
 * Solver : Baur Krykpayev
 * Date   : 4/7/2018
 */

class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int ret = -1;   
        if (haystack.length() < needle.length())
        {
            return ret;
        }
        
        if (haystack.length() == needle.length())
        {
            return (haystack == needle) ? 0 : -1;
        }
        
        for (int i = 0; i < haystack.length() - needle.length()+1; i++)
        {
            if (haystack.substr(i, needle.length()) == needle)
            {
                return i;
            }  
        }
        
        return ret;
    }
};