/* 
 * Problem: 686. Repeated String Match [easy]
 * Source : https://leetcode.com/problems/repeated-string-match/description/
 * Solver : Baur Krykpayev
 * Date   : 5/27/2018
 */

class Solution {
public:
    int repeatedStringMatch(string A, string B) 
    {
        int i = 1; string S = A;
        
        while (S.length() < B.length())
        {
            S += A; i++;
        }
        
        if (S.find(B) != -1) {return i;}
        S += A; i++;
        if (S.find(B) != -1) {return i;}
        
        return -1;
    }
};