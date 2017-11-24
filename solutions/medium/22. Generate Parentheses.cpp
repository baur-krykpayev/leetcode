/* 
 * Problem: 22. Generate Parentheses[medium]
 * Source : https://leetcode.com/problems/generate-parentheses/description/
 * Solver : Baur Krykpayev
 * Date   : 11/24/2017
 */
 
class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ret;
        stack<char> s;
        helper(2*n, "", ret, s);
        
        return ret;
    }
private:
    void helper(int n, string prefix, vector<string> &ret, stack<char> &s)
    {
        if (n == 0)
        {
            if (s.empty())
            {
                ret.push_back(prefix);    
            }
        }
        else
        {    
            s.push('(');
            helper(n-1, prefix + '(', ret, s);
            s.pop();
            
            bool popped = false;
            if (!s.empty())
            {
                if (s.top() == '(')
                {
                    s.pop();
                    popped = true;    
                }
                else
                {
                    s.push('(');
                }

                helper(n-1, prefix + ')', ret, s);

                if (popped)
                {
                    s.push('(');
                }
                else
                {
                    s.pop();
                }   
            }
        }   
    }
};