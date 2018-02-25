/* 
 * Problem: 150. Evaluate Reverse Polish Notation[medium]
 * Source : https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 * Solver : Baur Krykpayev
 * Date   : 2/25/2018
 */

class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<string> stk;

        for (int i = 0; i < tokens.size(); i++)
        {
            int a;
            int b;
            
            if (tokens[i] == "+")
            {
                a = stoi(stk.top());
                stk.pop();
                b = stoi(stk.top());
                stk.pop(); 
                stk.push(to_string(a+b));
            }
            else if (tokens[i] == "-")
            {
                a = stoi(stk.top());
                stk.pop();
                b = stoi(stk.top());
                stk.pop();
                stk.push(to_string(b-a));
            }
            else if (tokens[i] == "*")
            {
                a = stoi(stk.top());
                stk.pop();
                b = stoi(stk.top());
                stk.pop();
                stk.push(to_string(a*b));
            }
            else if (tokens[i] == "/")
            {
                a = stoi(stk.top());
                stk.pop();
                b = stoi(stk.top());
                stk.pop();
                stk.push(to_string(b/a));
            }
            else
            {
                stk.push(tokens[i]);
            }         
        }
        
        return stoi(stk.top());
    }
};