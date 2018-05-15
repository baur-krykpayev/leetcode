/* 
 * Problem: 415. Add Strings [easy]
 * Source : https://leetcode.com/problems/add-strings/description/
 * Solver : Baur Krykpayev
 * Date   : 5/15/2018
 */

class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
    
        int c = 0;
        string lng;
        string shrt;
        if (num1.length() > num2.length())
        {
            lng = num1;
            shrt = num2;
        }
        else
        {
            lng = num2;
            shrt = num1;
        }
        int i;
        string result;
        
        for (i = 0; i < lng.length(); i++)
        {
            int l = lng[i] - '0';
            int r = 0;
            if (i < shrt.length())
            {
                r = shrt[i] - '0';    
            }
            int s = l+r+c;
            result += (s%10+'0');
            c = s/10; 
        }
        if (c){result += (c+'0');}
        
        reverse(result.begin(), result.end());
        return result;
    }
};