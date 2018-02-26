/* 
 * Problem: 187. Repeated DNA Sequences[medium]
 * Source : https://leetcode.com/problems/repeated-dna-sequences/description/
 * Solver : Baur Krykpayev
 * Date   : 2/26/2018
 */

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        unordered_map<string, int> map;
        vector<string> ret;
        
        if (s.length() < 10) {return ret;}
        
        for (int i = 0; i <= s.length() - 10; i++)
        {
            string temp = s.substr(i,10);
            
            if (map.find(temp) == map.end())
            {
                map[temp] = i;
            }
            else
            {
                if (map[temp] >= 0)
                {
                    if (!temp.compare(s.substr(map[temp],10)))
                    {
                        ret.push_back(temp);    
                        map[temp] = INT_MIN;
                    }
                }       
            }
        }
        
        return ret;
    }
};