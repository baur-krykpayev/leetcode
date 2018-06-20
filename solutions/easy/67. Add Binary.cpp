/* 
 * Problem: 67. Add Binary [easy]
 * Source : https://leetcode.com/problems/add-binary/description/
 * Solver : Baur Krykpayev
 * Date   : 06/19/2018
 */
 
class Solution {
public:
    string addBinary(string a, string b) 
    {
        if (a.length() < b.length())
        {
            return addBinary(b,a);
        }
        string ret;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i = 0;
        int c = 0;
        while (i < a.length())
        {
            int x = (a[i] == '1') ? 1 : 0;
            int y = 0;
            
            if (i < b.length() && b[i] == '1')
            {
                y = 1;
            }
            
            int temp = x + y + c;
            ret += to_string(temp%2);
            c = temp/2;
            i++;
        }
    
        if(c)
        {
            ret += to_string(c);
        }
        
        reverse(ret.begin(), ret.end());
        return ret;
    }
};