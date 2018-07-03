/* 
 * Problem: 648. Replace Words [medium]
 * Source : https://leetcode.com/problems/replace-words/description/
 * Solver : Baur Krykpayev
 * Date   : 07/02/2018
 */
 
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) 
    {
        unordered_set<string> s;
        string ans;
        for (auto word : dict){s.insert(word);}
        sentence += ' ';
        
        string temp;
        for (int i = 0; i < sentence.length(); i++)
        {
            char c = sentence[i];
            if (c == ' ')
            {
                ans += (temp + ' ');
                temp.clear();
            }
            else
            {
                temp += c;
                if (s.count(temp))
                {
                    ans += (temp + ' ');
                    temp.clear();
                    while (sentence[i] != ' '){i++;}
                }
            }
        }
        
        ans.pop_back();
        return ans;
    }
};