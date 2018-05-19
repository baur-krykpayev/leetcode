/* 
 * Problem: 409. Longest Palindrome [easy]
 * Source : https://leetcode.com/problems/longest-palindrome/description/
 * Solver : Baur Krykpayev
 * Date   : 5/19/2018
 */

class Solution {
public:
    int longestPalindrome(string s) 
    {
        int map[58] = {0};
        int cnt = 0;
        for (char c : s){map[c - 'A']++;}
        for (int n : map){cnt += (n%2) ? (n-1) : n;}
        return cnt+1 > s.length() ? cnt : cnt+1;   
    }
};