/* 
 * Problem: 788. Rotated Digits [easy]
 * Source : https://leetcode.com/problems/rotated-digits/description/
 * Solver : Baur Krykpayev
 * Date   : 07/19/2018
 */
 
class Solution {
public:
    int rotatedDigits(int N) 
    {
        int ans = 0;
        for (int num = 0 ; num <= N; num++)
        {
            int rot = rotate(num);
            if (rot != -1 && rot != num)
            {
                ans++;
            }
        }
        
        return ans;
    }

private:
    int rotate(int num)
    {
        string s = to_string(num);
        string ans;
        
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            
            if(c == '3' || c ==  '4' || c == '7')
            {
                return -1;
            } 
            else if (c == '2')
            {
                ans += '5';
            }
            else if (c == '5')
            {
                ans += '2';
            }
            else if (c == '6')
            {
                ans += '9';
            }
            else if (c == '9')
            {
                ans += '6';
            }
            else
            {
                ans += c;
            }
        }
        
        return stoi(ans);
    }
};