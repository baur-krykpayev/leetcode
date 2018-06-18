/* 
 * Problem: 224. Basic Calculator [hard]
 * Source : https://leetcode.com/problems/basic-calculator/description/
 * Solver : Baur Krykpayev
 * Date   : 06/18/2018
 */
 
class Solution {
public:
    int calculate(string s) 
    {
        stack <int> stk;
        int cur = 0, sign = 1, ret = 0;
        
        for (char c : s) 
        { 
            if (c == ' ') {continue;}
            else if (isdigit(c)) 
            {
                cur = cur * 10 + c - '0';
            }
            else 
            {
                ret += sign * cur;
                cur = 0;
                
                if (c == '+') {sign = 1;}
                else if (c == '-') {sign = -1;}
                else if (c == '(') 
                {
                    stk.push(ret);
                    stk.push(sign);
                    ret = 0;
                    sign = 1;
                }
                else
                {
                    int op = stk.top(); stk.pop();
                    ret =  op* ret + stk.top();
                    stk.pop(); 
                }
            }
        }
        
        return ret + sign*cur;
    }
};