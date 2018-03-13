/* 
 * Problem: 76. Minimum Window Substring [medium]
 * Source : https://leetcode.com/problems/minimum-window-substring/description/
 * Solver : Baur Krykpayev
 * Date   : 3/12/2018
 */

class Solution {
public:
    string minWindow(string s, string t) 
    {
        string ret;
        if (t.length() > s.length()){return ret;}
        
        unordered_map<char, int> map;
        for (char c : t){map[c]++;}
        int start = 0, end = 0, counter = map.size();
        int min_len = INT_MAX;
        
        while (end < s.length())
        {
            char c = s[end];
            
            if (map.find(c) != map.end())
            {
                map[c]--;
                if (!map[c]) {counter--;}
            }
            end++;
            
            while (!counter)
            {
                char ch = s[start];
                if (map.find(ch) != map.end())
                {
                    map[ch]++;
                    if (map[ch] > 0){counter++;}
                    if ((end - start) < min_len)
                    {
                        min_len = end - start;
                        ret = s.substr(start, min_len);
                    }
                }
                start++;
            }
        }
        
        return ret;
    }
};