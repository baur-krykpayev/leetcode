/* 
 * Problem: 266. Palindrome Permutation [easy]
 * Source : https://leetcode.com/problems/palindrome-permutation/description/
 * Solver : Baur Krykpayev
 * Date   : 5/16/2018
 */

class Solution {
public:
    bool canPermutePalindrome(string s) 
    {
        int map[256] = {0};
        bool first = false;
        
        for (char c : s) {map[(int)c]++;}
        
        for(int i : map)
        {
            if (i%2)
            {
                if (first){return false;}
                else{first = true;}
            }
        }
        
        return true;
    }
};