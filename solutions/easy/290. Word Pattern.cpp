/* 
 * Problem: 290. Word Pattern [easy]
 * Source : https://leetcode.com/problems/word-pattern/description/
 * Solver : Baur Krykpayev
 * Date   : 07/29/2018
 */

class Solution {
public:
    bool wordPattern(string pattern, string str) 
    {
        unordered_map<char, string> hash;
        unordered_map<string, char> rev;
        str += " ";
        int i = 0;
        
        for (char c : pattern)
        {    
            string word = nextWord(str, i);
            if (word == ""){return false;}
            i += (word.length()+1);
            
            if (hash.find(c) == hash.end() && 
                rev.find(word) == rev.end())
            {
                hash[c] = word;
                rev[word] = c;
            }
            else
            {
                if (hash[c] != word || rev[word] != c)
                {
                    return false;
                }
            }
        }
        
        //case where string is greater than pattern
        if (i < str.length()){return false;}
        
        return true;
    }
    
private:
    string nextWord(string str, int start)
    {
        string word = "";
        int cur = start;
        while (str[cur] != ' '){cur++;}
        word = str.substr(start, cur-start);
        return word;   
    }
};