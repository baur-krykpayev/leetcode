/* 
 * Problem: 791. Custom Sort String[medium]
 * Source : https://leetcode.com/problems/custom-sort-string/description/
 * Solver : Baur Krykpayev
 * Date   : 2/27/2018
 */

class Solution {
public:
    string customSortString(string S, string T) 
    {
        unordered_map<char, int> map;
        string ret = "";
        string temp = "";
        
        for (int i = 0; i < S.length(); i++)
        {
            map[S[i]] = 0;
        }
        
        for (int i = 0; i < T.length(); i++)
        {
            if (map.find(T[i]) != map.end())
            {
                map[T[i]]++;
            }
            else
            {
                temp += T[i]; 
            }
        }
        
        for (int i = 0; i < S.length(); i++)
        {
           while (map[S[i]]--)
           {
               ret += S[i];
           }
        }
        
        return ret+temp;
    }
};