/* 
 * Problem: 537. Complex Number Multiplication[medium]
 * Source : https://leetcode.com/problems/complex-number-multiplication/description/
 * Solver : Baur Krykpayev
 * Date   : 11/22/2017
 */
 
class Solution {
public:
    string complexNumberMultiply(string x, string y) 
    {
        pair<int, int> a = iNeedToLearCppStringParsing(x);
        pair<int, int> b = iNeedToLearCppStringParsing(y);
        string ret;
            
        ret.append(to_string(a.first*b.first-a.second*b.second));
        ret.append("+");
        ret.append(to_string(a.second*b.first+a.first*b.second));
        ret.append("i");
            
        return ret;
    }
private:
    pair<int,int> iNeedToLearCppStringParsing(string str)
    {
        pair<int,int> ret;
        string temp;
        int i = 0;
        
        while(str.at(i) != '+')
        {
            temp += str.at(i);
            i++;
        }
        
        stringstream firstStr(temp);
        firstStr >> ret.first;
                
        temp.clear();
        i++;
      
        while(str.at(i) != 'i')
        {
            temp += str.at(i);
            i++;
        }
        stringstream secondStr(temp);
        
        secondStr >> ret.second;
       
        return ret;
    }
    
};