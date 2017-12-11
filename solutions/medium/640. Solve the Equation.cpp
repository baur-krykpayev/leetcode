/* 
 * Problem: 640. Solve the Equation[medium]
 * Source : https://leetcode.com/problems/solve-the-equation/description/
 * Solver : Baur Krykpayev
 * Date   : 12/11/2017
 */
 
class Solution {
public:

    string solveEquation(string equation) 
    {
        string temp = "";
        
        for (int i = 0; i < equation.length(); i++)
        {
            if (equation.at(i) == '+' || equation.at(i) == '-' || equation.at(i) == '=')
            {
                if (temp != "") {process(temp);}
                temp = "";
            } 
            
            if (equation.at(i) != '=') 
            {
                temp += equation.at(i);
            }
            else
            {
                reverse = true;
            }
            
            if (i == equation.length()-1)
            {
                if (temp != "") {process(temp);}
            }
        }
        
        if (num == 0 && x == 0){return "Infinite solutions";}
        if (x == 0){return "No solution";}
        return "x="+ to_string((-1*num)/x);
    }
    
private:
    int num = 0;
    int x = 0;
    int reverse = false;
    
    void process(string temp)
    {
        if (temp.back() == 'x')
        {
            temp.erase(temp.begin() + temp.length()-1);

            if (temp == "" || temp == "-" || temp == "+")
            {
                temp += "1";
            }
            
            x = (!reverse) ? x + stoi(temp) : x - stoi(temp);    
        }
        else
        {   
            num = (!reverse) ? num + stoi(temp) : num - stoi(temp);
        }
    }
};