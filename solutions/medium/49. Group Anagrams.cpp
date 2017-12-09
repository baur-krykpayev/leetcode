/* 
 * Problem: 49. Group Anagrams[medium]
 * Source : https://leetcode.com/problems/group-anagrams/description/
 * Solver : Baur Krykpayev
 * Date   : 12/09/2017
 */
 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> ret;
        unordered_map<string, int> hash;
            
        for (auto str: strs)
        {
            string strTemp = str;
            sort(strTemp.begin(), strTemp.end());
    
            if (hash.find(strTemp) == hash.end())
            {
                vector<string> temp{str};
                ret.push_back(temp);
                hash.insert(make_pair(strTemp,ret.size()-1));
            }
            else
            {
                ret[hash.find(strTemp)->second].push_back(str); 
            }
        }
        
        return ret;
    }
};