/* 
 * Problem: 520. Detect Capital [easy]
 * Source : https://leetcode.com/problems/detect-capital/description/
 * Solver : Baur Krykpayev
 * Date   : 5/14/2018
 */

class Solution {
public:
    bool detectCapitalUse(string word) 
    {
        int cnt = 0;
        for (char c : word)
        {
            if (isupper(c)){cnt++;}
        }
        
        if (!cnt || cnt == word.length() || (cnt==1 && word.length()>1 && isupper(word[0]))){return true;}
        
        return false;
    }
};