/* 
 * Problem: 32. Longest Valid Parentheses [hard]
 * Source : https://leetcode.com/problems/longest-valid-parentheses/description/
 * Solver : Baur Krykpayev
 * Date   : 07/07/2018
 */
 
class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int ans = 0;
        stack<int> stk;
        
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            
            if (ch == '(')
            {
                stk.push(i);
            }
            else
            {
                if (!stk.empty() && s[stk.top()] == '(')
                {
                    stk.pop();
                }
                else
                {
                    stk.push(i);   
                }
            }
        }
        
        stk.push(s.length());
        while (!stk.empty())
        {
            int end = stk.top(); stk.pop();
            int start = (stk.empty()) ? -1 : stk.top();
            ans = max(ans, end - start - 1);
        }
         
        return ans;
    }
};