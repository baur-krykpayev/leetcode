/* 
 * Problem: 320. Generalized Abbreviation [medium]
 * Source : https://leetcode.com/problems/generalized-abbreviation/description/
 * Solver : Baur Krykpayev
 * Date   : 6/3/2018
 */

class Solution {
public:
    vector<string> generateAbbreviations(string word) 
    {
        vector<string> ret;
        string temp;
        backtrack(0, 0, temp, word, ret);
        return ret;
    }
    
private:
    void backtrack(int i, int k, string& temp, string word, vector<string>& ret)
    {
        int l = temp.length();
        
        if (i == word.length())
        {
            if (k){temp += to_string(k);}
            ret.push_back(temp);
        }    
        else
        {
            backtrack(i+1, k+1, temp, word, ret);

            if (k){temp += to_string(k);}
            temp += word[i];
            backtrack(i+1, 0, temp, word, ret); 
        }
        
        while (temp.size() != l)
        {
            temp.erase(temp.end()-1);            
        }
    }
};