/* 
 * Problem: 796. Rotate String [easy]
 * Source : https://leetcode.com/problems/rotate-string/description/
 * Solver : Baur Krykpayev
 * Date   : 07/05/2018
 */
 
class Solution {
public:
    bool rotateString(string A, string B) 
    {
        if (A.length() != B.length()) {return false;}
        A += A;
        
        for (int i = 0; i < A.length() - B.length()+1; i++)
        {
            if (A.substr(i, B.length()) == B){return true;}
        }
            
        return false;
    }
};