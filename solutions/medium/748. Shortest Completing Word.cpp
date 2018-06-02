/* 
 * Problem: 748. Shortest Completing Word [medium]
 * Source : https://leetcode.com/problems/shortest-completing-word/description/
 * Solver : Baur Krykpayev
 * Date   : 6/2/2018
 */

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) 
    {
        string match, ret;
        
        for (char c : licensePlate)
        {
            char l = tolower(c);
            if ( 'a' <= l && l <= 'z')
            {
                match += l;
            } 
        }
        
        for (int i = 0; i < words.size(); i++)
        {
            unordered_map<char, int> m;
            int found = true;
            
            for (auto c : words[i])
            {
                m[c]++;
            }
        
            for (auto c : match)
            {
                if (m.find(c) == m.end() || !m[c])
                {
                    found = false;
                    break;
                }
                else
                {
                    m[c]--;
                }
            }
            
            if (found && (!ret.size() || words[i].size() < ret.size()))
            {
                ret = words[i];
            }
        }
        
        return ret;
    }
};