/* 
 * Problem: 819. Most Common Word [easy]
 * Source : https://leetcode.com/problems/most-common-word/description/
 * Solver : Baur Krykpayev
 * Date   : 07/02/2018
 */
 
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) 
    {
        unordered_set<string> ban;
        unordered_map<string, int> freq;
        for (auto word : banned){ban.insert(word);}
        
        string temp;
        int m_freq = 0;
        string ans;
        paragraph += ' ';
        for (char c : paragraph)
        {
            if (isalpha(c))
            {
                temp += tolower(c);
            }
            else if (c == ' ')
            {
                if (!ban.count(temp))
                {
                    freq[temp]++;
                    if (freq[temp] > m_freq)
                    {
                        m_freq = freq[temp];
                        ans = temp;
                    }
                }
                
                temp.clear();
            }
        }
        
        return ans;
    }
};