/* 
 * Problem: 394. Decode String [medium]
 * Source : https://leetcode.com/problems/decode-string/description/
 * Solver : Baur Krykpayev
 * Date   : 3/11/2018
 */

class Solution {
public:
    string decodeString(string s) 
    {
        int pos = 0;
        return helper(s, pos);
    }
    
private:
    string helper(string s, int& pos)
    {
        string ret;
        
        while (pos < s.length() && s[pos] != ']')
        {
            if (!isdigit(s[pos]))
            {
                ret += s[pos++];
            }
            else
            {
                int num = 0;
                while (pos < s.length() && isdigit(s[pos]))
                {
                    num = num*10 +s[pos++] - '0';
                }
                
                pos++;
                string temp = helper(s, pos);
                pos++;
                    
                while (num-- > 0)
                {
                    ret += temp;
                }
            }  
        }
        
        return ret;
    }
};