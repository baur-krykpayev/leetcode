/* 
 * Problem: 844. Backspace String Compare [easy]
 * Source : https://leetcode.com/problems/backspace-string-compare/description/
 * Solver : Baur Krykpayev
 * Date   : 06/16/2018
 */
 
class Solution {
public:
    bool backspaceCompare(string S, string T) 
    {
        stack<char> stk1;
        stack<char> stk2;
        
        for (char c : S)
        {
            if (c == '#')
            {
                if(!stk1.empty()){stk1.pop();}
            }
            else{stk1.push(c);}
        }
        
        for (char c : T)
        {
            if (c == '#')
            {
                if(!stk2.empty()){stk2.pop();}
            }
            else{stk2.push(c);}
        }
        
        return stk1 == stk2;
    }
};