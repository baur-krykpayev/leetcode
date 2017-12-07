/* 
 * Problem: 3. Longest Substring Without Repeating Characters[medium]
 * Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 * Solver : Baur Krykpayev
 * Date   : 12/07/2017
 */
 
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        set<char> hash;
        int start = 0;
        int count = 0;
        int ret = INT_MIN;
        
        for (int i = 0; i< s.length(); i++)
        {
            count++;
            
            while (hash.find(s.at(i)) != hash.end())    
            {
                hash.erase(s.at(start++));
                count--;
            }
                       
            ret = (count > ret) ? count : ret;
            hash.insert(s.at(i));          
        }
        
        return (ret == INT_MIN) ? 0 : ret;
    }
};