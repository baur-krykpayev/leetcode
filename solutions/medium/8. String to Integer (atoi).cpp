/* 
 * Problem: 8. String to Integer (atoi) [medium]
 * Source : https://leetcode.com/problems/string-to-integer-atoi/description/
 * Solver : Baur Krykpayev
 * Date   : 5/24/2018
 */

class Solution {
public:
    int myAtoi(string str) 
    {
        int i = 0;
        while(str[i] == ' '){i++;}
        bool neg = false;
        if (str[i] == '-'){neg = true; i++;}
        else if (str[i] == '+'){neg = false; i++;}
        else if (str[i] < '0' || str[i] > '9') {return 0;}
        
        int n = 0;
        while (i < str.length() && str[i] >= '0' && str[i] <= '9' )
        {
            if ((n > INT_MAX/10) || (n == INT_MAX/10 && (str[i] - '0') >7))
            {
                if (neg){return INT_MIN;}
                else{return INT_MAX;}
            }
            n = n*10 +(str[i] - '0');
            i++;
        }
        
        return (neg) ? -1*n : n;
    }
};