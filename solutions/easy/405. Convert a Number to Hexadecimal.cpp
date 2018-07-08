/* 
 * Problem: 405. Convert a Number to Hexadecimal [easy]
 * Source : https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/
 * Solver : Baur Krykpayev
 * Date   : 07/08/2018
 */
 
class Solution {
public:
    string toHex(int num) 
    {
        if (!num) {return "0";}
        
        string ans;
        
        while (num)
        {
            int halfword = num & 15;
            ans += convertToHex(halfword);
            num >>= 4;
            num &= ~(0xF << 28);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

private:
    char convertToHex(int n)
    {
        if (n == 10){return 'a';}
        else if (n == 11){return 'b';}
        else if (n == 12){return 'c';}
        else if (n == 13){return 'd';}
        else if (n == 14){return 'e';}
        else if (n == 15){return 'f';}
        return n + '0';
    }
};