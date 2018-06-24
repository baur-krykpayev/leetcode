/* 
 * Problem: 340. Longest Substring with At Most K Distinct Characters [hard]
 * Source : https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/
 * Solver : Baur Krykpayev
 * Date   : 06/24/2018
 */
 
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) 
    {
        unordered_map<char, int> hash;
        
        int start = 0, end = 0, ret = 0;
        
        while (end < s.length())
        {
            hash[s[end]]++;
            
            while (hash.size() > k)
            {
                int temp = s[start];
                hash[temp]--;
                if (!hash[temp])
                {
                    hash.erase(temp);
                }
                start++;
            }
            
            ret = max(ret, end-start+1);
            end++;
        }
        
        return ret;
    }
};