/* 
 * Problem: 389. Find the Difference [easy]
 * Source : https://leetcode.com/problems/find-the-difference/description/
 * Solver : Baur Krykpayev
 * Date   : 5/14/2018
 */

class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        unordered_map<char, int> map;
        for (char c : s){map[c]++;}

        for (char c : t)
        {
            if (map[c] > 0)
            {
                map[c]--;
            }
            else
            {
                return c;
            }
        }
        
        return 'F';
    }
};