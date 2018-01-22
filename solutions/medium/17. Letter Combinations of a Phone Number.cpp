/* 
 * Problem: 17. Letter Combinations of a Phone Number[medium]
 * Source : https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 * Solver : Baur Krykpayev
 * Date   : 1/22/2018
 */
 
class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        vector <string> ret;
        if (digits == ""){return ret;}
        string letters;
        string temp; 
        helper(temp, 0, ret, digits);
        return ret;
    }
    
private:
    string numToStr(char i)
    {
        string letters;
        
        switch (i)
        {
            case '2':
            {
                letters = "abc";
                break;
            }    

            case '3':
            {
                letters = "def";
                break;
            }    

            case '4':
            {
                letters = "ghi";
                break;
            }    

            case '5':
            {
                letters = "jkl";
                break;
            }    

            case '6':
            {
                letters = "mno";
                break;
            }    

            case '7':
            {
                letters = "pqrs";
                break;
            }    

            case '8':
            {
                letters = "tuv";
                break;
            }    

            case '9':
            {
                letters = "wxyz";
                break;
            }    
            default:
            {
                break;    
            }
        }
        
        return letters;
    }
        
    void helper(string &temp, int ind, vector<string> &ret, string digits)
    {
        if (temp.length() == digits.length())
        {
            ret.push_back(temp);
        }
        else
        {
            string letters = numToStr(digits.at(ind));
            for (int i = 0; i < letters.length(); i++)
            {
                temp += letters[i];
                helper(temp, ind + 1, ret, digits);
                temp.pop_back();
            }   
        }
    }
};