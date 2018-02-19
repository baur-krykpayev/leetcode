/* 
 * Problem: 451. Sort Characters By Frequency[medium]
 * Source : https://leetcode.com/problems/sort-characters-by-frequency/discuss/93404/C++-O(n)-solution-without-sort()
 * Solver : Baur Krykpayev
 * Date   : 2/18/2018
 */

class Solution {
public:
    string frequencySort(string s) 
    {
        string ret;
        unordered_map<int, int> ascii;
        
        for (int i = 0; i < s.length(); i++)
        {
         
            if (ascii.find(s.at(i)) != ascii.end())
            {
                ascii[s.at(i)] += 1;     
            }
            else
            {
                ascii[s.at(i)] = 1;     
            }
        }
        
        vector<pair<int,int>> temp(ascii.begin(), ascii.end());
        sort(temp.begin(), temp.end(), [](auto &left, auto &right){return left.second > right.second;});
        
        for (int i = 0; i < temp.size(); i++)
        {
            for (int k = 0; k < temp[i].second; k++)
            {
                ret += temp[i].first;    
            }
        }
        
        return ret;
    }
};