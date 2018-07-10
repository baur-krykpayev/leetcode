/* 
 * Problem: 383. Ransom Note [easy]
 * Source : https://leetcode.com/problems/ransom-note/description/
 * Solver : Baur Krykpayev
 * Date   : 07/09/2018
 */
 
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        unordered_map<char, int> hash;
        
        for (char c : magazine){hash[c]++;}
        
        for (char c : ransomNote)
        {
            if (hash.find(c) == hash.end() || !hash[c])
            {
                return false;
            }
            
            hash[c]--;
        }
        
        return true;
    }
};