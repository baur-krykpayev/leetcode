/* 
 * Problem: 500. Keyboard Row [easy]
 * Source : https://leetcode.com/problems/keyboard-row/
 * Solver : Baur Krykpayev
 * Date   : 5/25/2018
 */

class Solution {
public:    
    vector<string> findWords(vector<string>& words) 
    {
        vector<string> ret;
        for (string w: words)
        {
            if (check(w))
            {
                ret.push_back(w);
            }
        }
        return ret;
    }
    
private:
        unordered_set<char> top = {'q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char> mid = {'a','s','d','f','g','h','j','k','l'};
        unordered_set<char> bot = {'z','x','c','v','b','n','m'};
        
    bool check(string w)
    {
        if (!w.length()) {return false;}
        
        unordered_set<char> s;
        if (top.find(tolower(w[0])) != top.end())
        {
            s = top;
        }
        else if (mid.find(tolower(w[0])) != mid.end())
        {
            s = mid;
        }
        else
        {
            s = bot; 
        }
        
        for (int i = 1; i < w.length(); i++)
        {
            if (s.find(tolower(w[i])) == s.end())
            {
                return false;
            }
        }
            
        return true;
    }
};